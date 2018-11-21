#pragma once


#include"Main.h"


namespace Scene
{
	class GameScene : public MyApp::Scene
	{
	private:

		int _time;

		GameData::GameObjectManager _gameObjectManager;

	public:

		GameScene();

		void init()override;

		void update()override;

		void draw()const override;

	};
}