# include "Mine.h"
# include "Explosion.h"

GameObject::Mine::Mine(const Vec2 & pos, const Vec2 & vel, int id)
{
	_pos = pos;
	_velocity = vel;
	_id = id;
	_size = Size(20, 20);
	_tagData = makeTagData(L"Attack[" + ToString(id) + L"]");
	_time = 0;
}

void GameObject::Mine::update()
{
	_time++;
	
	if (Abs(_velocity.x) >= 0.1)
	{
		_velocity.x -= 0.5*getDirection();
	}
	
	moveObject(true);

	if (_time == 300)
	{
		_generator->push(std::make_unique<Explosion>(_pos, Vec2(0, 0), _id, 2));
	}


}


void GameObject::Mine::draw() const
{
	getCollider().draw(Palette::Yellow);
}

bool GameObject::Mine::eraser() const
{
	return _time >= 300;
}


void GameObject::Mine::collisionUpdate(const GameData::TagData & tagData)
{
	for (const auto & tag : tagData)
	{
		if (tag.type == L"Player" && _id != ParseOr<int>(tag.info[0], -1))
		{
			_time = 600;
			_generator->push(std::make_unique<Explosion>(_pos, Vec2(0, 0), _id,2));
		}
		if (tag.type == L"Attack" && _id != ParseOr<int>(tag.info[0], -1))
		{
			_time = 600;
			_generator->push(std::make_unique<Explosion>(_pos, Vec2(0, 0), _id,2));
		}
	}
}

