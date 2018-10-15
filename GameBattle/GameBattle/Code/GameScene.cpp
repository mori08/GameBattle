#include"GameScene.h"
#include"GameCamera.h"
#include"StageData.h"


Scene::GameScene::GameScene()
{
}


void Scene::GameScene::update()
{
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
