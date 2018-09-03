#include "AttackObject.h"


bool GameObject::AttackObject::eraser() const
{
	return _eraseFlag;
}


void GameObject::AttackObject::collisionUpdate(const GameData::TagData & tagData)
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


void GameObject::AttackObject::shooting(double gravity)
{
	++_time;

	if (_time == 120) { _eraseFlag = true; }

	_velocity.y += gravity;

	moveObject(true);

	if (isTouchingMap()) { _eraseFlag = true; }
}


void GameObject::AttackObject::walking()
{
	++_time;

	if (_time == 120) { _eraseFlag = true; }

	_velocity.y += 0.2;

	moveObject(true);

	if (isTouchingWall())
	{
		_velocity.x = -_velocity.x;
	}
}
