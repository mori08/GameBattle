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

		/// <summary>
		/// �X�V
		/// </summary>
		virtual void update() = 0;

		/// <summary>
		/// �`��
		/// </summary>
		virtual void draw() const = 0;

		/// <summary>
		/// ���I�u�W�F�N�g�Ƃ̌�������
		/// </summary>
		/// <param name="obj"> �I�u�W�F�N�g </param>
		virtual void collisionCheck(const std::unique_ptr<GameObject> & obj);

	protected:

		/// <summary>
		/// ��������p�̒����`�̎擾
		/// </summary>
		/// <returns> ��������p�̒����` </returns>
		virtual Rect & getCollider()const
		{
			return Rect(_pos.asPoint() - _size / 2, _size);
		}

		/// <summary>
		/// ���I�u�W�F�N�g�ƌ��������ۂ̏���
		/// </summary>
		/// <param name="tag"> �^�O </param>
		virtual void collisionUpdate(const String & Tag) = 0;
	};
}