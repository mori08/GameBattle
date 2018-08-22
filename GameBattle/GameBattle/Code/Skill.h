#pragma once


#include"Player.h"


namespace GameData
{

	class Skill
	{
	public:

		/// <summary>
		/// 更新
		/// </summary>
		/// <param name="time"> スキルの進行状況 </param>
		/// <param name="player"> プレイヤー </param>
		/// <param name="generator"> オブジェクトの生成リスト </param>
		virtual void update(int time, const GameObject::Player & player, const std::shared_ptr<Generator> & generator) = 0;

		/// <summary>
		/// 当たり判定確認
		/// </summary>
		/// <param name="collider"> 物体の領域 </param>
		/// <returns> タグ </returns>
		virtual String collision(const Rect & collider) = 0;

		/// <summary>
		/// 描画
		/// </summary>
		/// <param name="time"> スキル進行状況 </param>
		/// <param name="player"> プレイヤー </param>
		virtual void draw(int time, const GameObject::Player & player) const = 0;

	};

}