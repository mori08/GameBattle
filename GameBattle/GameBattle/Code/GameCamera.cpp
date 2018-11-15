#include "GameCamera.h"
#include "StageData.h"


void GameData::GameCamera::setPlayerPos(const Point & pos)
{
	if (_reset)
	{
		_posTL = pos;
		_posBR = pos;

		_reset = false;

		return;
	}

	if (pos.x < _posTL.x) { _posTL.x = pos.x; }
	if (pos.x > _posBR.x) { _posBR.x = pos.x; }
	if (pos.y < _posTL.y) { _posTL.y = pos.y; }
	if (pos.y > _posBR.y) { _posBR.y = pos.y; }
}


void GameData::GameCamera::update()
{
	_reset = true;

	Point pos = (_posTL + _posBR) / 2;
	Size  size = _posBR - _posTL + 400 * Size(2, 1);

	const Size MIN_SIZE = 300 * Size(2, 1); // Å¬ƒTƒCƒY

	if (size.x > StageData::Instance().getSize().x || size.y > StageData::Instance().getSize().y)
	{
		size = StageData::Instance().getSize();
	}
	
	if ((double)size.x > _raito*size.y) { size.y = (int)(size.x / _raito); }
	else { size.x = (int)(_raito*size.y); }

	if (pos.x - size.x / 2 < 0)
	{
		pos.x = size.x / 2;
	}
	if (pos.x + size.x / 2 > StageData::Instance().getSize().x)
	{
		pos.x = StageData::Instance().getSize().x - size.x / 2;
	}
	if (pos.y - size.y / 2 < 0)
	{
		pos.y = size.y / 2;
	}
	if (pos.y + size.y / 2 > StageData::Instance().getSize().y)
	{
		pos.y = StageData::Instance().getSize().y - size.y / 2;
	}

	double scl = 1.0*Window::BaseSize().x / size.x;
	
	_lerpRatio = 0.02;// s3d::Math::Lerp(_lerpRatio, 0.01, 0.02);

	m_pos.x = s3d::Math::Lerp(m_pos.x, pos.x, 0.05);
	m_pos.y = s3d::Math::Lerp(m_pos.y, pos.y, 0.01);
	m_scale = s3d::Math::Lerp(m_scale, scl, 0.05);

	setPos(m_pos);
	setScale(m_scale);

	pos = getPos().asPoint();
	size = (getScale()*Window::BaseSize()).asPoint();
}
