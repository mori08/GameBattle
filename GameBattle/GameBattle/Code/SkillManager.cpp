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


String GameData::SkillManager::getKeyRamdom()
{
	int total = 0;

	for (const auto & r : _rate) { total += r; }

	int v = Random(0, total - 1);

	for (size_t i = 0; i < _rate.size(); ++i)
	{
		if (v < (int)_rate.size())
		{
			for (size_t j = 0; j < _rate.size(); ++j)
			{
				if (i == j) { _rate[i] = 0; }

				else { _rate[i]++; }
			}

			return _skillKeyList[i];
		}

		v -= _rate[i];
	}
}


void GameData::SkillManager::setAllSkill()
{
#ifdef _DEBUG

	setSkill<Skill::TestSkill1>(L"TestSkill1");
	
	setSkill<Skill::TestSkill2>(L"TestSkill2");

#endif // _DEBUG
}
