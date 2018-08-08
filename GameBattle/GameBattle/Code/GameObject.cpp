#include "GameObject.h"
#include "StageData.h"


void GameObject::GameObject::collisionCheck(const std::unique_ptr<GameObject>& obj)
{
	if (getCollider().intersects(obj->getCollider()))
	{
		obj->collisionUpdate(_tag);
	}
}


void GameObject::GameObject::moveObject(bool useMapData)
{
	if (!useMapData)
	{
		_pos += _velocity;

		return;
	}

	_pos.x += _velocity.x;

	if (Abs(_velocity.x) > 0.01)
	{
		double unit = _velocity.x / Abs(_velocity.x);

		while (GameData::StageData::Instance().get(getCollider()) == GameData::StageData::BLOCK)
		{
			_velocity.x = 0;
			_pos.x -= unit;
		}
	}

	if (Abs(_velocity.y) < 0.01) { return; }

	double unit = _velocity.y / Abs(_velocity.y);

	if (_velocity.y < 0 || GameData::StageData::Instance().get(getCollider()) == GameData::StageData::HARF_BLOCK)
	{
		_pos.y += _velocity.y;

		while (GameData::StageData::Instance().get(getCollider()) == GameData::StageData::BLOCK)
		{
			_velocity.y = 0;
			_pos.y -= unit;
		}

		return;
	}

	_pos.y += _velocity.y;

	while (GameData::StageData::Instance().get(getCollider()) != GameData::StageData::EMPTY)
	{
		_velocity.y = 0;
		_pos.y -= unit;
	}
}
