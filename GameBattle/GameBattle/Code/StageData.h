#pragma once


#include<Siv3D.hpp>


namespace GameData
{

	class StageData
	{
	public:

		static const int CELLSIZE   = 16; // １マスの１辺の長さ

		static const int EMPTY      = 0;  // 何もない

		static const int HARF_BLOCK = 1;  // 上からは通過できるブロック

		static const int BLOCK      = 2;  // ブロック

	private:

		static const int WIDTH = 120; // 幅

		static const int HEIGHT = 60;  // 高さ

		static const int CASSETTE_POS = 3; // カセット出現箇所

	private:

		int cell[HEIGHT][WIDTH];         // マスごとのステージデータ

		Array<Vec2> cassettePos;        // カセットを生成する座標

	private:

		StageData();

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
		/// カセットを出現させる座標をランダムで決定します。
		/// </summary>
		/// <param name="id"> 抽選から除外する座標の番号 </param>
		/// <returns> 座標とその識別番号 </returns>
		std::pair<Vec2, size_t> getCassettePos(const size_t & id) const;

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