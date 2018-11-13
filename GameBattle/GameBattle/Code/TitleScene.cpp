#include "TitleScene.h"
#include "InputManager.h"


void Scene::TitleScene::init()
{
	isStart = true;

	if (m_data->_bgm)
	{
		SoundAsset(L"title_bgm").setLoop(true);
		SoundAsset(L"title_bgm").play();
	}

	_panelNameList.emplace_back(L"Jihad1_title");
	_panelNameList.emplace_back(L"AppleBattle_title");
	_panelNameList.emplace_back(L"Moglie_title");
	_panelNameList.emplace_back(L"CrashBreak_title");

	_panelId = Random(100);
}


void Scene::TitleScene::update()
{
	if (Random(_panelNameList.size() * 50) == 0)
	{
		_panelId = (_panelId + 1) % _panelNameList.size();
		_panelList.emplace_back(Random(0.0, 960.0), Random(0.5, 1.0), _panelNameList[_panelId]);
	}

	for (auto & panel : _panelList)
	{
		panel.update();
	}

	Erase_if(_panelList, [](const Panel & p) { return p.eraser(); });

	std::sort(_panelList.begin(), _panelList.end());

	if (GameData::InputManager::get(0, GameData::Button::Two, GameData::InputType::Clicked))
	{
		if (isStart)
		{
			SoundAsset(L"title_bgm").stop(2.0s);
			changeScene(L"GameScene");
		}
		else
		{
			System::Exit();
		}
	}

	if (GameData::InputManager::get(0, GameData::Button::Up, GameData::InputType::Clicked)
		|| GameData::InputManager::get(0, GameData::Button::Down, GameData::InputType::Clicked))
	{
		isStart = !isStart;
	}
}


void Scene::TitleScene::draw() const
{
	Rect(0, 0, Window::BaseSize()).draw(Color(240, 240, 240));

	for(const auto & panel : _panelList)
	{
		panel.draw();
	}

	if (isStart) 
	{
		font(L"START").regionCenter(Window::BaseCenter() + Point(200, 0)).draw(Color(0, 0, 255, 128));
	}
	else
	{
		font(L"EXIT").regionCenter(Window::BaseCenter() + Point(200, 50)).draw(Color(0, 0, 255, 128));
	}
	
	TextureAsset(L"title_logo").scale(0.8).drawAt(Window::BaseCenter() + Point(-200, 0));

	font(L"START").drawAt(Window::BaseCenter() + Point(200, 0));
	font(L"EXIT").drawAt(Window::BaseCenter() + Point(200, 50));
}
