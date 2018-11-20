#include "Moglie.h"

void Skill::Moglie::update(int time, GameObject::Player & player, const std::shared_ptr<GameData::Generator>&)
{
	animCount++;
	
	if (time < ENDTIME)
	{
		const int NONE = -1;
		player.setTextureId(NONE);
		player.controllMove();
	}
	else
	{
		player.setTextureId(GameObject::Player::STAND);
	}
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

	//animCount‚ªANIMBETWEENˆÈ‰º‚È‚çfalse ‚»‚¤‚Å‚È‚¢‚È‚çtrue
	const bool anim = animCount%ANIMBETWEEN*2 < ANIMBETWEEN;


	if (player.getDirection() == 1)
	{
		TextureAsset(Format(L"moglie", player.getId() + 1))(0, 48 * anim, 96, 48).drawAt(player.getPos().movedBy(20, 5));
	}

	else
	{
		TextureAsset(Format(L"moglie", player.getId() + 1))(0, 48 * anim, 96, 48).mirror().drawAt(player.getPos().movedBy(-20,5));
	}


	//const RectF rect = RectF(50, 50).setCenter(player.getPos()).movedBy(player.getDirection()*Vec2(70, 0));
	//rect.draw(Palette::Yellow);
}


bool Skill::Moglie::finish(int time) const
{
	return time > ENDTIME;
}

