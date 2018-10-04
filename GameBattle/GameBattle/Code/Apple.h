#pragma once

#include "GameObject.h"

namespace GameObject
{
	class Apple : public GameObject
	{
	private:

		int _time;

		int _id;

	public:

		Apple(const Vec2 & pos, const Vec2 & vel, int id);

		void update() override;

		void draw() const override;

		bool eraser() const override;

	private:

		void collisionUpdate(const GameData::TagData & tagData) override;

	};
}