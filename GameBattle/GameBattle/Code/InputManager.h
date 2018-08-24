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

		InputManager();

		InputManager(const InputManager&)            = delete;
		InputManager& operator=(const InputManager&) = delete;
		InputManager(InputManager&&)                 = delete;
		InputManager& operator=(InputManager&&)      = delete;

		/// <summary>
		/// �C���X�^���X�̎擾
		/// </summary>
		/// <param name="id"> �v���C���[�̎��ʔԍ� </param>
		/// <returns> �C���X�^���X </returns>
		static InputManager & instatnce(int id)
		{
			static InputManager instance[PLAYER_NUM];
			return instance[id];
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

	};

}