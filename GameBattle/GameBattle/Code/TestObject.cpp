#include "TestObject.h"


GameObject::TestObject::TestObject()
{
	_pos      = Point(100, 100);
	_velocity = Point::Zero;
	_size     = Point(48, 64);
	_tag      = L"Test";
}


void GameObject::TestObject::update()
{
	_velocity.x = 0;
	if (Input::KeyD.pressed) { _velocity.x = +4; }
	if (Input::KeyA.pressed) { _velocity.x = -4; }

	_velocity.y += 0.6;
	if (Input::KeyW.clicked) { _velocity.y = -12; }

	moveObject(true);
}


void GameObject::TestObject::draw() const
{
	getCollider().draw(Palette::Red);
}


bool GameObject::TestObject::eraser() const
{
	return false;
}


void GameObject::TestObject::collisionUpdate(const String &)
{
}
