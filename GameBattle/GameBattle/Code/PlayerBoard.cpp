#include "PlayerBoard.h"


GameData::PlayerBoard::PlayerBoard(int id)
	: _score(0)
	, _id(id)
	, _fontScore(25, L"游ゴシック Medium")
	, _fontSkill(10, L"游ゴシック Medium")
{
	for (int i = 0; i < 4; ++i)
	{
		_skillDataList[i].first  = L"";
		_skillDataList[i].second = 0;
	}
}


void GameData::PlayerBoard::addScore(int v)
{
	_score += v;
	if (_score < 0) _score = 0;
}


void GameData::PlayerBoard::setSkillData(int id, const String & name, int num)
{
	_skillDataList[id].first  = name;
	_skillDataList[id].second = num;
}


void GameData::PlayerBoard::draw() const
{
	Point pos = Point((_id + 0.5) * 960 / 4, 50);

	TextureAsset(L"PlayerBoard_" + ToString(_id)).scale(0.7).drawAt(pos);
	
	_fontScore(_score).drawAt(pos + Point(-70, 3), Palette::Black);

	for (int i = 0; i < 4; ++i)
	{
		_fontSkill(_skillDataList[i].first)
			.draw(pos + Point((i == 0 || i == 3) ? 5 : 15, -42 + i * 22), Palette::Black);
	}
}
