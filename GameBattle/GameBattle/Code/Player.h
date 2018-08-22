#pragma once


#include"GameObject.h"


namespace GameObject
{

	class Player : public GameObject
	{
	private:

		int _id; // ¯•Ê”Ô†

		bool _col;

	public:

		Player(int id);

		void update() override;

		void draw() const override;

		bool eraser() const override;

	private:

		void collisionUpdate(const String & tag) override;

	};

}