
# include "SmallEyeBall.h"

GameObject::SmallEyeBall::SmallEyeBall(const Vec2 & pos, const Vec2 & vel,int id)
{
	_pos = pos;
	_velocity = vel;

	_texSize = Size(TextureAsset(L"eye").size.x / 3, TextureAsset(L"eye").size.y / 2) / 2;
	_size = Size(20,20);

	_tagData = makeTagData(L"Attack[" + ToString(id) + L"]");
	_time = 0;
	_id = id;
	_eraser = false;
}

void GameObject::SmallEyeBall::update()
{
	_velocity.y += 0.4;
	moveObject(true);

	if (isTouchingMap())
	{
		_eraser = true;
	}
}


void GameObject::SmallEyeBall::draw() const
{
	TextureAsset(L"eye")(0, 0, 128, 80).resize(_texSize).drawAt(_pos);
//	getCollider().draw(Palette::Yellow);
}


bool GameObject::SmallEyeBall::eraser() const
{
	return _eraser;
}


void GameObject::SmallEyeBall::collisionUpdate(const GameData::TagData & tagData)
{
	for (const auto & tag : tagData)
	{
		if (tag.type == L"Player" && _id != ParseOr<int>(tag.info[0], -1))
		{
			_eraser = true;
		}

		if (tag.type == L"Attack" && _id != ParseOr<int>(tag.info[0], -1))
		{
			_eraser = true;
		}
	}
}

