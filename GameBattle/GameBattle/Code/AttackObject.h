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

	protected:

		/// <summary>
		/// 基本的な遠距離攻撃の動き
		/// </summary>
		/// <param name="gravity"> 重力による下方向の加速度 </param>
		void shooting(double gravity);

		/// <summary>
		/// 歩く生物的な動き
		/// </summary>
		void walking();
	};

}