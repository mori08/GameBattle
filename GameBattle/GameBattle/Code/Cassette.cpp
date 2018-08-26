#include "Cassette.h"
#include "SkillManager.h"


GameObject::Cassette::Cassette(const Vec2 & pos)
{
	_skillKey  = GameData::SkillManager::instance().getKeyRamdom();
	_eraseFlag = false;

	_pos      = pos;
	_size     = Size(30, 30);
	_velocity = Vec2(0, -10);
	_tag      = L"Cassette[" + _skillKey + L"]";	
}


void GameObject::Cassette::update()
{
	_velocity.y += 0.02;

	moveObject(true);
}


void GameObject::Cassette::draw() const
{
	getCollider().draw(Palette::Aqua);
}


bool GameObject::Cassette::eraser() const
{
	return _eraseFlag;
}


void GameObject::Cassette::collisionUpdate(const String & tag)
{
	for(const auto & t : makeTagData(tag))
	{
		if (t.type == L"GetSkill")
		{
			_eraseFlag = true;
		}
	}
}
