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
