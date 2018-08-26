#pragma once


#include"Player.h"


namespace Skill
{

	class TestSkill1 : public Skill
	{
	public:

		void update(int, const GameObject::Player &, const std::shared_ptr<GameData::Generator> &) override;

		String collision(int, const GameObject::Player & player, const Rect & collider) override;

		void draw(int time, const GameObject::Player & player) const override;

		bool finish(int time)const override;
	};

	class TestSkill2 : public Skill
	{
	public:

		void update(int time, const GameObject::Player & player, const std::shared_ptr<GameData::Generator> & generator) override;

		String collision(int, const GameObject::Player &, const Rect &) override;

		void draw(int, const GameObject::Player &) const override;

		bool finish(int time)const override;
	};

	class TestSkill3 : public Skill
	{
		void update(int time, const GameObject::Player & player, const std::shared_ptr<GameData::Generator> & generator) override;

		String collision(int, const GameObject::Player &, const Rect &) override;

		void draw(int, const GameObject::Player &) const override;

		bool finish(int time)const override;
	};

	class TestSkill4 : public Skill
	{
		void update(int time, const GameObject::Player & player, const std::shared_ptr<GameData::Generator> & generator) override;

		String collision(int, const GameObject::Player &, const Rect &) override;

		void draw(int, const GameObject::Player &) const override;

		bool finish(int time)const override;
	};

}