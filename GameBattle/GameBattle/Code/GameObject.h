#pragma once


#include<Siv3D.hpp>


namespace GmaeObject
{
	class GameObject
	{
	private:

		Vec2   _pos;      // ���W

		Vec2   _velocity; // ���x

		Point  _size;     // �T�C�Y

		String _tag;      // �^�O

	public:

		virtual void update() = 0;

		virtual void draw() const = 0;

		virtual void collisionCheck(const std::unique_ptr<GameObject> & obj);

		virtual void collisionUpdate(const String & Tag);
	};
}