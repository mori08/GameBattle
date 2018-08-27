#include "StageData.h"
#include "SkillManager.h"
#include "Cassette.h"
#include "GameCamera.h"


using namespace GameData;


GameObject::Cassette::Cassette(const size_t & id)
{
	auto data = StageData::Instance().getCassettePos(id);

	_id        = data.second;
	_skillKey  = SkillManager::instance().getKeyRamdom();
	_eraseFlag = false;

	_pos      = data.first;
	_size     = Size(30, 30);
	_velocity = Vec2(0, -1);
	_tagData  = makeTagData(L"Cassette[" + _skillKey + L"]");
}


void GameObject::Cassette::update()
{
	_velocity.y += 0.02;

	moveObject(true);
}


void GameObject::Cassette::draw() const
{
	getCollider().draw(Palette::Aqua);
}


bool GameObject::Cassette::eraser() const
{
	return _eraseFlag;
}


void GameObject::Cassette::collisionUpdate(const GameData::TagData & tag)
{
	for(const auto & t : tag)
	{
		if (t.type == L"GetSkill")
		{
			_eraseFlag = true;

			_generator->push(std::make_unique<Cassette>(_id));
		}
	}
}
