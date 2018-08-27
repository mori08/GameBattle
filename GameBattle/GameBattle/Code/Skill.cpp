#include "Skill.h"


GameData::TagData Skill::Skill::NoneTag;

Array<GameData::TagData> Skill::Skill::AttackTag;


void Skill::Skill::setTagData()
{
	AttackTag.clear();
	AttackTag.emplace_back(GameObject::GameObject::makeTagData(L"Attack[0]"));
	AttackTag.emplace_back(GameObject::GameObject::makeTagData(L"Attack[1]"));
	AttackTag.emplace_back(GameObject::GameObject::makeTagData(L"Attack[2]"));
	AttackTag.emplace_back(GameObject::GameObject::makeTagData(L"Attack[3]"));
}
