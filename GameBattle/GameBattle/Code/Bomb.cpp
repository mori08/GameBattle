# include "Explosion.h"
# include "Bomb.h"

GameObject::Bomb::Bomb(const Vec2 & pos, const Vec2 & vel, int id)
{
	_pos = pos;
	_velocity = vel;
	_size = Size(20, 20);
	_tagData = makeTagData(L"Attack[" + ToString(id) + L"]");
	_time = 0;
	_id = id;
}

void GameObject::Bomb::update()
{
	_time++;

	if (isTouchingMap())
	{
		_generator->push(std::make_unique<Explosion>(_pos, Vec2(0, 0), _id));
		return;
	}

	moveObject(true);
	
	if (isTouchingMap())
	{
		_generator->push(std::make_unique<Explosion>(_pos, Vec2(0, 0), _id));
		return;
	}

}


void GameObject::Bomb::draw() const
{
	TextureAsset(L"bomb").draw(getCollider().pos);
}


bool GameObject::Bomb::eraser() const
{
	return isTouchingMap() || _time >= 600;
}


void GameObject::Bomb::collisionUpdate(const GameData::TagData & tagData)
{
	for (const auto & tag : tagData)
	{
		if (tag.type == L"Player" && _id != ParseOr<int>(tag.info[0], -1))
		{
			_generator->push(std::make_unique<Explosion>(_pos, Vec2(0, 0), _id));
			_time = 600;
		}
		if (tag.type == L"Attack" && _id != ParseOr<int>(tag.info[0], -1))
		{
			_generator->push(std::make_unique<Explosion>(_pos, Vec2(0, 0), _id));
			_time = 600;
		}
	}
}

