#pragma once

#include "GameObject.h"

namespace GameObject
{
	class Robot : public GameObject
	{
	private:

		int _time;

		int _id;

		Vec2 _savedVel;

		int _direction;

	public:

		Robot(const Vec2 & pos, const Vec2 & vel, int id);

		void update() override;

		void draw() const override;

		bool eraser() const override;

	private:

		void collisionUpdate(const GameData::TagData & tagData) override;

	};
}