#pragma once

#include "GameObject.h"
# include "Explosion.h"


namespace GameObject
{
	class Bomb : public GameObject
	{
	private:

		int _time;

		int _id;

	public:

		Bomb(const Vec2 & pos, const Vec2 & vel, int id);

		void update() override;

		void draw() const override;

		bool eraser() const override;

	private:

		void collisionUpdate(const GameData::TagData & tagData) override;

		void generateExplosion()
		{
			_generator->push(std::make_unique<Explosion>(_pos, Size(40, 50), _id, 1));
		}

	};
}