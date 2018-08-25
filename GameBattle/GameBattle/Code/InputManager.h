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

		InputManager()
			: preVec(Vec2::Zero)
		{
		};

		InputManager(const InputManager&)            = default;
		InputManager& operator=(const InputManager&) = default;
		InputManager(InputManager&&)                 = default;
		InputManager& operator=(InputManager&&)      = default;

		/// <summary>
		/// インスタンスの取得
		/// </summary>
		/// <param name="id"> プレイヤーの識別番号 </param>
		/// <returns> インスタンス </returns>
		static InputManager & Instatnce(int id)
		{
			static InputManager inputManager[PLAYER_NUM];

			return inputManager[id];
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
		/// 入力を取得します。
		/// </summary>
		/// <param name="id"> プレイヤーの識別番号 </param>
		/// <param name="buttonId"> どのボタンの入力か </param>
		/// <param name="inputType"> どのような入力か </param>
		/// <returns> 入力があったとき true , そうでないとき false </returns>
		static bool get(int id, int buttonId, const InputType & inputType);

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

	public:

		/// <summary>
		/// 入力を正しく行われているかのテスト
		/// </summary>
		static void test()
		{
#ifdef _DEBUG

			static Font font(10);

			Point base = Point::Zero;

			for (int i = 0; i < PLAYER_NUM; ++i)
			{
				if (!Gamepad(i).isConnected()) { continue; }
				
				font(L"Gamepad [", i, L"]").draw(base);

				int l = font.height;

				drawPadInput(i, Button::Left , L"←", base + Point(2*l, 3*l));
				drawPadInput(i, Button::Right, L"→", base + Point(4*l, 3*l));
				drawPadInput(i, Button::Up   , L"↑", base + Point(3*l, 2*l));
				drawPadInput(i, Button::Down , L"↓", base + Point(3*l, 4*l));

				drawPadInput(i, Button::One  , L"１", base + Point(7*l, 2*l));
				drawPadInput(i, Button::Two  , L"２", base + Point(8*l, 3*l));
				drawPadInput(i, Button::Three, L"３", base + Point(7*l, 4*l));
				drawPadInput(i, Button::Four , L"４", base + Point(6*l, 3*l));

				base.y += 5 * l;
			}

			font(L"Key").draw(base);

			int l = font.height;

			drawKeyInput(Button::Left , L"←", base + Point(2 * l, 3 * l));
			drawKeyInput(Button::Right, L"→", base + Point(4 * l, 3 * l));
			drawKeyInput(Button::Up   , L"↑", base + Point(3 * l, 2 * l));
			drawKeyInput(Button::Down , L"↓", base + Point(3 * l, 4 * l));

			drawKeyInput(Button::One  , L"１", base + Point(7 * l, 2 * l));
			drawKeyInput(Button::Two  , L"２", base + Point(8 * l, 3 * l));
			drawKeyInput(Button::Three, L"３", base + Point(7 * l, 4 * l));
			drawKeyInput(Button::Four , L"４", base + Point(6 * l, 3 * l));

#endif // _DEBUG
		}

	private:

		static void drawPadInput(int id, Button button, String str, Point pos)
		{
#ifdef _DEBUG

			static Font font(10);
			int l = font.height;
			if      (get(id, button, InputType::Clicked))  { Circle(pos, l/2).draw(Palette::Red);  font(str).drawCenter(pos); }
			else if (get(id, button, InputType::Pressed))  { font(str).drawCenter(pos); }
			else if (get(id, button, InputType::Released)) { Circle(pos, l/2).draw(Palette::Blue); font(str).drawCenter(pos); }
			else                                           { font(str).drawCenter(pos, Alpha(100)); }

#endif // _DEBUG
		}

		static void drawKeyInput(Button button, String str, Point pos)
		{
#ifdef _DEBUG

			static Font font(10);
			int l = font.height;
			if      (keyInput(button, InputType::Clicked))  { Circle(pos, l / 2).draw(Palette::Red);  font(str).drawCenter(pos); }
			else if (keyInput(button, InputType::Pressed))  { font(str).drawCenter(pos); }
			else if (keyInput(button, InputType::Released)) { Circle(pos, l / 2).draw(Palette::Blue); font(str).drawCenter(pos); }
			else                                            { font(str).drawCenter(pos, Alpha(100)); }

#endif // _DEBUG
		}

	};

}