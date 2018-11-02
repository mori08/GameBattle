#include "Panicn.h"


void GameObject::Panicn::update()
{
	++_time;

	if (_time == _endTime) { _eraseFlag = true; }

	_velocity.y = 0.5f*Sin(_time*0.01f + _geta);

	moveObject(false);
}


void GameObject::Panicn::draw() const
{
	(
	_velocity.x < 0 ?
	TextureAsset(_colorId) : TextureAsset(_colorId).mirror()
	) .scale(0.07).drawAt(_pos);
}
