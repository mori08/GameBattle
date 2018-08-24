#include "TestSkill.h"


void Skill::TestSkill1::update(int, const GameObject::Player &, const std::shared_ptr<GameData::Generator>&)
{
	// ‚Æ‚­‚É‰½‚à‚µ‚È‚­‚Ä‚¢‚¢‚©‚È
}


String Skill::TestSkill1::collision(int, const GameObject::Player & player, const Rect & collider)
{
	if (Circle(player.getPos(), 30).intersects(collider))
	{
		return L"Attack[" + ToString(player.getId()) + L"]";
	}

	return L"";
}


void Skill::TestSkill1::draw(int, const GameObject::Player & player) const
{
	Circle(player.getPos(), 30).draw(Palette::Lime);
}


bool Skill::TestSkill1::finish(int time) const
{
	return time == 30;
}
