#pragma once

#include "GameObject.h"
# include "Explosion.h"

namespace GameObject
{
	class Bullet : public GameObject
	{
	private:

		int _time;

		int _id;

	public:

		Bullet(const Vec2 & pos, const Vec2 & vel, int id);

		void update() override;

		void draw() const override;

		bool eraser() const override;

	private:

		void collisionUpdate(const GameData::TagData & tagData) override;

		void generateExplosion()
		{
			_generator->push(std::make_unique<Explosion>(_pos, Size(0, 0), _id, 2));
		}

	};
}