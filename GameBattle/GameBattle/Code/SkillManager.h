#pragma once


#include"Skill.h"


namespace GameData
{

	class SkillManager
	{
	private:

		using skill_ptr = std::shared_ptr<Skill::Skill>;

	private:
		
		std::unordered_map<String, skill_ptr> _skillMap; // ������ƃX�L����Map

		Array<String> _skillKeyList; // _skillMap�̃L�[�i������j�̃��X�g

		Array<int>    _raito;        // �m�����v�Z���邽�߂̒l

	private:

		SkillManager();

	public:
		
		SkillManager(const SkillManager&)            = delete;
		SkillManager& operator=(const SkillManager&) = delete;
		SkillManager(SkillManager&&)                 = delete;
		SkillManager & operator=(SkillManager&&)     = delete;

	public:

		/// <summary>
		/// �C���X�^���X�̎擾
		/// </summary>
		static SkillManager & instance()
		{
			static SkillManager rtn;

			return rtn;
		}

		/// <summary>
		/// �X�L�����擾���܂��B
		/// </summary>
		/// <param name="key"> �L�[�ƂȂ镶���� </param>
		/// <returns> �X�L���̃|�C���^��Ԃ��܂� </returns>
		skill_ptr & getSkill(const String & key) const;

	};

}