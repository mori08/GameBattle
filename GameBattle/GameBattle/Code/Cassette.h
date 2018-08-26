#pragma once


#include"GameObject.h"


namespace GameObject
{

	class Cassette : public GameObject
	{
	private:

		String _skillKey;

		bool   _eraseFlag;

	public:

		Cassette(const Vec2 & pos);

		void update() override;

		void draw() const override;

		bool eraser() const override;

		void collisionUpdate(const String & tag) override;

	};

}