#include "TestSkill.h"
#include "TestObject.h"


void Skill::TestSkill1::update(int, const GameObject::Player &, const std::shared_ptr<GameData::Generator>&)
{
	// とくに何もしなくていいかな
}


String Skill::TestSkill1::collision(int, const GameObject::Player & player, const Rect & collider)
{
	if (Circle(player.getPos() + player.getDirection()*Vec2(30, 0), 30).intersects(collider))
	{
		return L"Attack[" + ToString(player.getId()) + L"]";
	}

	return L"";
}


void Skill::TestSkill1::draw(int, const GameObject::Player & player) const
{
	Circle(player.getPos() + player.getDirection()*Vec2(30, 0), 30).draw(Palette::Lime);
}


bool Skill::TestSkill1::finish(int time) const
{
	return time == 30;
}




void Skill::TestSkill2::update(int time, const GameObject::Player & player, const std::shared_ptr<GameData::Generator>& generator)
{
	if (time == 10)
	{
		Vec2 pos = player.getPos();

		Vec2 vel = player.getDirection() * Vec2(8, 0);

		generator->push(std::make_unique<GameObject::TestObject>(player.getPos(),));
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
	return time > 20;
}
