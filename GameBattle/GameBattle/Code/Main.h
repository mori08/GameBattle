#pragma once


#include<Siv3D.hpp>
#include<HamFramework.hpp>


struct ShareData
{
	bool _bgm = false;
	Array<int> _scoreList;
};


using MyApp = SceneManager<String, ShareData>;