#include "MaterialDefence.h"
#include "Bomber.h"
#include "GameCamera.h"
# include "StageData.h"

void Skill::MaterialDefence::update(int time, GameObject::Player & player, const std::shared_ptr<GameData::Generator>& generator)
{
	if (time == 3)
	{
		const Size stageSize = GameData::StageData::Instance().getSize();
		const bool playerIsLeft = player.getPos().x < stageSize.x / 2;

		const Vec2 pos = Point((playerIsLeft) ? 0 : GameData::StageData::Instance().getSize().x, 50);
		const Vec2 vel = Vec2(playerIsLeft ? 8 : -8, 0);
		generator->push(std::make_unique<GameObject::Bomber>(pos, vel, player.getId()));
	}
}


GameData::TagData& Skill::MaterialDefence::collision(int, const GameObject::Player &, const Rect &)
{
	return NoneTag;
}


void Skill::MaterialDefence::draw(int, const GameObject::Player & player) const
{

}


bool Skill::MaterialDefence::finish(int time) const
{
	return time > 40;
}
