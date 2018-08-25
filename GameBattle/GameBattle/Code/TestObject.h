#pragma once


#include "GameObject.h"


namespace GameObject
{

	class TestObject : public GameObject
	{
	private:

		bool _eraseFlag = false;

		int  _id;

	public:

		TestObject(Vec2 pos, Vec2 vel, int id);

		void update() override;

		void draw() const override;

		bool eraser() const override;

	private:

		void collisionUpdate(const String & tag) override;

	};

}