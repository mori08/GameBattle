#include "Player.h"
#include "GameCamera.h"
#include "SkillManager.h"
#include "TestSkill.h"
#include "InputManager.h"


using namespace GameData;


GameObject::Player::Player(int id)
{
	_id        = id;
	_time      = 0;
	_state     = State::NORMAL;
	_direction = RIGHT;
	_moveSpeed = DEFAULT_MOVE_SPEED;

	_pos         = Point(100, 100);
	_velocity    = Point::Zero;
	_size        = Point(40, 60);
	_tagData     = makeTagData(L"Player[" + ToString(id) + L"]");
	_muteki      = false;
	_textureId   = 0;
	_damageTime  = 0;

	for (auto & n : _skillNum)
	{
		n = 0;
	}

	for (auto & skill : _skillList)
	{
		skill = nullptr;
	}
}


void GameObject::Player::update()
{
	_col = false;

	if (isLanding())
	{
		_velocity.x = 0;
	}

	if (_damageTime > 0)
	{
		--_damageTime;

		if (_damageTime == 0) _muteki = false;
	}

	++_time;

	switch(_state)
	{
	case State::NORMAL:
		normal();
		break;

	case State::USING_SKILL:
		useSkill();
		break;

	case State::GET_SKILL:
		getSkill();
		break;
	}

	setPlayerBoard();

	_velocity.y += _disabledGravity ? 0 : GRAVITY;
	_disabledGravity = false;

	moveObject(true);

	GameCamera::Instance().setPlayerPos(_pos.asPoint());
}


void GameObject::Player::draw() const
{
	switch (_state)
	{
	case State::NORMAL:
		drawPlayer();
		break;

	case State::USING_SKILL:
		drawPlayer();
		_skillList[_sId]->draw(_time, *this);
		break;

	case State::GET_SKILL:
		drawSkillWall();
		break;
	}
}


bool GameObject::Player::eraser() const
{
	return false;
}


void GameObject::Player::collisionCheck(const std::unique_ptr<GameObject>& obj)
{
	static TagData getSkillTag = makeTagData(L"GetSkill[]");

	if (getCollider().intersects(obj->getCollider()))
	{
		obj->collisionUpdate(_tagData);

		if (_state == State::GET_SKILL)
		{
			obj->collisionUpdate(getSkillTag);
		}
	}
	
	if (_state == State::USING_SKILL)
	{
		obj->collisionUpdate(_skillList[_sId]->collision(_time, *this, obj->getCollider()));
	}
}


void GameObject::Player::collisionUpdate(const TagData & tagData)
{
	for(const auto & t : tagData)
	{
		if (t.type == L"Attack" && _id != ParseOr<int>(t.info[0], -1))
		{
			if (_muteki) break;
			
			_damageTime = 120;
			_muteki     = true;

			int anotherId = ParseOr<int>(t.info[0], -1);

			if (anotherId < 0 || anotherId >= _playerBoardList.size()) break;

			_playerBoardList[_id].addScore(-1);
			
			_playerBoardList[anotherId].addScore(3);
		}

		if (t.type == L"Cassette" && _state == State::GET_SKILL)
		{
			_skillList[_sId] = SkillManager::instance().getSkill(t.info[0]);
		}
	}
}


void GameObject::Player::changeState(const State & state)
{
	if (_state == state) return;

	_time = 0;
	_state = state;
}


void GameObject::Player::controllMove()
{
	_velocity.x = 0;

	if ( InputManager::get(_id, Button::Left, InputType::Pressed) && !InputManager::get(_id, Button::Right, InputType::Pressed))
	{
		_velocity.x = LEFT*_moveSpeed;
		_direction = LEFT;
	}
	if (!InputManager::get(_id, Button::Left, InputType::Pressed) &&  InputManager::get(_id, Button::Right, InputType::Pressed))
	{
		_velocity.x = RIGHT*_moveSpeed;
		_direction = RIGHT;
	}

	if (InputManager::get(_id, Button::Up, InputType::Clicked) && isLanding()) { _velocity.y = -12; }
}


void GameObject::Player::normal()
{
	static const int WALK_SPEED = 10;

	controllMove();

	if (!isLanding())
	{
		setTextureId(JAMP);
	}
	else if (Abs(_velocity.x) < 0.1f)
	{
		setTextureId(STAND);
	}
	else
	{
		setTextureId(WALK_0 + (_time % (4 * WALK_SPEED)) / WALK_SPEED);
	}

	for (int i = 0; i < 4; ++i)
	{
		if (InputManager::get(_id, i, InputType::Clicked))
		{
			if (_skillList[i] == nullptr)
			{
				_sId = i;

				changeState(State::GET_SKILL);

				return;
			}
			else
			{
				_sId = i;

				changeState(State::USING_SKILL);

				return;
			}
		}
	}
}


void GameObject::Player::useSkill()
{
	if (_skillList[_sId]->finish(_time))
	{
		if (--_skillNum[_sId] == 0)
		{
			_skillList[_sId] = nullptr;
		}

		changeState(State::NORMAL);

		return;
	}

	_skillList[_sId]->update(_time, *this, _generator);
}



void GameObject::Player::getSkill()
{
	controllMove();

	if (_skillList[_sId] == nullptr)
	{
		changeState(State::NORMAL);

		normal();

		return;
	}

	if (_time == 145) 
	{
		changeState(State::NORMAL);

		_skillNum[_sId] = 5;
	}
}


void GameObject::Player::drawPlayer() const
{
	static const Size SIZE = Size(128, 160);
	const Point pos = Point(_textureId % 4, _textureId / 4);
	const double scl = 0.45;
	const double alpha = (_damageTime % 20 < 10) ? 1.0 : 0.5;

	(
		_direction == RIGHT ?
		TextureAsset(L"player_" + ToString(_id))(pos*SIZE, SIZE) : TextureAsset(L"player_" + ToString(_id))(pos*SIZE, SIZE).mirror()
	).scale(scl).drawAt(_pos.asPoint() + Point(0, -5), AlphaF(alpha));

}


void GameObject::Player::drawSkillWall() const
{
	Point p = _pos.asPoint();

	if (false)
	{
		if (_time < 15)
		{
			int t = _time;
			drawPlayer();
			Rect(p - Point(t * 8, t * 6), t * 16, t * 12).draw(Color(0, 0, 255, 128));
		}
		else if (_time < 45)
		{
			drawPlayer();
			Rect(p - Point(15 * 8, 15 * 6), 15 * 16, 15 * 12).draw(Color(0, 0, 255, 128));
		}
		else if (_time < 105)
		{
			int t = 285 - _time;
			drawPlayer();
			Rect(p - Point(t / 2, t * 3 / 8), t, t * 3 / 4).draw(Color(0, 0, 255, 128));
		}
		else if (_time < 145)
		{
			int t = 285 - _time;
			int a = 128 - 2 * (_time - 105);
			Rect(p - Point(t / 2, t * 3 / 8), t, t * 3 / 4).draw(Color(0, 0, 255, a));
			drawPlayer();
		}
	}

	if (_skillList[_sId] == nullptr)
	{
		drawPlayer();
		return;
	}
	if (_time < 15)
	{
		int t = _time;
		drawPlayer();
		TextureAsset(_skillList[_sId]->getTextureName()).scale(t / 15.0).drawAt(_pos, Alpha(200));
	}
	else if (_time < 45)
	{
		drawPlayer();
		TextureAsset(_skillList[_sId]->getTextureName()).drawAt(_pos, Alpha(200));
	}
	else if (_time < 105)
	{
		int t = _time - 45;
		drawPlayer();
		TextureAsset(_skillList[_sId]->getTextureName()).scale(1 - t / 240.0).drawAt(_pos, Alpha(200));
	}
	else if (_time < 145)
	{
		int t = _time - 45;
		int a = 200 - 2 * (_time - 105);
		TextureAsset(_skillList[_sId]->getTextureName()).scale(1 - t / 240.0).drawAt(_pos, Alpha(a));
		drawPlayer();
	}
}


void GameObject::Player::setPlayerBoard()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_skillList[i] == nullptr)
		{
			_playerBoardList[_id].setSkillData(i, L"", 0);
		}
		else
		{
			_playerBoardList[_id].setSkillData(i, _skillList[i]->getSkillName(), _skillNum[i]);
		}
	}
}
