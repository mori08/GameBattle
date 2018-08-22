#include "GameObjectManager.h"
#include "Player.h"


GameData::GameObjectManager::GameObjectManager()
{
	_generator = std::make_shared<Generator>();
	GameObject::GameObject::setGenerator(_generator);

	for (int i = 0; i < 2; ++i)
	{
		_gameObjectList.emplace_back(std::make_unique<GameObject::Player>(i));
	}
}


void GameData::GameObjectManager::update()
{
	// オブジェクトの生成
	while (!_generator->empty())
	{
		_gameObjectList.emplace_back(move(_generator->front()));
		_generator->pop();
	}

	// オブジェクトの更新
	for (auto & object : _gameObjectList)
	{
		object->update();
	}

	// 交差判定及びその処理
	for(auto & object1 : _gameObjectList)
	{
		for (auto & object2 : _gameObjectList)
		{
			if (object1 == object2)
			{
				continue;
			}

			object1->collisionCheck(object2);
		}
	}

	// オブジェクトの削除
	_gameObjectList.remove_if([](auto & itr) { return itr->eraser(); });
}


void GameData::GameObjectManager::draw() const
{
	for (const auto & object : _gameObjectList)
	{
		object->draw();
	}
}
