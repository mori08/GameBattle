#pragma once


#include<Siv3D.hpp>


namespace GameData
{
	class PlayerBoard
	{
	private:

		using skill_data = std::pair<String, int>;

		int  _id;

		int  _score;

		Font _fontScore;
		Font _fontSkill;

		std::array<skill_data, 4> _skillDataList;

	public:

		PlayerBoard(int id);

		void addScore(int v);

		int getScore()const
		{
			return _score;
		}

		void setSkillData(int id, const String & name, int num);

		void draw(double scl)const;

	};
}