#pragma once


#include"Skill.h"


namespace GameObject
{

	class Player : public GameObject
	{
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

		const double DEFAULT_MOVE_SPEED = 4.0; // �����ړ����x

	private:
		
		int        _id;        // ���ʔԍ�

		int	       _sId;       // �X�L���̎��ʔԍ�

		skill_list _skillList; // �X�L��

		int	       _time;      // ���o�p�̎���

		State      _state;     // ���

		int	       _direction; // ���� �������̂Ƃ� -1 , �E�����̂Ƃ� +1

		double     _moveSpeed; // ���E�����ւ̈ړ����x

		bool _col;

	public:

		Player(int id);

		void update() override;

		void draw() const override;

		bool eraser() const override;

		void collisionCheck(const std::unique_ptr<GameObject> & obj) override;

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

	private:

		void collisionUpdate(const String & tag) override;

		/// <summary>
		/// ��Ԃ�ύX���܂��B
		/// </summary>
		void changeState(const State & state);

		/// <summary>
		/// �v���C���[�̓������R���g���[���[�Ő��䂵�܂��B
		/// </summary>
		void controllMove();

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