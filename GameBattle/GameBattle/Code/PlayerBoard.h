#pragma once


#include<Siv3D.hpp>


namespace GameData
{
	class PlayerBoard
	{
	private:

		int _score;

	public:

		void addScore(int v);

		void draw()const;

	};
}