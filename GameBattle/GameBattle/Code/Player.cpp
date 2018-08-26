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

	_pos      = Point(100, 100);
	_velocity = Point::Zero;
	_size     = Point(40, 60);
	_tag      = L"Player[" + ToString(id) + L"]";

	for (auto & skill : _skillList)
	{
		skill = nullptr;
	}

	_skillList[0] = std::make_shared<Skill::TestSkill1>();
	_skillList[1] = std::make_shared<Skill::TestSkill2>();
}


void GameObject::Player::update()
{
	_col = false;

	if (isLanding())
	{
		_velocity.x = 0;
	}
	_velocity.y += 0.6;

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

	moveObject(true);

	if (_velocity.x < 0) { _direction = LEFT;  }
	if (_velocity.x > 0) { _direction = RIGHT; }

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
	if (getCollider().intersects(obj->getCollider()))
	{
		obj->collisionUpdate(_tag);
	}

	if (_state != State::USING_SKILL) { return; }
	
	String skillTag = _skillList[_sId]->collision(_time, *this, obj->getCollider());

	if (skillTag == L"") { return; }

	obj->collisionUpdate(skillTag);
}


void GameObject::Player::collisionUpdate(const String & tag)
{
	for(const auto & t : makeTagData(tag))
	{
		if (t.type == L"Attack" && _id != ParseOr<int>(t.info[0], -1))
		{
			_col = true;
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
	}
	if (!InputManager::get(_id, Button::Left, InputType::Pressed) &&  InputManager::get(_id, Button::Right, InputType::Pressed))
	{
		_velocity.x = RIGHT*_moveSpeed;
	}

	if (InputManager::get(_id, Button::Up, InputType::Clicked) && isLanding()) { _velocity.y = -12; }
}


void GameObject::Player::normal()
{
	controllMove();

	for (int i = 0; i < 4; ++i)
	{
		if (InputManager::get(_id, i, InputType::Clicked))
		{
			if (_skillList[i] == nullptr)
			{
				_sId = i;

				changeState(State::GET_SKILL);
			}
			else
			{
				_sId = i;

				changeState(State::USING_SKILL);
			}
		}
	}
}


void GameObject::Player::useSkill()
{
	if (_skillList[_sId]->finish(_time))
	{
		changeState(State::NORMAL);
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
	}
}


void GameObject::Player::drawPlayer() const
{
	getCollider().draw(_col ? Palette::Red : Palette::Orange);
}


void GameObject::Player::drawSkillWall() const
{
	Point p = _pos.asPoint();

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
	else if(_time < 105)
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
