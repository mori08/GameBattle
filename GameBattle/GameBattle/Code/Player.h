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

		const double DEFAULT_MOVE_SPEED = 4.0; // 初期移動速度

	private:
		
		int        _id;        // 識別番号

		int	       _sId;       // スキルの識別番号

		skill_list _skillList; // スキル

		int	       _time;      // 演出用の時間

		State      _state;     // 状態

		int	       _direction; // 向き 左向きのとき -1 , 右向きのとき +1

		double     _moveSpeed; // 左右方向への移動速度

		bool _col;

	public:

		Player(int id);

		void update() override;

		void draw() const override;

		bool eraser() const override;

		void collisionCheck(const std::unique_ptr<GameObject> & obj) override;

	public:

		/// <summary>
		/// 座標を取得します。
		/// </summary>
		/// <returns> 座標 </returns>
		Vec2 getPos() const { return _pos; }

		/// <summary>
		/// プレイヤーの識別番号を取得します。
		/// </summary>
		/// <returns> プレイヤーの識別番号 </returns>
		int getId() const { return _id; }

		/// <summary>
		/// プレイヤーの向いている方向を取得します。
		/// </summary>
		/// <returns> 方向 左向きのとき -1 , 右向きのとき +1 </returns>
		int getDirection() const { return _direction; };

	private:

		void collisionUpdate(const String & tag) override;

		/// <summary>
		/// 状態を変更します。
		/// </summary>
		void changeState(const State & state);

		/// <summary>
		/// プレイヤーの動きをコントローラーで制御します。
		/// </summary>
		void controllMove();

		/// <summary>
		/// 通常時の処理
		/// </summary>
		void normal();

		/// <summary>
		/// スキルを使用します。
		/// </summary>
		void useSkill();

		/// <summary>
		/// スキルを獲得します。
		/// </summary>
		void getSkill();

		/// <summary>
		/// プレイヤーを描画します。
		/// </summary>
		void drawPlayer() const;

		/// <summary>
		/// スキルを獲得するための壁を描画します。
		/// </summary>
		void drawSkillWall() const;

	};

}