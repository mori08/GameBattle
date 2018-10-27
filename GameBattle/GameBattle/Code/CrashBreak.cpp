#include "CrashBreak.h"

void Skill::CrashBreak::update(int time, GameObject::Player & player, const std::shared_ptr<GameData::Generator>&)
{
	if (InRange(time,50,100))
	{
		player.setMuteki(true);

		const Vec2 vec = Vec2(10, 0)*player.getDirection();
		player.setVelocity(vec);
	}

	else
	{
		player.setMuteki(false);
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


void Skill::CrashBreak::draw(int time, const GameObject::Player & player) const
{
	if (InRange(time, 50, 100))
	{
		player.getCollider().draw(Palette::Yellow);
	}
}


bool Skill::CrashBreak::finish(int time) const
{
	return time > 100;
}

