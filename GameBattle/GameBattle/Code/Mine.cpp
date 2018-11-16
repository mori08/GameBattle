# include "Mine.h"

GameObject::Mine::Mine(const Vec2 & pos, const Vec2 & vel, int id)
{
	_pos = pos;
	_velocity = vel;
	_id = id;
	_size = Size(TextureAsset(L"MT1").size.x / 4, TextureAsset(L"MT1").size.y);
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
		generateExplosion();
	}


}


void GameObject::Mine::draw() const
{
	//getCollider().draw(Palette::Yellow);
	TextureAsset(Format(L"MT", (_id + 1)))(_size.x*((_time % 40)/10), 0, _size).drawAt(getCollider().center);
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
			generateExplosion();
		}
		if (tag.type == L"Attack" && _id != ParseOr<int>(tag.info[0], -1))
		{
			_time = 600;
			generateExplosion();
		}
	}
}


