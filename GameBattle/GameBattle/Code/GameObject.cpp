#include "GameObject.h"


void GmaeObject::GameObject::collisionCheck(const std::unique_ptr<GameObject>& obj)
{
	if (getCollider().intersects(obj->getCollider()))
	{
		obj->collisionUpdate(_tag);
	}
}


void GmaeObject::GameObject::moveObject(bool useMapData)
{
	if (!useMapData)
	{
		_pos += _velocity;

		return;
	}

	// MapData‚ªŠ®¬‚µ‚½‚çÀ‘•
}
