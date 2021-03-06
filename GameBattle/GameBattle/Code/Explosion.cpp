# include "Explosion.h"

GameObject::Explosion::Explosion(const Vec2 & pos, const Size& size,int id,int texId)
{
	_pos = pos;
	_velocity = Vec2(0, 0);
	_size = size;
	_tagData = makeTagData(L"Attack[" + ToString(id) + L"]");
	_time = 0;
	_id = id;
	_texId = texId;

}

void GameObject::Explosion::update()
{
	_time++;
}


void GameObject::Explosion::draw() const
{
	TextureAsset(Format(L"explosion",_texId))(160 * (_time / 10), 0, 160, 160).drawAt(getCollider().center.movedBy(0, -40));
}


bool GameObject::Explosion::eraser() const
{
	return _time >= 60;
}


void GameObject::Explosion::collisionUpdate(const GameData::TagData &)
{
/*	for (const auto & tag : tagData)
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
	*/
}

