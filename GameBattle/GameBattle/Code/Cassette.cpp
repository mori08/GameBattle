#include "Cassette.h"
#include "SkillManager.h"


void GameObject::Cassette::update()
{
	_skillKey = GameData::SkillManager::instance().getKeyRamdom();
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
