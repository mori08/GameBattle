# include "Bullet.h"
# include "Explosion.h"

GameObject::Bullet::Bullet(const Vec2 & pos, const Vec2 & vel, int id)
{
	_pos = pos;
	_velocity = vel;
	_id = id;
	_size = Size(15, 15);
	_tagData = makeTagData(L"Attack[" + ToString(id) + L"]");
	_time = 0;

}

void GameObject::Bullet::update()
{
	_time++;

	moveObject(true);

	if (isTouchingMap())
	{
		_generator->push(std::make_unique<Explosion>(_pos, Size(0, 0), _id, 2));
	}
}


void GameObject::Bullet::draw() const
{
	getCollider().draw(Palette::Yellow);
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
			_generator->push(std::make_unique<Explosion>(_pos, Size(0, 0), _id, 2));
		}
		if (tag.type == L"Attack" && _id != ParseOr<int>(tag.info[0], -1))
		{
			_time = 600;
			_generator->push(std::make_unique<Explosion>(_pos, Size(0, 0), _id, 2));
		}
	}
}


