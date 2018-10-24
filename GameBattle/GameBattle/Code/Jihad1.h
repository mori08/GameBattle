#pragma once


#include"Player.h"


namespace Skill
{

	class Jihad1 : public Skill
	{
	public:

		void update(int, GameObject::Player &, const std::shared_ptr<GameData::Generator> &) override;

		GameData::TagData & collision(int, const GameObject::Player & player, const Rect & collider) override;

		void draw(int time, const GameObject::Player & player) const override;

		bool finish(int time)const override;

	};

}