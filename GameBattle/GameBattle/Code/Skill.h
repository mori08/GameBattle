#pragma once


#include"GameObject.h"


namespace GameObject
{
	class Player;
}


namespace Skill
{

	class Skill
	{
	protected:

		static GameData::TagData NoneTag;

		static Array<GameData::TagData> AttackTag;

	public:

		static void setTagData();

		/// <summary>
		/// 更新
		/// </summary>
		/// <param name="time"> スキルの進行状況 </param>
		/// <param name="player"> プレイヤー </param>
		/// <param name="generator"> オブジェクトの生成リスト </param>
		virtual void update(int time, GameObject::Player & player, const std::shared_ptr<GameData::Generator> & generator) = 0;

		/// <summary>
		/// 当たり判定確認
		/// </summary>
		/// <param name="collider"> 物体の領域 </param>
		/// <returns> タグ </returns>
		virtual GameData::TagData & collision(int time, const GameObject::Player & player, const Rect & collider) = 0;

		/// <summary>
		/// 描画
		/// </summary>
		/// <param name="time"> スキル進行状況 </param>
		/// <param name="player"> プレイヤー </param>
		virtual void draw(int time, const GameObject::Player & player) const = 0;

		/// <summary>
		/// 終了判定
		/// </summary>
		/// <param name="time"> スキル進行状況 </param>
		/// <returns> 終了するとき true , そうでないとき false </returns>
		virtual bool finish(int time) const = 0;

	};



}