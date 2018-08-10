#pragma once


#include<Siv3D.hpp>


namespace GameData
{

	class StageData
	{
	private:

		static const int WIDTH    = 120; // 幅

		static const int HEIGHT   = 60;  // 高さ

		static const int CELLSIZE = 16;  // １マスの１辺の長さ

		int cell[HEIGHT][WIDTH];         // マスごとのステージデータ

	public:

		static const int EMPTY      = 0; // 何もない

		static const int HARF_BLOCK = 1; // 上からは通過できるブロック

		static const int BLOCK      = 2; // ブロック

	private:

		StageData()
		{
			read();
		}

		StageData(const StageData &) {}

		StageData(StageData &&) {}

	public:

		static StageData & Instance()
		{
			static StageData stageData;

			return stageData;
		}

		/// <summary>
		/// 長方形がステージと交差しているか取得します。
		/// </summary>
		/// <param name="collider"> 長方形 </param>
		/// <returns> 交差しているとき true , そうでないとき false </returns>
		int get(const Rect & rect) const;

		/// <summary>
		/// ステージのサイズを取得します。
		/// </summary>
		Size getSize() const
		{
			return CELLSIZE*Size(WIDTH, HEIGHT);
		}

		/// <summary>
		/// マップのデータを描画する
		/// </summary>
		void draw() const;

	private:

		/// <summary>
		/// 指定された座標のステージのデータを取得します。
		/// </summary>
		/// <param name="pos"> 座標 </param>
		/// <returns> ステージのデータ </returns>
		int getCell(const Point & pos) const;

		/// <summary>
		/// CSVファイルの読み込み
		/// </summary>
		void read();

	};

}