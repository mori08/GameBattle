#include"StageData.h"


GameData::StageData::StageData()
{
	
}


int GameData::StageData::get(const Rect & rect) const
{
	int t = rect.y < 0 ? -1 : rect.y / CELLSIZE;
	int b = (rect.y + rect.h) < 0 ? -1 : ((rect.y + rect.h) / CELLSIZE);
	int l = rect.x < 0 ? -1 : rect.x / CELLSIZE;
	int r = (rect.x + rect.w) < 0 ? -1 : ((rect.x + rect.w) / CELLSIZE);

	int rtn = 0;

	for (int y = t; y <= b; ++y)
	{
		for (int x = l; x <= r; ++x)
		{
			rtn = Max(rtn, getCell(Point(x, y)));
		}
	}

	return rtn;
}


Vec2 GameData::StageData::getPlayerPos(int id) const
{
	if (playerPos.size() == 0)
	{
#ifdef _DEBUG
		Println(L"error > マップにプレイヤー生成座標が設定されていません");
#endif // _DEBUG

		return Vec2::Zero;
	}

	int i = id % playerPos.size();

	return playerPos[i];
}


std::pair<Vec2, size_t> GameData::StageData::getCassettePos(const size_t & id) const
{
	if (id < 0 || id >= cassettePos.size())
	{
		size_t r = Random<size_t>(0, cassettePos.size() - 1);
		
		return move(std::pair<Vec2, size_t>(cassettePos[r], r));
	}

	size_t r = Random<size_t>(0, cassettePos.size() - 2);

	if (r >= id) { ++r; }

	return move(std::pair<Vec2, size_t>(cassettePos[r], r));
}


void GameData::StageData::draw() const
{
	TextureAsset(_name).scale(getSize().x / 960.0).draw();

	for (int y = 0; y < _height; ++y)
	{
		for (int x = 0; x < _width; ++x)
		{
			if (cell[y][x] == HARF_BLOCK)
			{
				Rect(CELLSIZE*Point(x, y), CELLSIZE).draw(Palette::Wheat);
			}
			else if (cell[y][x] == BLOCK)
			{
				Rect(CELLSIZE*Point(x, y), CELLSIZE).draw(Palette::White);
			}
		}
	}
}


int GameData::StageData::getCell(const Point & pos) const
{
	if (pos.x < 0 || pos.x >= _width) { return BLOCK; }

	if (pos.y < 0) { return EMPTY; }

	if (pos.y >= _height) { return BLOCK; }

	return cell[pos.y][pos.x];
}


void GameData::StageData::read(const String & stageName)
{
	_name = stageName;

	const CSVReader csv(L"Asset/Data/" + stageName + L".csv");

	_width = csv.columns(0);
	_height = csv.rows;

	cell = std::vector<std::vector<int>>(_height, std::vector<int>(_width));
	playerPos.clear();

	for (int y = 0; y < _height; ++y)
	{
		for (int x = 0; x < _width; ++x)
		{
			switch (csv.get<int>(y, x))
			{
			case EMPTY:
			case BLOCK:
			case HARF_BLOCK:
				cell[y][x] = csv.get<int>(y, x);
				break;

			case CASSETTE_POS:
				cell[y][x] = 0;
				cassettePos.emplace_back(x*CELLSIZE, y*CELLSIZE);
				break;

			case PLAYER_POS:
				cell[y][x] = 0;
				playerPos.emplace_back(CELLSIZE*Vec2(x, y));
				break;
			}
		}
	}

	cassetteGenerateFrameCount = Array<int>(cassettePos.size(), 0);
}
