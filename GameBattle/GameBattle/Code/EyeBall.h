#pragma once

#include "GameObject.h"

namespace GameObject
{
	class EyeBall : public GameObject
	{
	private:

		int _time;

		int _id;

		bool _bombed = false;
		Size _texSize;

		const int ANIMENDTIME = 6 * 6;
		const int ENDTIME = 50;

	public:

		EyeBall(const Vec2 & pos, const Vec2 & vel,int id);

		void update() override;

		void draw() const override;

		bool eraser() const override;

	private:

		void collisionUpdate(const GameData::TagData & tagData) override;

		void generateSmallEyeBalls();

	};
}
