# include "EyeBall.h"
# include "Jihad2.h"

void Skill::Jihad2::update(int time, GameObject::Player & player, const std::shared_ptr<GameData::Generator>& generator)
{
	if (time == STARTTIME)
	{
		const Vec2 vel = Vec2(10 * player.getDirection(), -10);
		generator->push(std::make_unique<GameObject::EyeBall>(player.getPos(), vel, player.getId()));
	}
}


GameData::TagData& Skill::Jihad2::collision(int , const GameObject::Player & , const Rect &)
{
	return NoneTag;
}


void Skill::Jihad2::draw(int , const GameObject::Player & ) const
{

}


bool Skill::Jihad2::finish(int time) const
{
	return time > ENDTIME;
}

