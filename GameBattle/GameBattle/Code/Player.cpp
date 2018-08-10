#include "Player.h"
#include "GameCamera.h"


GameObject::Player::Player(int id)
{
	_id = id;

	_pos = Point(100, 100);
	_velocity = Point::Zero;
	_size = Point(40, 60);
	_tag = L"Player[" + ToString(id) + L"]";
}


void GameObject::Player::update()
{
	if (Abs(Gamepad(_id).x) > 0.1)
	{
		_velocity.x = 4 * Gamepad(_id).x;
	}
	else
	{
		_velocity.x = 0;
	}

	_velocity.y += 0.6;
	if (Gamepad(_id).button(2).clicked) { _velocity.y = -12; }

	moveObject(true);

	GameData::GameCamera::Instance().setPlayerPos(_pos.asPoint());
}


void GameObject::Player::draw() const
{
	getCollider().draw(Palette::Orange);
}


bool GameObject::Player::eraser() const
{
	return false;
}


void GameObject::Player::collisionUpdate(const String &)
{
}
