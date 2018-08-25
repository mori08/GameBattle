#pragma once


#include"Skill.h"


namespace GameData
{

	class SkillManager
	{
	private:

		using skill_ptr = std::shared_ptr<Skill::Skill>;

	private:
		
		std::unordered_map<String, skill_ptr> _skillMap; // 文字列とスキルのMap

		Array<String> _skillKeyList; // _skillMapのキー（文字列）のリスト

		Array<int>    _raito;        // 確率を計算するための値

	private:

		SkillManager();

	public:
		
		SkillManager(const SkillManager&)            = delete;
		SkillManager& operator=(const SkillManager&) = delete;
		SkillManager(SkillManager&&)                 = delete;
		SkillManager & operator=(SkillManager&&)     = delete;

	public:

		/// <summary>
		/// インスタンスの取得
		/// </summary>
		static SkillManager & instance()
		{
			static SkillManager rtn;

			return rtn;
		}

		/// <summary>
		/// スキルを取得します。
		/// </summary>
		/// <param name="key"> キーとなる文字列 </param>
		/// <returns> スキルのポインタを返します </returns>
		skill_ptr & getSkill(const String & key) const;

	};

}