#include "Jihad1.h"
#include "Finger.h"

void Skill::Jihad1::update(int time, GameObject::Player & player, const std::shared_ptr<GameData::Generator>& generator)
{
	if (time == 5)
	{
		Vec2 pos = player.getPos();

		Vec2 vel = Vec2(player.getDirection(), 0);

		generator->push(std::make_unique<GameObject::Finger>(pos, vel, player.getId()));
	}
}

GameData::TagData & Skill::Jihad1::collision(int, const GameObject::Player &, const Rect &)
{
	return NoneTag;
}

void Skill::Jihad1::draw(int, const GameObject::Player &) const
{
}

bool Skill::Jihad1::finish(int time) const
{
	return time > 15;
}
