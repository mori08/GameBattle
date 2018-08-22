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
}


namespace GameObject
{
	class GameObject
	{
	private:

		bool _isLanding = false;  // �ڒn����

		static std::shared_ptr<GameData::Generator> _generator;

	protected:

		Vec2   _pos;      // ���W

		Vec2   _velocity; // ���x

		Point  _size;     // �T�C�Y

		String _tag;      // �^�O

	public:

		virtual ~GameObject(){}

		/// <summary>
		/// �X�V
		/// </summary>
		virtual void update() = 0;

		/// <summary>
		/// �`��
		/// </summary>
		virtual void draw() const = 0;

		/// <summary>
		/// �폜���邩�ǂ��������܂��B
		/// </summary>
		/// <returns> �폜����Ƃ� true , �����łȂ��Ƃ� false </returns>
		virtual bool eraser() const = 0;

		/// <summary>
		/// ���I�u�W�F�N�g�Ƃ̌���������s���܂��B
		/// </summary>
		/// <param name="obj"> �I�u�W�F�N�g </param>
		virtual void collisionCheck(const std::unique_ptr<GameObject> & obj);

		/// <summary>
		/// �I�u�W�F�N�g�̐������X�g��ݒ肷��B
		/// </summary>
		/// <param name="generator"> �I�u�W�F�N�g�̐������X�g </param>
		static void setGenerator(const std::shared_ptr<GameData::Generator> & generator)
		{
			_generator = generator;
		}

	protected:

		/// <summary>
		/// ��������p�̒����`�̎擾���܂��B
		/// </summary>
		/// <returns> ��������p�̒����` </returns>
		virtual Rect getCollider()const
		{
			return Rect(_pos.asPoint() - _size / 2, _size);
		}

		/// <summary>
		/// ���I�u�W�F�N�g�ƌ��������ۂ̏������s���܂��B
		/// </summary>
		/// <param name="tag"> �^�O </param>
		virtual void collisionUpdate(const String & Tag) = 0;

		/// <summary>
		/// ���x�ɉ����č��W��ύX���܂��B
		/// </summary>
		/// <param name="useMapData"> �}�b�v�f�[�^�����悤����Ƃ� true , ���Ȃ��Ƃ� false </param>
		void moveObject(bool useMapData);

		/// <summary>
		/// ���̃I�u�W�F�N�g���ڒn���Ă��邩�����܂��B
		/// </summary>
		/// <returns> �ڒn���Ă���Ƃ� true , �����łȂ��Ƃ� false </returns>
		bool isLanding() const;

	};
}