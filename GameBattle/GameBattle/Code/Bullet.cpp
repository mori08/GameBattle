# include "Bullet.h"

GameObject::Bullet::Bullet(const Vec2 & pos, const Vec2 & vel, int id)
{
	_pos = pos;
	_velocity = vel;
	_id = id;
	_size = Size(48, 48);
	_tagData = makeTagData(L"Attack[" + ToString(id) + L"]");
	_time = 0;

}

void GameObject::Bullet::update()
{
	_time++;

	moveObject(true);

	if (isTouchingMap())
	{
		generateExplosion();
	}
}


void GameObject::Bullet::draw() const
{
	//getCollider().draw(Palette::Yellow);
	if (_velocity.x > 0)
	{
		TextureAsset(L"bullet")(16 * 2, 16 * 1, 16, 16).resize(_size).drawAt(_pos);
	}
	else
	{
		TextureAsset(L"bullet")(16 * 0, 16 * 1, 16, 16).resize(_size).drawAt(_pos);
	}

}

bool GameObject::Bullet::eraser() const
{
	return _time >= 100 || isTouchingMap();
}


void GameObject::Bullet::collisionUpdate(const GameData::TagData & tagData)
{
	for (const auto & tag : tagData)
	{
		if (tag.type == L"Player" && _id != ParseOr<int>(tag.info[0], -1))
		{
			_time = 600;
			generateExplosion();
		}
		if (tag.type == L"Attack" && _id != ParseOr<int>(tag.info[0], -1))
		{
			_time = 600;
			generateExplosion();
		}
	}
}


