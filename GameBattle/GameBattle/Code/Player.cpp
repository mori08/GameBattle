#include "Player.h"
#include "GameCamera.h"


GameObject::Player::Player(int id)
{
	_id    = id;
	_time  = 0;
	_state = State::NORMAL;

	_pos      = Point(100, 100);
	_velocity = Point::Zero;
	_size     = Point(40, 60);
	_tag      = L"Player[" + ToString(id) + L"]";

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
	_velocity.y += 0.6;

	++_time;

	switch(_state)
	{
	case State::NORMAL:
		controll();
		break;

	case State::USING_SKILL:
		useSkill();
		break;
	}

	moveObject(true);

	GameData::GameCamera::Instance().setPlayerPos(_pos.asPoint());
}


void GameObject::Player::draw() const
{
	getCollider().draw(_col?Palette::Red : Palette::Orange);

	if (_state == State::USING_SKILL)
	{
		_skillList[_sId]->draw(_time, *this);
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
	
	String skillTag = _skillList[_sId]->collision(obj->getCollider());

	if (skillTag == L"") { return; }

	obj->collisionUpdate(skillTag);
}


void GameObject::Player::collisionUpdate(const String &)
{
	_col = true;
}


void GameObject::Player::changeState(const State & state)
{
	if (_state == state) return;

	_time = 0;
	_state = state;
}


void GameObject::Player::controll()
{
	_velocity.x = 4 * Gamepad(_id).x;

	if (Gamepad(_id).button(2).clicked && isLanding()) { _velocity.y = -12; }

	for (int i = 0; i < 4; ++i)
	{
		if (Gamepad(_id).button(i).clicked)
		{
			_sId = i;

			_state = State::USING_SKILL;
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
