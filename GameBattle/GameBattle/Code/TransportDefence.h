#pragma once

#include"Player.h"


namespace Skill
{
	class TransportDefence : public Skill
	{
		const int STARTTIME = 20;
		const int ENDTIME = 60;

	public:

		TransportDefence() :Skill(L"—A‘—–h‰q", L"TransportDefence_title") {}

		void update(int, GameObject::Player &, const std::shared_ptr<GameData::Generator> &) override;

		GameData::TagData & collision(int, const GameObject::Player & player, const Rect & collider) override;

		void draw(int time, const GameObject::Player & player) const override;

		bool finish(int time)const override;
	};


}
