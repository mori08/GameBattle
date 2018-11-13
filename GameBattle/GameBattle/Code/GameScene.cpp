#include"GameScene.h"
#include"GameCamera.h"
#include"StageData.h"


Scene::GameScene::GameScene()
{
	_time = 0;
}


void Scene::GameScene::init()
{
	if (m_data->_bgm)
	{
		SoundAsset(L"battle_bgm").setLoop(true);
		SoundAsset(L"battle_bgm").play();
	}
}


void Scene::GameScene::update()
{
	++_time;
	Println(_time);
	_gameObjectManager.update();

	GameData::GameCamera::Instance().update();

	if (_time >= 7200 || Input::KeySpace.clicked)
	{
		changeScene(L"ResultScene");

		m_data->_scoreList.clear();

		for (int i = 0; i < 4; ++i)
		{
			m_data->_scoreList.emplace_back(GameObject::GameObject::getPlayerScore(i));
		}
	}
}


void Scene::GameScene::draw() const
{
	{
		const auto t1 = GameData::GameCamera::Instance().createTransformer();

		GameData::StageData::Instance().draw();

		_gameObjectManager.draw();
	}

	GameObject::GameObject::drawPlayerBoard();
}
