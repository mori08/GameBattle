#pragma once


#include"GameObject.h"

#include"PlayerBoard.h"


namespace GameData
{

	class GameObjectManager
	{
	private:

		std::list<std::unique_ptr<GameObject::GameObject>> _gameObjectList;

		std::shared_ptr<Generator> _generator; // 生成するオブジェクトのリスト

		Array<Point> _cassettePos;

	public:

		GameObjectManager();

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