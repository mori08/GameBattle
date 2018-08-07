#include "GameObject.h"


void GmaeObject::GameObject::collisionCheck(const std::unique_ptr<GameObject>& obj)
{
	if (getCollider().intersects(obj->getCollider()))
	{
		obj->collisionUpdate(_tag);
	}
}
