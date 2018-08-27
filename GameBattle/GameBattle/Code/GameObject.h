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

		bool _isLanding = false;  // �ڒn����

	protected:

		Vec2    _pos;      // ���W

		Vec2    _velocity; // ���x

		Point   _size;     // �T�C�Y

		GameData::TagData _tagData;  // �^�O

		static std::shared_ptr<GameData::Generator> _generator;

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
		virtual void collisionUpdate(const GameData::TagData & tagData) = 0;

	protected:

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

		/// <summary>
		/// ���̃I�u�W�F�N�g���}�b�v�ɐڂ��Ă��邩�����܂��B
		/// </summary>
		/// <returns> �ڂ��Ă���Ƃ� true , �����łȂ��Ƃ� false </returns>
		bool isTouchingMap() const;

	public:

		/// <summary>
		/// �^�O�̕�����𕪊��E�������܂��B
		/// </summary>
		/// <param name="tagStr"> �^�O�̕����� </param>
		static GameData::TagData makeTagData(const String & tagsStr);

	};
}