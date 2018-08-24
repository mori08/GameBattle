#include "GameObject.h"
#include "StageData.h"


std::shared_ptr<GameData::Generator> GameObject::GameObject::_generator;


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

	_isLanding = false;

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


bool GameObject::GameObject::isLanding() const
{
	Rect rect = getCollider();
	rect.y++;

	if (GameData::StageData::Instance().get(rect) == GameData::StageData::BLOCK)
	{
		return true;
	}

	if (GameData::StageData::Instance().get(getCollider()) == GameData::StageData::EMPTY
		&& GameData::StageData::Instance().get(rect) == GameData::StageData::HARF_BLOCK)
	{
		return true;
	}

	return false;
}



GameObject::GameObject::TagData GameObject::GameObject::makeTagData(const String & tagsStr)
{
	if (tagsStr == L"")
	{
		return move(TagData());
	}

	TagData tagData;

	for (const auto & tagStr : tagsStr.split(L']'))
	{
		GameData::Tag tag;

		if (tagStr.split(L'[').size() < 2) { continue; }

		tag.type = tagStr.split(L'[')[0];
		tag.info = tagStr.split(L'[')[1].split(L',');

		tagData.emplace_back(tag);
	}

	return move(tagData);
}
