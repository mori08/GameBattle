#include "PlayerBoard.h"


void GameData::PlayerBoard::addScore(int v)
{
	_score += v;
	if (_score < 0) _score = 0;
}


void GameData::PlayerBoard::draw() const
{
	
}
