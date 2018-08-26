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

		Array<int>    _rate;         // 確率を計算するための値

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
		skill_ptr getSkill(const String & key) const;

		/// <summary>
		/// ランダムでキーとなる文字列を取得します。
		/// </summary>
		/// <returns> キーとなる文字列 </returns>
		String getKeyRamdom();

	private:

		/// <summary>
		/// ゲームで使用するスキルを全て登録します。
		/// </summary>
		void setAllSkill();

		/// <summary>
		/// スキルを登録します。
		/// </summary>
		/// <param name="key"> キーとなる文字列 </param>
		template<typename SKILL_TYPE>
		void setSkill(const String & key)
		{
			_skillMap[key] = std::make_shared<SKILL_TYPE>();

			_skillKeyList.emplace_back(key);

			_raito.emplace_back(1);
		}

	};

}