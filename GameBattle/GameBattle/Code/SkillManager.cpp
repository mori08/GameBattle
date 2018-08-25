#include "SkillManager.h"


GameData::SkillManager::skill_ptr GameData::SkillManager::getSkill(const String & key) const
{
	auto itr = _skillMap.find(key);

	if (itr != _skillMap.end())
	{
		return itr->second;
	}

	return nullptr;
}
