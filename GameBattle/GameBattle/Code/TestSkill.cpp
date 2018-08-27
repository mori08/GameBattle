#include "TestSkill.h"
#include "TestObject.h"


void Skill::TestSkill1::update(int, GameObject::Player &, const std::shared_ptr<GameData::Generator>&)
{
	// とくに何もしなくていいかな
}


GameData::TagData& Skill::TestSkill1::collision(int, const GameObject::Player & player, const Rect & collider)
{
	if (Circle(player.getPos() + player.getDirection()*Vec2(60, 0), 30).intersects(collider))
	{
		return AttackTag[player.getId()];
	}

	return NoneTag;
}


void Skill::TestSkill1::draw(int, const GameObject::Player & player) const
{
	Circle(player.getPos() + player.getDirection()*Vec2(60, 0), 30).draw(Palette::Yellow);
}


bool Skill::TestSkill1::finish(int time) const
{
	return time > 10;
}




void Skill::TestSkill2::update(int time, GameObject::Player & player, const std::shared_ptr<GameData::Generator>& generator)
{
	if (time == 3)
	{
		Vec2 pos = player.getPos();

		Vec2 vel = Vec2(player.getDirection() * 8, -8);

		generator->push(std::make_unique<GameObject::TestObject>(pos, vel, player.getId()));
	}
}


GameData::TagData & Skill::TestSkill2::collision(int, const GameObject::Player &, const Rect &)
{
	return NoneTag;
}

void Skill::TestSkill2::draw(int, const GameObject::Player &) const
{
	// オブジェクトを生成するのでパスで
}


bool Skill::TestSkill2::finish(int time) const
{
	return time > 6;
}




void Skill::TestSkill3::update(int time, GameObject::Player & player, const std::shared_ptr<GameData::Generator>& generator)
{
	player.controllMove();

	if (time % 10 == 0)
	{
		Vec2 pos = player.getPos();

		Vec2 vel = Vec2(Random(-3, 3), -Random(8, 16));

		generator->push(std::make_unique<GameObject::TestObject>(pos, vel, player.getId()));
	}
}


GameData::TagData &  Skill::TestSkill3::collision(int, const GameObject::Player &, const Rect &)
{
	return NoneTag;
}


void Skill::TestSkill3::draw(int, const GameObject::Player &) const
{
}


bool Skill::TestSkill3::finish(int time) const
{
	return time > 120;
}




void Skill::TestSkill4::update(int time, GameObject::Player & player, const std::shared_ptr<GameData::Generator>& generator)
{
	if (time == 3)
	{
		Vec2 pos = player.getPos();

		Vec2 vel = Vec2(player.getDirection() * 6, 0);

		generator->push(std::make_unique<GameObject::TestObject2>(pos, vel, player.getId()));
	}
}


GameData::TagData &  Skill::TestSkill4::collision(int, const GameObject::Player &, const Rect &)
{
	return NoneTag;
}


void Skill::TestSkill4::draw(int, const GameObject::Player &) const
{
}


bool Skill::TestSkill4::finish(int time) const
{
	return time > 6;
}
