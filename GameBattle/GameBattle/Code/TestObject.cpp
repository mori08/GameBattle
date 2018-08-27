#include "TestObject.h"


GameObject::TestObject::TestObject(Vec2 pos, Vec2 vel,int id)
{
	_pos      = pos;
	_velocity = vel;
	_size     = Point(30, 30);
	_tagData   = makeTagData(L"Attack[" + ToString(id) + L"]");
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


void GameObject::TestObject::collisionUpdate(const GameData::TagData & tagData)
{
	for (const auto & tag : tagData)
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




GameObject::TestObject2::TestObject2(Vec2 pos, Vec2 vel, int id)
{
	_pos      = pos;
	_velocity = vel;
	_size     = Point(30, 30);
	_tagData  = makeTagData(L"Attack[" + ToString(id) + L"]");
	_time     = 0;
	_id       = id;
}


void GameObject::TestObject2::update()
{
	_velocity.y += 0.2;

	_time++;

	moveObject(true);
}

void GameObject::TestObject2::draw() const
{
	getCollider().draw(Palette::Yellow);
}

bool GameObject::TestObject2::eraser() const
{
	return _time >= 300;
}

void GameObject::TestObject2::collisionUpdate(const GameData::TagData & tagData)
{
	for (const auto & tag : tagData)
	{
		if (tag.type == L"Player" && _id != ParseOr<int>(tag.info[0], -1))
		{
			_time = 600;
		}
		if (tag.type == L"Attack" && _id != ParseOr<int>(tag.info[0], -1))
		{
			_time = 600;
		}
	}
}
