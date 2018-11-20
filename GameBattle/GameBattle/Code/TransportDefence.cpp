# include "Mine.h"
# include "TransportDefence.h"

void Skill::TransportDefence::update(int time, GameObject::Player & player, const std::shared_ptr<GameData::Generator>& generator)
{
	if (time == STARTTIME)
	{
		const Vec2 vel = Vec2(10, 0)*player.getDirection();
		generator->push(std::make_unique<GameObject::Mine>(player.getPos(), vel, player.getId()));
		player.setTextureId(GameObject::Player::ATTACK);
	}
}


GameData::TagData& Skill::TransportDefence::collision(int time, const GameObject::Player & player, const Rect &collider)
{

	return NoneTag;
}


void Skill::TransportDefence::draw(int time, const GameObject::Player & player) const
{

}


bool Skill::TransportDefence::finish(int time) const
{
	return time > ENDTIME;
}

