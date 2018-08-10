#include "GameCamera.h"
#include "StageData.h"


void GameData::GameCamera::setPlayerPos(const Point & pos)
{
	if (_reset)
	{
		_posTL = pos;
		_posBR = pos;

		return;
	}

	if (pos.x < _posTL.x) { _posTL.x = pos.x; }
	if (pos.x > _posBR.x) { _posBR.x = pos.x; }
	if (pos.y < _posTL.y) { _posTL.y = pos.y; }
	if (pos.y > _posBR.y) { _posBR.y = pos.y; }
}


void GameData::GameCamera::update()
{
	Point pos = (_posTL + _posBR) / 2;
	Size  size = _posTL - _posBR;

	const Size MIN_SIZE = Size(200, 100); // ç≈è¨ÉTÉCÉY

	if (size.x < MIN_SIZE.x && size.y < MIN_SIZE.y) { size = MIN_SIZE; }
	else if ((double)size.x > _raito*size.y) { size.y = size.x / _raito; }
	else { size.x = _raito*size.y; }

	if (pos.x - size.x / 2 < 0) 
	{
		pos.x = size.x; 
	}
	if (pos.x + size.x / 2 > StageData::Instance().getSize().x) 
	{
		pos.x = StageData::Instance().getSize().x - size.x / 2;
	}
	if (pos.y - size.y < 0)
	{
		pos.y = size.y;
	}
	if (pos.y + size.y / 2 > StageData::Instance().getSize().y)
	{
		pos.y = StageData::Instance().getSize().y - size.y / 2;
	}

	setTargetPos(pos);
	setTargetScale(size.x / StageData::Instance().getSize().x);

	Camera2D::update();
}
