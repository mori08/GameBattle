#pragma once


#include"AttackObject.h"


namespace GameObject
{

	class Panicn : public AttackObject
	{
	private:

		String _colorId;
		double _geta;

	public:

		Panicn(const Vec2 & pos, double speed, int id)
			: AttackObject(pos, Vec2(speed, 0), id)
		{
			_size = Size(30, 30);
			_endTime = 1200;

			_geta = Random(0.0, 2 * Pi);

			_colorId = RandomSelect<String>(
			{
				L"black_panicn",
				L"red_panicn",
				L"green_panicn",
				L"blue_panicn",
				L"magenta_panicn",
				L"cyan_panicn",
				L"yellow_panicn",
				L"white_panicn"
			});
		}

		void update()override;

		void draw()const override;

	};

}