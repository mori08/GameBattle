#include "AppleBattle.h"
# include "Apple.h"

void Skill::AppleBattle::update(int time, GameObject::Player & player, const std::shared_ptr<GameData::Generator>& generator)
{
	if (time == STARTTIME)
	{
		const Vec2 pos = player.getPos();

		const Vec2 vel = Vec2(player.getDirection() * 8, 0);

		generator->push(std::make_unique<GameObject::Apple>(pos, vel, player.getId()));

		const int ATTACK = 10;

		player.setTextureId(ATTACK);
	}

}


GameData::TagData& Skill::AppleBattle::collision(int, const GameObject::Player & , const Rect & )
{
	return NoneTag;
}


void Skill::AppleBattle::draw(int, const GameObject::Player & player) const
{
}


bool Skill::AppleBattle::finish(int time) const
{
	return time > ENDTIME;
}

