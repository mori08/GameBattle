#include "Moglie.h"

void Skill::Moglie::update(int, GameObject::Player &, const std::shared_ptr<GameData::Generator>&)
{

}


GameData::TagData& Skill::Moglie::collision(int, const GameObject::Player & player, const Rect & collider)
{
	const RectF rect = RectF(50, 50).setCenter(player.getPos()).movedBy(player.getDirection()*Vec2(70, 0));

	if (rect.intersects(collider))
	{
		return AttackTag[player.getId()];
	}

	return NoneTag;
}


void Skill::Moglie::draw(int, const GameObject::Player & player) const
{
	const RectF rect = RectF(50, 50).setCenter(player.getPos()).movedBy(player.getDirection()*Vec2(70, 0));
	rect.draw(Palette::Yellow);
}


bool Skill::Moglie::finish(int time) const
{
	return time > 40;
}

