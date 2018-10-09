#pragma once
#include "GameObject.h"

namespace GameObject
{
	class Bomber : public GameObject
	{
	private:

		int _time;

		int _id;

	public:

		Bomber(const Vec2 & pos, const Vec2 & vel, int id);

		void update() override;

		void draw() const override;

		bool eraser() const override;

	private:

		void collisionUpdate(const GameData::TagData & tagData) override;

	};

	
}