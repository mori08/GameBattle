#pragma once


#include"GameObject.h"


namespace GameObject
{

	class AttackObject : public GameObject
	{
	protected:

		int  _id;

		bool _eraseFlag = false; // オブジェクトを削除する

	public:

		bool eraser() const override;

		void collisionUpdate(const GameData::TagData & tagData) override;

	};

}