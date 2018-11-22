#pragma once

#include"Player.h"


namespace Skill
{

	class Moglie: public Skill
	{
		const int ENDTIME = 80;

		int animCount = 0;

		const int ANIMBETWEEN = 6;

	public:

		Moglie() :Skill(L"ÇŸÇÍÇŸÇÍÉÇÉOÉäÅ[", L"Moglie_title") 
		{
			
		}

		void update(int, GameObject::Player &, const std::shared_ptr<GameData::Generator> &) override;

		GameData::TagData & collision(int, const GameObject::Player & player, const Rect & collider) override;

		void draw(int time, const GameObject::Player & player) const override;

		bool finish(int time)const override;
	};


}