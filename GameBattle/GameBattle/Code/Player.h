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

	private:

		int        _id;        // ���ʔԍ�

		int	       _sId;       // �X�L���̎��ʔԍ�

		skill_list _skillList; // �X�L��

		int	       _time;      // ���o�p�̎���

		State      _state;     // ���

		bool _col;

	public:

		Player(int id);

		void update() override;

		void draw() const override;

		bool eraser() const override;

		void collisionCheck(const std::unique_ptr<GameObject> & obj) override;

	private:

		void collisionUpdate(const String & tag) override;

		/// <summary>
		/// ��Ԃ�ύX���܂��B
		/// </summary>
		void changeState(const State & state);

		/// <summary>
		/// �v���C���[�̓������R���g���[���[�Ő��䂵�܂��B
		/// </summary>
		void controll();

		/// <summary>
		/// �X�L�����g�p���܂��B
		/// </summary>
		void useSkill();

	};

}