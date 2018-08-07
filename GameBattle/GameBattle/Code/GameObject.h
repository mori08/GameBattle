#pragma once


#include<Siv3D.hpp>


namespace GmaeObject
{
	class GameObject
	{
	private:

		Vec2   _pos;      // 座標

		Vec2   _velocity; // 速度

		Point  _size;     // サイズ

		String _tag;      // タグ

	public:

		virtual void update() = 0;

		virtual void draw() const = 0;

		virtual void collisionCheck(const std::unique_ptr<GameObject> & obj);

		virtual void collisionUpdate(const String & Tag);
	};
}