#pragma once


#include"Skill.h"


namespace GameObject
{
	class Player : public GameObject
	{
	public:

		static const int
			WALK_0 = 0,
			WALK_1 = 1,
			WALK_2 = 2,
			WALK_3 = 3,
			STAND  = 4,
			SET_UP = 5,
			SIT    = 6,
			DOWN   = 7,
			JAMP   = 8,
			DAMAGE = 9,
			ATTACK = 10;
			

	private:

		using skill_ptr  = std::shared_ptr<Skill::Skill>;
		using skill_list = std::array<skill_ptr, 4>;

		enum class State
		{
			NORMAL,
			GET_SKILL,
			USING_SKILL
		};

		static const int LEFT  = -1;
		static const int RIGHT = +1;

		const double GRAVITY = 0.6;

		const double DEFAULT_MOVE_SPEED = 4.0; // �����ړ����x

	private:
		
		int        _id;              // ���ʔԍ�

		int	       _sId;             // �X�L���̎��ʔԍ�

		skill_list _skillList;       // �X�L��

		std::array<int,4> _skillNum; // �X�L���̎c��g�p��

		int	       _time;            // ���o�p�̎���

		State      _state;           // ���

		int	       _direction;       // ���� �������̂Ƃ� -1 , �E�����̂Ƃ� +1

		double     _moveSpeed;       // ���E�����ւ̈ړ����x

		bool       _muteki;          // true �̂Ƃ������蔻�莞�̏����𖳌�

		bool       _disabledGravity; // �d�͉����x�𖳌��ɂ���

		int        _textureId;       // �\������摜�̔ԍ�

		bool       _col;

	public:

		Player(int id);

		void update() override;

		void draw() const override;

		bool eraser() const override;

		void collisionCheck(const std::unique_ptr<GameObject> & obj) override;
		
		void collisionUpdate(const GameData::TagData & tagData) override;

	public:

		/// <summary>
		/// ���W���擾���܂��B
		/// </summary>
		/// <returns> ���W </returns>
		Vec2 getPos() const { return _pos; }

		/// <summary>
		/// �v���C���[�̎��ʔԍ����擾���܂��B
		/// </summary>
		/// <returns> �v���C���[�̎��ʔԍ� </returns>
		int getId() const { return _id; }

		/// <summary>
		/// �v���C���[�̌����Ă���������擾���܂��B
		/// </summary>
		/// <returns> ���� �������̂Ƃ� -1 , �E�����̂Ƃ� +1 </returns>
		int getDirection() const { return _direction; };

		/// <summary>
		/// �v���C���[�̓������R���g���[���[�Ő��䂵�܂��B
		/// </summary>
		void controllMove();

		/// <summary>
		/// ���G��Ԃ�ݒ肵�܂��B
		/// </summary>
		/// <param name="m"> true �̂Ƃ� ���G��� , false �̂Ƃ� ���� </param>
		void setMuteki(bool m)
		{
			_muteki = m;
		}

		/// <summary>
		/// ���x��ݒ肵�܂��B
		/// </summary>
		/// <param name="v"> ���x </param>
		/// <remarks> ���̊֐����Ă񂾃��[�v�ł͉����x�͖�������܂��B </remarks>
		void setVelocity(const Vec2 & v)
		{
			_disabledGravity = true;
			_velocity = v;
		}

		/// <summary>
		/// �v���C���[�̉摜��ύX���܂��B
		/// </summary>
		/// <param name="texture_id"> �摜�̎��ʔԍ� </param>
		void setTextureId(int textureId)
		{
			_textureId = textureId;
		}

	private:

		/// <summary>
		/// ��Ԃ�ύX���܂��B
		/// </summary>
		void changeState(const State & state);

		/// <summary>
		/// �ʏ펞�̏���
		/// </summary>
		void normal();

		/// <summary>
		/// �X�L�����g�p���܂��B
		/// </summary>
		void useSkill();

		/// <summary>
		/// �X�L�����l�����܂��B
		/// </summary>
		void getSkill();

		/// <summary>
		/// �v���C���[��`�悵�܂��B
		/// </summary>
		void drawPlayer() const;

		/// <summary>
		/// �X�L�����l�����邽�߂̕ǂ�`�悵�܂��B
		/// </summary>
		void drawSkillWall() const;

	};

}