#pragma once


#include"GameObject.h"


namespace GameObject
{

	class Cassette : public GameObject::GameObject
	{
	private:

		String _skillKey;

		bool   _eraseFlag;

	public:

		Cassette();

		void update() override;

		void draw() const override;

		bool eraser() const override;

		void collisionUpdate(const String & tag) override;

	};

}