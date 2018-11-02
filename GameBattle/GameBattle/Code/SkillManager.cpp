#include"SkillManager.h"

#include"TestSkill.h"

#include"Jihad1.h"

#include"ColorPanic.h"


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
	if (_skillKeyList.empty()) return L"";

	if (_skillKeyList.size() == 1) return _skillKeyList[0];

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

	Println(L"error > getKeyRandomで正しく処理できませんでした。");

	return _skillKeyList[Random<int>(0, (int)_skillKeyList.size() - 1)];
}


void GameData::SkillManager::setAllSkill()
{
#ifdef _DEBUG
	/*
	setSkill<Skill::TestSkill1>(L"TestSkill1");
	
	setSkill<Skill::TestSkill2>(L"TestSkill2");

	setSkill<Skill::TestSkill3>(L"TestSkill3");

	setSkill<Skill::TestSkill4>(L"TestSkill4");
	*/
	setSkill<Skill::Jihad1>(L"Jihad1");

	setSkill<Skill::ColorPanic>(L"ColorPanic");

#endif // _DEBUG
}
