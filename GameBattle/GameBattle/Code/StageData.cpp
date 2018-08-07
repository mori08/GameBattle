#include"StageData.h"


bool GameData::StageData::get(const Point & pos) const
{
	int x = pos.x / CELLSIZE;
	int y = pos.y / CELLSIZE;

	if (x < 0 || x >= WIDTH) { return true; }

	if (y < 0) { return false; }

	if (y >= HEIGHT) { return true; }

	return cell[y][x];
}


bool GameData::StageData::get(const Rect & rect) const
{
	int t = rect.y / CELLSIZE;
	int b = (rect.y + rect.h) / CELLSIZE;
	int l = rect.x / CELLSIZE;
	int r = (rect.x + rect.w) / CELLSIZE;

	for (int y = t; y <= b; ++y)
	{
		for (int x = l; x <= r; ++x)
		{
			if (get(Point(x, y))) { return true; }
		}
	}

	return false;
}


void GameData::StageData::draw() const
{
	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			if (cell[y][x])
			{
				Rect(CELLSIZE*Point(x, y), CELLSIZE).draw(Palette::Wheat);
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
			cell[y][x] = csv.get<int>(y, x) != 0;
		}
	}
}
