#pragma once


#include"GameObject.h"


namespace GameObject
{

	class AttackObject : public GameObject
	{
	protected:

		int  _id;   // プレイヤーの識別番号

		int  _time; // オブジェクトが生成されてからかかる時間

		bool _eraseFlag = false; // オブジェクトを削除する

		int  _endTime; // timeと値が等しくなると

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