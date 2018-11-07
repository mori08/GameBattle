#pragma once

#include "GameObject.h"

namespace GameObject
{
	class Mine : public GameObject
	{
	private:

		int _time;

		int _id;

	public:

		Mine(const Vec2 & pos, const Vec2 & vel, int id);

		void update() override;

		void draw() const override;

		bool eraser() const override;

	private:

		void collisionUpdate(const GameData::TagData & tagData) override;

		int getDirection()const
		{
			return _velocity.x >= 0 ? 1 : -1;
		}

	};
}