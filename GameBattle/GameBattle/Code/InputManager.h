#pragma once


#include<Siv3D.hpp>


namespace GameData
{

	enum class Button
	{
		Left,
		Right,
		Up,
		Down,
		One,
		Two,
		Three,
		Four
	};

	enum class InputType
	{
		Clicked,
		Pressed,
		Released
	};

	class InputManager
	{
	private:

		static const int PLAYER_NUM = 4; // プレイヤーの人数

		Vec2 preVec; // 一フレーム前のアナログパッドの動き

	private:

		InputManager();

		InputManager(const InputManager&)            = delete;
		InputManager& operator=(const InputManager&) = delete;
		InputManager(InputManager&&)                 = delete;
		InputManager& operator=(InputManager&&)      = delete;

		/// <summary>
		/// インスタンスの取得
		/// </summary>
		/// <param name="id"> プレイヤーの識別番号 </param>
		/// <returns> インスタンス </returns>
		static InputManager & instatnce(int id)
		{
			static InputManager instance[PLAYER_NUM];
			return instance[id];
		}

	public:

		/// <summary>
		/// 入力を取得します。
		/// </summary>
		/// <param name="id"> プレイヤーの識別番号 </param>
		/// <param name="button"> どのボタンの入力か </param>
		/// <param name="inputType"> どのような入力か </param>
		/// <returns> 入力があったとき true , そうでないとき false </returns>
		static bool get(int id, const Button & button, const InputType & inputType);

		/// <summary>
		/// アナログパッドの倒されている方向を更新します。
		/// </summary>
		static void updatePreVec();

	private:

		/// <summary>
		/// キーボードでの入力を管理します。
		/// </summary>
		/// <param name="button"> どのボタンの入力か </param>
		/// <param name="inputType"> どのような入力か </param>
		/// <returns> 入力があったとき true , そうでないとき false </returns> 
		static bool keyInput(const Button & button, const InputType & inputType);

		/// <summary>
		/// ゲームパッドでの入力を取得します。
		/// </summary>
		/// <param name="pad"> ゲームパッド </param>
		/// <param name="button"> どのボタンの入力か </param>
		/// <param name="inputType"> どのような入力か </param>
		/// <returns> 入力があったとき true , そうでないとき false </returns>
		bool padInput(const Gamepad & pad, const Button & button, const InputType & inputType);

		/// <summary>
		/// アナログパッドの入力を2値で取得します。
		/// </summary>
		/// <param name="value"> 値 </param>
		/// <param name="preValue"> 一フレーム前の値 </param>
		/// <param name="inputType"> どのような入力か </param>
		/// <returns> 入力があったとき true , そうでないとき false </returns>
		bool analogInput(double value, double preValue, InputType inputType);

	};

}