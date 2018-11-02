#include "Panicn.h"


void GameObject::Panicn::update()
{
	++_time;

	if (_time == _endTime) { _eraseFlag = true; }

	_velocity.y = Sin(_time*0.01f + _geta);

	moveObject(false);
}


void GameObject::Panicn::draw() const
{
	getCollider().draw();

	(
	_velocity.x < 0 ?
	TextureAsset(_colorId) : TextureAsset(_colorId).mirror()
	) .scale(0.07).drawAt(_pos);
}
