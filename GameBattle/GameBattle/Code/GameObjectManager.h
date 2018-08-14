#pragma once


#include"GameObject.h"


namespace GameData
{
	class GameObjectManager
	{
	private:

		std::list<std::unique_ptr<GameObject::GameObject>> _gameObjectList;

	public:

		/// <summary>
		/// オブジェクトの更新
		/// </summary>
		void update();

		/// <summary>
		/// オブジェクトの描画
		/// </summary>
		void draw()const;

	};
}