#pragma once


#include"AttackObject.h"



namespace GameObject
{

	class Finger : public AttackObject
	{
	private:



	public:

		void update() override;

		void draw() const override;

	};

}