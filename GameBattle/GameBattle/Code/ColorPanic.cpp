#include "ColorPanic.h"
#include "Panicn.h"


void Skill::ColorPanic::update(int time, GameObject::Player & player, const std::shared_ptr<GameData::Generator>& generator)
{
	if (time == 20)
	{
		SoundAsset(L"colorpanic").playMulti();
	}

	player.setTextureId(GameObject::Player::ATTACK);

	if(time%20==0)
	{
		Vec2 pos = player.getPos();

		double speed = player.getDirection()*5.0*Random(0.2, 0.6);

		generator->push(std::make_unique<GameObject::Panicn>(pos, speed, player.getId()));
	}
}


GameData::TagData & Skill::ColorPanic::collision(int, const GameObject::Player &, const Rect &)
{
	return NoneTag;
}


void Skill::ColorPanic::draw(int, const GameObject::Player &) const
{

}

bool Skill::ColorPanic::finish(int time) const
{
	return time > 90;
}
