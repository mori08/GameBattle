#pragma once


#include"Main.h"
#include"GameObjectManager.h"


namespace Scene
{
	class GameScene : public MyApp::Scene
	{
	private:

		GameData::GameObjectManager _gameObjectManager;

	public:

		GameScene();

		void update()override;

		void draw()const override;

	};
}