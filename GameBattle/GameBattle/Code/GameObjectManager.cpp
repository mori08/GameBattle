#include "GameObjectManager.h"
#include "StageData.h"
#include "Player.h"
#include "Cassette.h"


GameData::GameObjectManager::GameObjectManager()
{
	Skill::Skill::setTagData();

	_generator = std::make_shared<Generator>();
	GameObject::GameObject::setGenerator(_generator);

	for (int i = 0; i < 4; ++i)
	{
		_gameObjectList.emplace_back(std::make_unique<GameObject::Player>(i));
	}

	GameObject::GameObject::initPlayerBoard(4);

	//_gameObjectList.emplace_back(std::make_unique<GameObject::Cassette>(-1)); 
}


void GameData::GameObjectManager::update()
{
	cassetteManage();

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


void GameData::GameObjectManager::cassetteManage()
{
	for (int i = 0; i < StageData::Instance().cassetteGenerateFrameCount.size(); ++i)
	{
		if (StageData::Instance().cassetteGenerateFrameCount[i]-- == 0)
		{
			_gameObjectList.emplace_back(std::make_unique<GameObject::Cassette>(i));
		}
	}
}

