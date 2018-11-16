#pragma once
#include "GameObject.h"

namespace GameObject
{
	class Explosion : public GameObject
	{
	private:

		int _time;

		int _id;

		int _texId;

		bool _collision;

	public:

		Explosion(const Vec2 & pos, const Size& size, int id, int texId);

		void update() override;

		void draw() const override;

		bool eraser() const override;

	private:

		void collisionUpdate(const GameData::TagData & tagData) override;

	};
}