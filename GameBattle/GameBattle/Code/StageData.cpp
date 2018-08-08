#include"StageData.h"


int GameData::StageData::get(const Point & pos) const
{
	int x = pos.x / CELLSIZE;
	int y = pos.y / CELLSIZE;

	if (x < 0 || x >= WIDTH) { return 2; }

	if (y < 0) { return 0; }

	if (y >= HEIGHT) { return 2; }

	return cell[y][x];
}


int GameData::StageData::get(const Rect & rect) const
{
	int t = rect.y / CELLSIZE;
	int b = (rect.y + rect.h) / CELLSIZE;
	int l = rect.x / CELLSIZE;
	int r = (rect.x + rect.w) / CELLSIZE;

	int rtn = 0;

	for (int y = t; y <= b; ++y)
	{
		for (int x = l; x <= r; ++x)
		{
			rtn = Max(rtn, cell[y][x]);
		}
	}

	return rtn;
}


void GameData::StageData::draw() const
{
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


void GameData::StageData::read()
{
	const CSVReader csv(L"Asset/Data/Stage.csv");

	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			cell[y][x] = csv.get<int>(y, x);
		}
	}
}
