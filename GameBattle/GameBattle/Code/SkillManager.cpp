#include"SkillManager.h"

#include"TestSkill.h"


GameData::SkillManager::SkillManager()
{
	setAllSkill();
}


GameData::SkillManager::skill_ptr GameData::SkillManager::getSkill(const String & key) const
{
	auto itr = _skillMap.find(key);

	if (itr != _skillMap.end())
	{
		return itr->second;
	}

	return nullptr;
}


void GameData::SkillManager::setAllSkill()
{
#ifdef _DEBUG

	setSkill<Skill::TestSkill1>(L"TestSkill1");
	
	setSkill<Skill::TestSkill2>(L"TestSkill2");

#endif // _DEBUG
}
