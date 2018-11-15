#include "CrashBreak.h"

void Skill::CrashBreak::update(int time, GameObject::Player & player, const std::shared_ptr<GameData::Generator>&)
{
	if (InRange(time,STARTTIME,ENDTIME))
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
	if (time < STARTTIME) { return NoneTag; }

	const RectF rect = RectF(TextureAsset(L"crash").size).setCenter(player.getPos());
	if (rect.intersects(collider))
	{
		return AttackTag[player.getId()];
	}

	return NoneTag;
}


void Skill::CrashBreak::draw(int time, const GameObject::Player & player) const
{
	if (InRange(time, STARTTIME, ENDTIME))
	{
		if (player.getDirection() == 1)
		{
			TextureAsset(Format(L"crash", player.getId() + 1)).drawAt(player.getPos());// .drawFrame(1, 0, Palette::Yellow);
		}

		else
		{
			TextureAsset(Format(L"crash", player.getId() + 1)).mirror().drawAt(player.getPos());//.drawFrame(1, 0, Palette::Yellow);
		}
	}
}


bool Skill::CrashBreak::finish(int time) const
{
	return time > ENDTIME;
}

