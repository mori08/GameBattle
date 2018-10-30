# include "Bomb.h"
# include "Bomber.h"


GameObject::Bomber::Bomber(const Vec2 & pos, const Vec2 & vel, int id)
{
	_pos = pos;
	_velocity = vel;
	_size = Size(80, 40);
	_tagData = makeTagData(L"Attack[" + ToString(id) + L"]");
	_time = 0;
	_id = id;
}

void GameObject::Bomber::update()
{
	_time++;
	moveObject(false);
	
	if (_time %10 == 0)
	{
		const Vec2 pos = _pos;
		const Vec2 vel = Vec2(0,7);
		_generator->push(std::make_unique<Bomb>(pos, vel, _id));
	}
}


void GameObject::Bomber::draw() const
{
	getCollider().draw(Palette::Yellow);
}


bool GameObject::Bomber::eraser() const
{
	return _time >= 300;
}


void GameObject::Bomber::collisionUpdate(const GameData::TagData & tagData)
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


//--------------------
