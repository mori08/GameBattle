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
	_velocity.x = 0;
	if (Input::KeyD.pressed) { _velocity.x = +4; }
	if (Input::KeyA.pressed) { _velocity.x = -4; }

	_velocity.y += 0.6;
	if (Input::KeyW.clicked) { _velocity.y = -12; }

	moveObject(true);

	GameData::GameCamera::Instance().setPlayerPos(_pos.asPoint());
	Println(_pos);
}


void GameObject::Player::draw() const
{
	getCollider().draw(Palette::Orange);
	Circle(_pos, 10).draw(Color(250, 0, 0, 100));
	Circle(GameData::GameCamera::Instance().getPos(), 10).draw(Color(0, 0, 250, 100));
}


bool GameObject::Player::eraser() const
{
	return false;
}


void GameObject::Player::collisionUpdate(const String &)
{
}
