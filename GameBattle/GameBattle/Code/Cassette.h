#pragma once


#include"GameObject.h"


namespace GameObject
{

	class Cassette : public GameObject::GameObject
	{
	private:

		String _skillKey;

	public:

		void update() override;

		void draw() const override;

		bool eraser() const override;

		void collisionUpdate(const String & tag) override;

	};

}