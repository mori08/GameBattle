#pragma once

#include"Player.h"


namespace Skill
{
	class Jihad2 : public Skill
	{
		const int STARTTIME = 20;
		const int ENDTIME = 60;

	public:

		Jihad2() :Skill(L"Ç∂ÇÕÇ†Ç«ÅIÅI", L"Jihad2_title") {}

		void update(int, GameObject::Player &, const std::shared_ptr<GameData::Generator> &) override;

		GameData::TagData & collision(int, const GameObject::Player & player, const Rect & collider) override;

		void draw(int time, const GameObject::Player & player) const override;

		bool finish(int time)const override;
	};


}
