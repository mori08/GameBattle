#pragma once


#include<Siv3D.hpp>


namespace GameData
{

	class StageData
	{
	private:

		static const int WIDTH = 60;

		static const int HEIGHT = 30;

		static const int CELLSIZE = 16;

		bool cell[HEIGHT][WIDTH];

	private:

		StageData()
		{
			read();
		}

		StageData(const StageData & sd) {}

		StageData(StageData && sd) {}

	public:

		static StageData & Instance()
		{
			static StageData stageData;

			return stageData;
		}

		/// <summary>
		/// 指定された座標のステージのデータを取得します。
		/// </summary>
		/// <param name="pos"> 座標 </param>
		/// <returns> ステージのデータ </returns>
		bool get(const Point & pos) const;

		/// <summary>
		/// 長方形がステージと交差しているか取得します。
		/// </summary>
		/// <param name="collider"> 長方形 </param>
		/// <returns> 交差しているとき true , そうでないとき false </returns>
		bool get(const Rect & rect) const;

		/// <summary>
		/// マップのデータを描画する
		/// </summary>
		void draw() const;

	private:

		void read();

	};

}