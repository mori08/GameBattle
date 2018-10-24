#include "Finger.h"


void GameObject::Finger::update()
{
	walking();
}


void GameObject::Finger::draw() const
{
	getCollider().draw();
}
