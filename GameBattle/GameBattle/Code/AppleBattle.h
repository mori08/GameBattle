#pragma once

#include"Player.h"


namespace Skill
{

	class AppleBattle : public Skill
	{
		const int STARTTIME = 3;
		const int ENDTIME = 40;

	public:

		AppleBattle() :Skill(L"±¯ÌßÙÊÞÄÙ", L"AppleBattle_title") {}

		void update(int, GameObject::Player &, const std::shared_ptr<GameData::Generator> &) override;

		GameData::TagData & collision(int, const GameObject::Player & player, const Rect & collider) override;

		void draw(int time, const GameObject::Player & player) const override;

		bool finish(int time)const override;
	};


}