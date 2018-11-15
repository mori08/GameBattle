# include "Apple.h"

GameObject::Apple::Apple(const Vec2 & pos, const Vec2 & vel,int id)
{
	_pos = pos;
	_velocity = vel;
	_size = Size(30, 30);
	_tagData = makeTagData(L"Attack[" + ToString(id) + L"]");
	_time = 0;
	_id = id;
}

void GameObject::Apple::update()
{
	_time++;
	moveObject(true);
}


void GameObject::Apple::draw() const
{
	TextureAsset(L"apple").drawAt(_pos + Point(0, -20));
}


bool GameObject::Apple::eraser() const
{
	return _time >= 300 || isTouchingMap();
}


void GameObject::Apple::collisionUpdate(const GameData::TagData & tagData)
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

