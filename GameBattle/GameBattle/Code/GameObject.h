#pragma once


#include<Siv3D.hpp>


namespace GmaeObject
{
	class GameObject
	{
	protected:

		Vec2   _pos;      // 座標

		Vec2   _velocity; // 速度

		Point  _size;     // サイズ

		String _tag;      // タグ

	public:

		/// <summary>
		/// 更新
		/// </summary>
		virtual void update() = 0;

		/// <summary>
		/// 描画
		/// </summary>
		virtual void draw() const = 0;

		/// <summary>
		/// 削除するかどうか示します。
		/// </summary>
		/// <returns> 削除するとき true , そうでないとき false </returns>
		virtual bool eraser() const = 0;

		/// <summary>
		/// 他オブジェクトとの交差判定を行います。
		/// </summary>
		/// <param name="obj"> オブジェクト </param>
		virtual void collisionCheck(const std::unique_ptr<GameObject> & obj);

	protected:

		/// <summary>
		/// 交差判定用の長方形の取得します。
		/// </summary>
		/// <returns> 交差判定用の長方形 </returns>
		virtual Rect & getCollider()const
		{
			return Rect(_pos.asPoint() - _size / 2, _size);
		}

		/// <summary>
		/// 他オブジェクトと交差した際の処理を行います。
		/// </summary>
		/// <param name="tag"> タグ </param>
		virtual void collisionUpdate(const String & Tag) = 0;

	private:

		/// <summary>
		/// 速度に応じて座標を変更します。
		/// </summary>
		/// <param name="useMapData"> マップデータをしようするとき true , しないとき false </param>
		void moveObject(bool useMapData);

	};
}