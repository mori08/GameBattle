#pragma once


#include"Main.h"


namespace Scene
{
	class ResultScene : public MyApp::Scene
	{
	private:

		Array<int> _rank;

		Array<Color> _colorList;

	public:

		ResultScene();

		void init()override;

		void update()override;

		void draw()const override;

	};
}