#include "Jihad1.h"

void Skill::Jihad1::update(int, GameObject::Player &, const std::shared_ptr<GameData::Generator>&)
{
}

GameData::TagData & Skill::Jihad1::collision(int, const GameObject::Player &, const Rect &)
{
	return NoneTag;
}

void Skill::Jihad1::draw(int, const GameObject::Player &) const
{
}

bool Skill::Jihad1::finish(int) const
{
	return false;
}
