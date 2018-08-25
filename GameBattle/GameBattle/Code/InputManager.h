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

		static const int PLAYER_NUM = 4; // �v���C���[�̐l��

		Vec2 preVec; // ��t���[���O�̃A�i���O�p�b�h�̓���

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
		/// �C���X�^���X�̎擾
		/// </summary>
		/// <param name="id"> �v���C���[�̎��ʔԍ� </param>
		/// <returns> �C���X�^���X </returns>
		static InputManager & Instatnce(int id)
		{
			static InputManager inputManager[PLAYER_NUM];

			return inputManager[id];
		}

	public:

		/// <summary>
		/// ���͂��擾���܂��B
		/// </summary>
		/// <param name="id"> �v���C���[�̎��ʔԍ� </param>
		/// <param name="button"> �ǂ̃{�^���̓��͂� </param>
		/// <param name="inputType"> �ǂ̂悤�ȓ��͂� </param>
		/// <returns> ���͂��������Ƃ� true , �����łȂ��Ƃ� false </returns>
		static bool get(int id, const Button & button, const InputType & inputType);

		/// <summary>
		/// ���͂��擾���܂��B
		/// </summary>
		/// <param name="id"> �v���C���[�̎��ʔԍ� </param>
		/// <param name="buttonId"> �ǂ̃{�^���̓��͂� </param>
		/// <param name="inputType"> �ǂ̂悤�ȓ��͂� </param>
		/// <returns> ���͂��������Ƃ� true , �����łȂ��Ƃ� false </returns>
		static bool get(int id, int buttonId, const InputType & inputType);

		/// <summary>
		/// �A�i���O�p�b�h�̓|����Ă���������X�V���܂��B
		/// </summary>
		static void updatePreVec();

	private:

		/// <summary>
		/// �L�[�{�[�h�ł̓��͂��Ǘ����܂��B
		/// </summary>
		/// <param name="button"> �ǂ̃{�^���̓��͂� </param>
		/// <param name="inputType"> �ǂ̂悤�ȓ��͂� </param>
		/// <returns> ���͂��������Ƃ� true , �����łȂ��Ƃ� false </returns> 
		static bool keyInput(const Button & button, const InputType & inputType);

		/// <summary>
		/// �Q�[���p�b�h�ł̓��͂��擾���܂��B
		/// </summary>
		/// <param name="pad"> �Q�[���p�b�h </param>
		/// <param name="button"> �ǂ̃{�^���̓��͂� </param>
		/// <param name="inputType"> �ǂ̂悤�ȓ��͂� </param>
		/// <returns> ���͂��������Ƃ� true , �����łȂ��Ƃ� false </returns>
		bool padInput(const Gamepad & pad, const Button & button, const InputType & inputType);

		/// <summary>
		/// �A�i���O�p�b�h�̓��͂�2�l�Ŏ擾���܂��B
		/// </summary>
		/// <param name="value"> �l </param>
		/// <param name="preValue"> ��t���[���O�̒l </param>
		/// <param name="inputType"> �ǂ̂悤�ȓ��͂� </param>
		/// <returns> ���͂��������Ƃ� true , �����łȂ��Ƃ� false </returns>
		bool analogInput(double value, double preValue, InputType inputType);

	public:

		/// <summary>
		/// ���͂𐳂����s���Ă��邩�̃e�X�g
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

				drawPadInput(i, Button::Left , L"��", base + Point(2*l, 3*l));
				drawPadInput(i, Button::Right, L"��", base + Point(4*l, 3*l));
				drawPadInput(i, Button::Up   , L"��", base + Point(3*l, 2*l));
				drawPadInput(i, Button::Down , L"��", base + Point(3*l, 4*l));

				drawPadInput(i, Button::One  , L"�P", base + Point(7*l, 2*l));
				drawPadInput(i, Button::Two  , L"�Q", base + Point(8*l, 3*l));
				drawPadInput(i, Button::Three, L"�R", base + Point(7*l, 4*l));
				drawPadInput(i, Button::Four , L"�S", base + Point(6*l, 3*l));

				base.y += 5 * l;
			}

			font(L"Key").draw(base);

			int l = font.height;

			drawKeyInput(Button::Left , L"��", base + Point(2 * l, 3 * l));
			drawKeyInput(Button::Right, L"��", base + Point(4 * l, 3 * l));
			drawKeyInput(Button::Up   , L"��", base + Point(3 * l, 2 * l));
			drawKeyInput(Button::Down , L"��", base + Point(3 * l, 4 * l));

			drawKeyInput(Button::One  , L"�P", base + Point(7 * l, 2 * l));
			drawKeyInput(Button::Two  , L"�Q", base + Point(8 * l, 3 * l));
			drawKeyInput(Button::Three, L"�R", base + Point(7 * l, 4 * l));
			drawKeyInput(Button::Four , L"�S", base + Point(6 * l, 3 * l));

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