#include "TestSkill.h"
#include "TestObject.h"


void Skill::TestSkill1::update(int, const GameObject::Player &, const std::shared_ptr<GameData::Generator>&)
{
	// とくに何もしなくていいかな
}


String Skill::TestSkill1::collision(int, const GameObject::Player & player, const Rect & collider)
{
	if (Circle(player.getPos() + player.getDirection()*Vec2(60, 0), 30).intersects(collider))
	{
		return L"Attack[" + ToString(player.getId()) + L"]";
	}

	return L"";
}


void Skill::TestSkill1::draw(int, const GameObject::Player & player) const
{
	Circle(player.getPos() + player.getDirection()*Vec2(60, 0), 30).draw(Palette::Yellow);
}


bool Skill::TestSkill1::finish(int time) const
{
	return time > 10;
}




void Skill::TestSkill2::update(int time, const GameObject::Player & player, const std::shared_ptr<GameData::Generator>& generator)
{
	if (time == 3)
	{
		Vec2 pos = player.getPos();

		Vec2 vel = Vec2(player.getDirection() * 8, -8);

		generator->push(std::make_unique<GameObject::TestObject>(pos, vel, player.getId()));
	}
}


String Skill::TestSkill2::collision(int, const GameObject::Player &, const Rect &)
{
	return L"";
}

void Skill::TestSkill2::draw(int, const GameObject::Player &) const
{
	// オブジェクトを生成するのでパスで
}


bool Skill::TestSkill2::finish(int time) const
{
	return time > 6;
}




void Skill::TestSkill3::update(int time, const GameObject::Player & player, const std::shared_ptr<GameData::Generator>& generator)
{
	if (time % 10 == 0)
	{
		Vec2 pos = player.getPos();

		Vec2 vel = Vec2(player.getDirection() * Random(4, 10), -Random(4, 10));

		generator->push(std::make_unique<GameObject::TestObject2>(pos, vel, player.getId()));
	}
}


String Skill::TestSkill3::collision(int, const GameObject::Player &, const Rect &)
{
	return String();
}


void Skill::TestSkill3::draw(int, const GameObject::Player &) const
{
}


bool Skill::TestSkill3::finish(int time) const
{
	return time > 120;
}




void Skill::TestSkill4::update(int time, const GameObject::Player & player, const std::shared_ptr<GameData::Generator>& generator)
{
	if (time == 3)
	{
		Vec2 pos = player.getPos();

		Vec2 vel = Vec2(player.getDirection() * 6, 0);

		generator->push(std::make_unique<GameObject::TestObject2>(pos, vel, player.getId()));
	}
}


String Skill::TestSkill4::collision(int, const GameObject::Player &, const Rect &)
{
	return L"";
}


void Skill::TestSkill4::draw(int, const GameObject::Player &) const
{
}


bool Skill::TestSkill4::finish(int time) const
{
	return time > 6;
}
