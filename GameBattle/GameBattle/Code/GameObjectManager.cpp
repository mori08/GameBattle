#include "GameObjectManager.h"


void GameData::GameObjectManager::update()
{
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
