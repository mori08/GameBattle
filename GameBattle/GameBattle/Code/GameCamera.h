#pragma once


#include <HamFramework.hpp>


namespace GameData
{
	class GameCamera : public Camera2D
	{
	private:

		Camera2D _camera; // �J����

		Point    _posTL;  // ����̍��W

		Point    _posBR;  // �E���̍��W

		bool     _reset;  // true �̂Ƃ����W��ݒ肵�Ȃ���

		double   _raito;  // ��ʔ�

	public:

		GameCamera()
			: _reset(true)
			, _raito(2.0)
		{}

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