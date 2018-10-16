#include"SkillManager.h"

#include"TestSkill.h"
# include "Moglie.h"
# include "AppleBattle.h"
# include "CrashBreak.h"


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
		if (v < _rate[i])
		{
			for (size_t j = 0; j < _rate.size(); ++j)
			{
				if (i == j) { _rate[j] = 0; }

				else { _rate[j]++; }
			}

			return _skillKeyList[i];
		}

		v -= _rate[i];
	}

	Println(L"error > getKeyRandom‚Å³‚µ‚­ˆ—‚Å‚«‚Ü‚¹‚ñ‚Å‚µ‚½B");

	return _skillKeyList[Random<int>(0, _skillKeyList.size() - 1)];
}


void GameData::SkillManager::setAllSkill()
{
#ifdef _DEBUG

	//setSkill<Skill::TestSkill1>(L"TestSkill1");
	//setSkill<Skill::TestSkill2>(L"TestSkill2");
	//setSkill<Skill::TestSkill3>(L"TestSkill3");
	//setSkill<Skill::TestSkill4>(L"TestSkill4");
	//setSkill<Skill::TestSkill5>(L"TestSkill5");
	//setSkill<Skill::TestSkill6>(L"TestSkill6");]

	setSkill<Skill::AppleBattle>(L"Apple");
//	setSkill<Skill::Moglie>(L"Moglie");
	setSkill<Skill::CrashBreak>(L"CrashBreak");

#endif // _DEBUG
}
