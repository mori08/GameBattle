#pragma once


#include"GameObject.h"


namespace GameData
{

	class GameObjectManager
	{
	private:

		std::list<std::unique_ptr<GameObject::GameObject>> _gameObjectList;

		std::shared_ptr<Generator> _generator; // ��������I�u�W�F�N�g�̃��X�g

	public:

		GameObjectManager();

		/// <summary>
		/// �I�u�W�F�N�g�̍X�V
		/// </summary>
		void update();

		/// <summary>
		/// �I�u�W�F�N�g�̕`��
		/// </summary>
		void draw()const;

	};
}