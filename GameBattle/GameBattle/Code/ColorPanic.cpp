#include "ColorPanic.h"
#include "Panicn.h"


void Skill::ColorPanic::update(int time, GameObject::Player & player, const std::shared_ptr<GameData::Generator>& generator)
{
	player.setTextureId(GameObject::Player::ATTACK);

	if(time%20==0)
	{
		Vec2 pos = player.getPos();

		double speed = player.getDirection()*5.0*Random(0.2, 0.6);

		generator->push(std::make_unique<GameObject::Panicn>(pos, speed, player.getId()));
	}
}


GameData::TagData & Skill::ColorPanic::collision(int, const GameObject::Player & player, const Rect & collider)
{
	return NoneTag;
}


void Skill::ColorPanic::draw(int time, const GameObject::Player & player) const
{

}

bool Skill::ColorPanic::finish(int time) const
{
	return time > 90;
}
