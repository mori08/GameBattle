#pragma once


#include <Siv3D.hpp>
#include <HamFramework.hpp>


namespace GameData
{
	class GameCamera : public BasicCamera2D
	{
	private:

		Camera2D _camera; // カメラ

		Point    _posTL;  // 左上の座標

		Point    _posBR;  // 右下の座標

		bool     _reset;  // true のとき座標を設定しなおす

		double   _raito;  // 画面比

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
		/// 被写体の座標を登録します。
		/// </summary>
		/// <param name="pos"> 座標 </param>
		void setPlayerPos(const Point & pos);

		/// <summary>
		/// 更新
		/// </summary>
		void update();

	};
}