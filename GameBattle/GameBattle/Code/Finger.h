#pragma once


#include"AttackObject.h"



namespace GameObject
{

	class Finger : public AttackObject
	{
	public:

		Finger(const Vec2 & pos, const Vec2 & velocity, int id)
			: AttackObject(pos, velocity, id)
		{
			_size = Point(40, 60);
			_endTime = 600;
		}

		void update() override;

		void draw() const override;

	};

}