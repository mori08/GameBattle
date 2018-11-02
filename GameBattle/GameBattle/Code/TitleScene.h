#pragma once

#include"Main.h"


namespace Scene
{
	class TitleScene : public MyApp::Scene
	{
	private:

		Font font;



		void init()override;

		void update()override;

		void draw()const override;
	};
}