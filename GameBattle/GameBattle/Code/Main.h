#pragma once


#include<Siv3D.hpp>
#include<HamFramework.hpp>


struct ShareData
{
	bool _bgm = true;
	double _scl = 2;
	Array<int> _scoreList;
};


using MyApp = SceneManager<String, ShareData>;