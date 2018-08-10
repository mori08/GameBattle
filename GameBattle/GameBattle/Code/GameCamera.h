#pragma once


#include <Siv3D.hpp>
#include <HamFramework.hpp>


namespace GameData
{
	class GameCamera : public BasicCamera2D
	{
	private:

		Camera2D _camera; // �J����

		Point    _posTL;  // ����̍��W

		Point    _posBR;  // �E���̍��W

		bool     _reset;  // true �̂Ƃ����W��ݒ肵�Ȃ���

		double   _raito;  // ��ʔ�

		double   _lerpRatio;

	private:

		GameCamera()
			: _reset(true)
			, _raito(2.0)
			, _lerpRatio(0.01)
		{}

		GameCamera(const GameCamera &) {}

		GameCamera(GameCamera &&) {}

	public:

		static GameCamera & Instance()
		{
			static GameCamera camera;

			return camera;
		}

		/// <summary>
		/// ��ʑ̂̍��W��o�^���܂��B
		/// </summary>
		/// <param name="pos"> ���W </param>
		void setPlayerPos(const Point & pos);

		/// <summary>
		/// �X�V
		/// </summary>
		void update();

	};
}