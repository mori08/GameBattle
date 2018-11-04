#include "TitleScene.h"
#include "InputManager.h"

void Scene::TitleScene::init()
{
	isStart = true;
}


void Scene::TitleScene::update()
{
	if (GameData::InputManager::get(0, GameData::Button::Two, GameData::InputType::Clicked))
	{
		if (isStart)
		{
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
	if (isStart) 
	{
		font(L"START").region(Window::Center()).draw(Color(255, 255, 255, 128));
	}
	else
	{
		font(L"EXIT").region(Window::Center() + Point(0, 20)).draw(Color(255, 255, 255, 128));
	}
	font(L"START").draw(Window::Center());

	font(L"EXIT").draw(Window::Center() + Point(0, 20));
}
