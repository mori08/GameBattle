#include "Cassette.h"
#include "SkillManager.h"


GameObject::Cassette::Cassette()
{
	_skillKey = GameData::SkillManager::instance().getKeyRamdom();

	_tag = L"Cassette[" + _skillKey + L"]";
}


void GameObject::Cassette::update()
{
	
}


void GameObject::Cassette::draw() const
{

}


bool GameObject::Cassette::eraser() const
{
	return false;
}


void GameObject::Cassette::collisionUpdate(const String & tag)
{
	
}
