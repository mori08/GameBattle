#pragma once


#include"Main.h"
#include"GameObjectManager.h"


namespace Scene
{
	class GameScene : public MyApp::Scene
	{
	private:

		int _time;

		bool _pause;
		bool _stopGame;

		Font font{ 20, L"ü‡ÉSÉVÉbÉN Medium" };

		GameData::GameObjectManager _gameObjectManager;

	public:

		GameScene();

		void init()override;

		void update()override;

		void draw()const override;

	};
}