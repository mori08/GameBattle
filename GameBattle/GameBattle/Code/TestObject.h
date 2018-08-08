#pragma once


#include "GameObject.h"


namespace GameObject
{

	class TestObject : public GameObject
	{
	public:

		TestObject();

		void update() override;

		void draw() const override;

		bool eraser() const override;

	private:

		void collisionUpdate(const String & tag) override;

	};

}