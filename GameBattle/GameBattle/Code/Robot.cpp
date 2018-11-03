# include "Robot.h"

GameObject::Robot::Robot(const Vec2 & pos, const Vec2 & vel, int id)
{
	_pos = pos;
	_savedVel = vel;
	_velocity = vel;
	_id = id;
	_size = Size(80, 80);
	_tagData = makeTagData(L"Attack[" + ToString(id) + L"]");
	_time = 0;

	_direction = (_velocity.x >= 0) ? 1 : -1;
}

void GameObject::Robot::update()
{
	_time++;
	
	PutText(_velocity).at(500, 0);

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

	if (isTouchingWall())
	{
		_savedVel.x = -_savedVel.x;
		_direction = (_savedVel.x >= 0) ? 1 : -1;
	}
	
}


void GameObject::Robot::draw() const
{
	if (_direction == 1)
	{
		TextureAsset(L"robot").resize(_size).mirror().drawAt(_pos);
	}

	else
	{
		TextureAsset(L"robot").resize(_size).drawAt(_pos);
	}
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


