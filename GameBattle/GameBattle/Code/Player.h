#pragma once


#include"GameObject.h"


namespace GameData
{
	class Skill;
}


namespace GameObject
{

	class Player : public GameObject
	{
	private:

		using skill_ptr = std::shared_ptr<GameData::Skill>;
		using skill_list = std::array<skill_ptr, 4>;

	private:

		int        _id;    // 識別番号

		skill_list _skill; // スキル

		bool _col;

	public:

		Player(int id);

		void update() override;

		void draw() const override;

		bool eraser() const override;

	private:

		void collisionUpdate(const String & tag) override;

	};

}