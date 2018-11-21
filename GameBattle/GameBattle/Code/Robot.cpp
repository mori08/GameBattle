# include "Robot.h"
# include "Bullet.h"

GameObject::Robot::Robot(const Vec2 & pos, const Vec2 & vel, int id)
{
	_pos = pos;
	_savedVel = vel;
	_velocity = vel;
	_id = id;
	_size = Size(60, 60);
	_tagData = makeTagData(L"Attack[" + ToString(id) + L"]");
	_time = 0;

	_direction = (_velocity.x >= 0) ? 1 : -1;
}

void GameObject::Robot::update()
{
	_time++;

	if (_time % 20 == 0 && _time % 80 != 0)
	{
		const Vec2 vel = Vec2(_direction * 10, 0);
		_generator->push(std::make_unique<Bullet>(_pos, vel, _id));
	}


	if (isLanding())
	{
		_velocity.x = _savedVel.x;
		_velocity.y = 0;
	}
	else
	{
		_velocity.x = 0;
		_velocity.y += 0.2;
	}

	moveObject(true);

	if (isTouchingWall() && isLanding())
	{
		_savedVel.x = -_savedVel.x;
		_direction = (_savedVel.x >= 0) ? 1 : -1;
	}
	
}


void GameObject::Robot::draw() const
{
	if (_direction == 1)
	{
		TextureAsset(Format(L"robot", _id+1)).resize(_size).mirror().drawAt(_pos);
	}

	else
	{
		TextureAsset(Format(L"robot", _id+1)).resize(_size).drawAt(_pos);
	}

//	getCollider().draw(Palette::Yellow);
}

bool GameObject::Robot::eraser() const
{
	return _time >= 300;
}


void GameObject::Robot::collisionUpdate(const GameData::TagData & tagData)
{
	for (const auto & tag : tagData)
	{
		if (tag.type == L"Player" && _id != ParseOr<int>(tag.info[0], -1))
		{
			_time = 600;
		}
		if (tag.type == L"Attack" && _id != ParseOr<int>(tag.info[0], -1))
		{
			_time = 600;
		}
	}
}


