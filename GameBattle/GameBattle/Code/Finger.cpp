#include "Finger.h"


void GameObject::Finger::update()
{
	walking();
}


void GameObject::Finger::draw() const
{
	const Size SIZE(64, 96);

	getCollider().draw();

	TextureAsset(L"finger")(SIZE.x * ((_time % (5 * 10)) / 10), 0, SIZE).drawAt(_pos.asPoint() + Point(0, -15));
}
