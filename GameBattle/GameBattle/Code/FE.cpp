#include "FE.h"
# include "Robot.h"

void Skill::FE::update(int time, GameObject::Player & player, const std::shared_ptr<GameData::Generator>& _generator)
{
	if (time == STARTTIME)
	{
		const Vec2 pos = player.getPos().movedBy(player.getDirection() * 10, -15);
		const Vec2 vel = Vec2(2* player.getDirection(), 0);
		_generator->push(std::make_unique<GameObject::Robot>(pos,vel,player.getId()));
	}
}


GameData::TagData& Skill::FE::collision(int, const GameObject::Player &, const Rect &)
{
	return NoneTag;
}


void Skill::FE::draw(int time, const GameObject::Player & player) const
{
}


bool Skill::FE::finish(int time) const
{
	return time > ENDTIME;
}

