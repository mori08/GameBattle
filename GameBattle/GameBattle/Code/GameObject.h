#pragma once


#include<Siv3D.hpp>

#include<queue>


namespace GameObject
{
	class GameObject;
}


namespace GameData
{
	using Generator = std::queue<std::unique_ptr<GameObject::GameObject>>;

	class Tag
	{
	public:
		String type;

		Array<String> info;
	};

	using TagData = Array<Tag>;
}


namespace GameObject
{
	class GameObject
	{
	private:

		bool _isLanding = false;  // 接地判定

	protected:

		Vec2    _pos;      // 座標

		Vec2    _velocity; // 速度

		Point   _size;     // サイズ

		GameData::TagData _tagData;  // タグ

		static std::shared_ptr<GameData::Generator> _generator;

	public:

		virtual ~GameObject(){}

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

		/// <summary>
		/// オブジェクトの生成リストを設定する。
		/// </summary>
		/// <param name="generator"> オブジェクトの生成リスト </param>
		static void setGenerator(const std::shared_ptr<GameData::Generator> & generator)
		{
			_generator = generator;
		}

		/// <summary>
		/// 交差判定用の長方形の取得します。
		/// </summary>
		/// <returns> 交差判定用の長方形 </returns>
		virtual Rect getCollider()const
		{
			return Rect(_pos.asPoint() - _size / 2, _size);
		}

		/// <summary>
		/// 他オブジェクトと交差した際の処理を行います。
		/// </summary>
		/// <param name="tag"> タグ </param>
		virtual void collisionUpdate(const GameData::TagData & tagData) = 0;

	protected:

		/// <summary>
		/// 速度に応じて座標を変更します。
		/// </summary>
		/// <param name="useMapData"> マップデータをしようするとき true , しないとき false </param>
		void moveObject(bool useMapData);

		/// <summary>
		/// このオブジェクトが接地しているか示します。
		/// </summary>
		/// <returns> 接地しているとき true , そうでないとき false </returns>
		bool isLanding() const;

		/// <summary>
		/// このオブジェクトがマップに接しているか示します。
		/// </summary>
		/// <returns> 接しているとき true , そうでないとき false </returns>
		bool isTouchingMap() const;

	public:

		/// <summary>
		/// タグの文字列を分割・整理します。
		/// </summary>
		/// <param name="tagStr"> タグの文字列 </param>
		static GameData::TagData makeTagData(const String & tagsStr);

	};
}