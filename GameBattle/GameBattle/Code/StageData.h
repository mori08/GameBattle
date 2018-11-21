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

		int _width; // 幅

		int _height;  // 高さ

		String _name; // ステージ名

		static const int CASSETTE_POS = 3;     // カセット出現箇所

		static const int PLAYER_POS = 4;       // プレイヤー生成座標

		std::vector<std::vector<int>> cell;    // マスごとのステージデータ

		std::vector<Vec2> playerPos;           // プレイヤー生成の座標
	public:

		Array<Vec2> cassettePos;               // カセットを生成する座標

		Array<int> cassetteGenerateFrameCount; // カセット生成までのフレーム数

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
			return CELLSIZE*Size(_width, _height);
		}

		/// <summary>
		/// プレイヤーを生成する座標を取得します。
		/// </summary>
		/// <param name="id"> プレイヤーの識別番号 </param>
		/// <returns> 
		Vec2 getPlayerPos(int id)const;

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

		/// <summary>
		/// 指定された座標のステージのデータを取得します。
		/// </summary>
		/// <param name="pos"> 座標 </param>
		/// <returns> ステージのデータ </returns>
		int getCell(const Point & pos) const;

		/// <summary>
		/// CSVファイルの読み込み
		/// </summary>
		/// <param name="stageName"> ステージ名 </param>
		void read(const String & stageName);

	};

}