#include"GameScene.h"
#include"GameCamera.h"
#include"StageData.h"


Scene::GameScene::GameScene()
{
	_time = 0;
}


void Scene::GameScene::update()
{
	++_time;

	_gameObjectManager.update();

	GameData::GameCamera::Instance().update();
}


void Scene::GameScene::draw() const
{
	{
		const auto t1 = GameData::GameCamera::Instance().createTransformer();

		GameData::StageData::Instance().draw();

		_gameObjectManager.draw();
	}
}
