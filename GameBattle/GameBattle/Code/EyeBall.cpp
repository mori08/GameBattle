# include "EyeBall.h"
# include "SmallEyeBall.h"

GameObject::EyeBall::EyeBall(const Vec2 & pos, const Vec2 & vel, int id)
{
	_pos = pos;
	_velocity = vel;
	_texSize = Size(TextureAsset(L"eye").size.x / 3 / 1.5, TextureAsset(L"eye").size.y / 2 / 1.5);
	_size = Size(30, 30);
	_tagData = makeTagData(L"Attack[" + ToString(id) + L"]");
	_time = 0;
	_id = id;
}

void GameObject::EyeBall::update()
{
	if (_bombed)
	{
		_time++;
		return;
	}

	_velocity.y += 0.4;	
	moveObject(true);

	if (isTouchingMap() && !_bombed)
	{
		generateSmallEyeBalls();
		_bombed = true;
	}
}


void GameObject::EyeBall::draw() const
{
	if (_time >= ANIMENDTIME) 
	{
		TextureAsset(L"eye")(128 * 2, 80 * 1, 128, 80).resize(_texSize).drawAt(_pos);
		return; 
	}

//	getCollider().draw(Palette::Yellow);
	TextureAsset(L"eye")(128 * ((_time % (ANIMENDTIME / 2)) / (ANIMENDTIME / 6)), 80 * (_time / (ANIMENDTIME / 2)), 128, 80).resize(_texSize).drawAt(_pos);
	//getCollider().draw(Palette::Yellow);

}


bool GameObject::EyeBall::eraser() const
{
	return _bombed && _time >= ENDTIME;
}


void GameObject::EyeBall::collisionUpdate(const GameData::TagData & tagData)
{
	for (const auto & tag : tagData)
	{
		if (tag.type == L"Player" && _id != ParseOr<int>(tag.info[0], -1))
		{
			_bombed = true;
			generateSmallEyeBalls();
		}

		if (tag.type == L"Attack" && _id != ParseOr<int>(tag.info[0], -1))
		{
			_bombed = true;
			generateSmallEyeBalls();
		}
	}
}

void GameObject::EyeBall::generateSmallEyeBalls()
{
	if (_bombed) { return; }

	_generator->push(std::make_unique<SmallEyeBall>(_pos, Vec2(-15, -10), _id));
	_generator->push(std::make_unique<SmallEyeBall>(_pos, Vec2(-10, -10), _id));
	_generator->push(std::make_unique<SmallEyeBall>(_pos, Vec2(-6, -10), _id));
	_generator->push(std::make_unique<SmallEyeBall>(_pos, Vec2(6, -10), _id));
	_generator->push(std::make_unique<SmallEyeBall>(_pos, Vec2(10, -10), _id));
	_generator->push(std::make_unique<SmallEyeBall>(_pos, Vec2(15, -10), _id));
}

