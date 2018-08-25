#include "TestObject.h"


GameObject::TestObject::TestObject(Vec2 pos, Vec2 vel,int id)
{
	_pos      = pos;
	_velocity = vel;
	_size     = Point(30, 30);
	_tag      = L"Attack[" + ToString(id) + L"]";
	_eraseFlag = false;
	_id        = id;
}

void GameObject::TestObject::update()
{
	_velocity.y += 0.2;

	moveObject(true);

	if (isTouchingMap()) { _eraseFlag = true; }
}


void GameObject::TestObject::draw() const
{
	getCollider().draw(Palette::Yellow);
}


bool GameObject::TestObject::eraser() const
{
	return _eraseFlag;
}


void GameObject::TestObject::collisionUpdate(const String & str)
{
	for (const auto & tag : makeTagData(str))
	{
		if (tag.type == L"Player" && _id != ParseOr<int>(tag.info[0], -1))
		{
			_eraseFlag = true;
		}
		if (tag.type == L"Attack" && _id != ParseOr<int>(tag.info[0], -1))
		{
			_eraseFlag = true;
		}
	}
}
