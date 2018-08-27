#include "GameObject.h"
#include "StageData.h"


using namespace GameData;


std::shared_ptr<GameData::Generator> GameObject::GameObject::_generator;


void GameObject::GameObject::collisionCheck(const std::unique_ptr<GameObject>& obj)
{
	if (getCollider().intersects(obj->getCollider()))
	{
		obj->collisionUpdate(_tagData);
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

		while (StageData::Instance().get(getCollider()) == StageData::BLOCK)
		{
			_velocity.x = 0;
			_pos.x -= unit;
		}
	}

	_isLanding = false;

	if (Abs(_velocity.y) < 0.01) { return; }

	double unit = _velocity.y / Abs(_velocity.y);

	if (_velocity.y < 0 || StageData::Instance().get(getCollider()) == StageData::HARF_BLOCK)
	{
		_pos.y += _velocity.y;

		while (StageData::Instance().get(getCollider()) == StageData::BLOCK)
		{
			_velocity.y = 0;
			_pos.y -= unit;
		}

		return;
	}

	_pos.y += _velocity.y;

	while (StageData::Instance().get(getCollider()) != StageData::EMPTY)
	{
		_velocity.y = 0;
		_pos.y -= unit;
	}
}


bool GameObject::GameObject::isLanding() const
{
	Rect rect = getCollider();
	rect.y++;

	if (StageData::Instance().get(rect) == StageData::BLOCK)
	{
		return true;
	}

	if (StageData::Instance().get(getCollider()) == StageData::EMPTY
		&& StageData::Instance().get(rect) == StageData::HARF_BLOCK)
	{
		return true;
	}

	return false;
}


bool GameObject::GameObject::isTouchingMap() const
{
	if (isLanding()) { return true; }

	Rect rect = getCollider();
	
	if (StageData::Instance().get(rect.movedBy(Point(+1, 0))) == StageData::BLOCK) { return true; }
	if (StageData::Instance().get(rect.movedBy(Point(-1, 0))) == StageData::BLOCK) { return true; }
	if (StageData::Instance().get(rect.movedBy(Point(0, -1))) == StageData::BLOCK) { return true; }

	return false;
}


TagData GameObject::GameObject::makeTagData(const String & tagsStr)
{
	if (tagsStr == L"")
	{
		return move(TagData());
	}
	
	TagData tagData;

	for (const auto & tagStr : tagsStr.split(L']'))
	{
		Tag tag;

		if (tagStr.split(L'[').size() < 2) { continue; }

		tag.type = tagStr.split(L'[')[0];
		tag.info = tagStr.split(L'[')[1].split(L',');

		tagData.emplace_back(tag);
	}

	return move(tagData);
}
