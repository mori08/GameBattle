#include "CrashBreak.h"

void Skill::CrashBreak::update(int time, GameObject::Player & player, const std::shared_ptr<GameData::Generator>& generator)
{
	if (time == 50)
	{
	
	}
}


GameData::TagData& Skill::CrashBreak::collision(int time, const GameObject::Player & player, const Rect &collider)
{
	if (time < 50) { return NoneTag; }

	if (player.getCollider().intersects(collider))
	{
		return AttackTag[player.getId()];
	}

	return NoneTag;
}


void Skill::CrashBreak::draw(int, const GameObject::Player & player) const
{
	player.getCollider().draw(Palette::Yellow);
}


bool Skill::CrashBreak::finish(int time) const
{
	return time > 100;
}

