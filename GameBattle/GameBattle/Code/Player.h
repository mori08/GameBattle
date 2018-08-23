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

		int        _id;        // 識別番号

		int	       _sId;       // スキルの識別番号

		skill_list _skillList; // スキル

		int	       _time;      // 演出用の時間

		State      _state;     // 状態

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
		/// 状態を変更します。
		/// </summary>
		void changeState(const State & state);

		/// <summary>
		/// プレイヤーの動きをコントローラーで制御します。
		/// </summary>
		void controll();

		/// <summary>
		/// スキルを使用します。
		/// </summary>
		void useSkill();

	};

}