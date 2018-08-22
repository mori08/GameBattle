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
	// �I�u�W�F�N�g�̐���
	while (!_generator->empty())
	{
		_gameObjectList.emplace_back(move(_generator->front()));
		_generator->pop();
	}

	// �I�u�W�F�N�g�̍X�V
	for (auto & object : _gameObjectList)
	{
		object->update();
	}

	// ��������y�т��̏���
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

	// �I�u�W�F�N�g�̍폜
	_gameObjectList.remove_if([](auto & itr) { return itr->eraser(); });
}


void GameData::GameObjectManager::draw() const
{
	for (const auto & object : _gameObjectList)
	{
		object->draw();
	}
}
