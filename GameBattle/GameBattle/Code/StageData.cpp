#include"StageData.h"


GameData::StageData::StageData()
{
	read();
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
	TextureAsset(L"stage").draw();

	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			if (cell[y][x] == 1)
			{
				Rect(CELLSIZE*Point(x, y), CELLSIZE).draw(Palette::Wheat);
			}
			else if (cell[y][x] == 2)
			{
				Rect(CELLSIZE*Point(x, y), CELLSIZE).draw(Palette::White);
			}
		}
	}
}


int GameData::StageData::getCell(const Point & pos) const
{
	if (pos.x < 0 || pos.x >= WIDTH) { return BLOCK; }

	if (pos.y < 0) { return EMPTY; }

	if (pos.y >= HEIGHT) { return BLOCK; }

	return cell[pos.y][pos.x];
}


void GameData::StageData::read()
{
	const CSVReader csv(L"Asset/Data/Stage.csv");

	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
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
			}
		}
	}
}
