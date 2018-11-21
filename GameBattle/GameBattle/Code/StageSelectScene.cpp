#include "StageSelectScene.h"
#include "InputManager.h"
#include "StageData.h"


using namespace GameData;


namespace
{
	const double CURSOR_SPEED = 4;
	const double RATE = 0.9;
	const double RADIUS = 20;
}


void Scene::StageSelectScene::SelectCursor::update()
{
	Vec2 v = Vec2::Zero;

	if (InputManager::get(_id, Button::Up, InputType::Pressed))
	{
		v.y -= CURSOR_SPEED;
	}

	if (InputManager::get(_id, Button::Down, InputType::Pressed))
	{
		v.y += CURSOR_SPEED;
	}

	if (InputManager::get(_id, Button::Left, InputType::Pressed))
	{
		v.x -= CURSOR_SPEED;
	}

	if (InputManager::get(_id, Button::Right, InputType::Pressed))
	{
		v.x += CURSOR_SPEED;
	}

	_pos += v;

	if (_pos.x < 0) { _pos.x = 0; }
	if (_pos.x > Window::BaseCenter().x) { _pos.x = Window::BaseCenter().x; }
	if (_pos.y < 0) { _pos.y = 0; }
	if (_pos.y > Window::BaseCenter().y) { _pos.y = Window::BaseCenter().y; }
}


void Scene::StageSelectScene::SelectCursor::draw() const
{
	Circle(_pos, RADIUS).draw(_color).drawFrame(1, 1, Palette::Black);
}


Circle Scene::StageSelectScene::SelectCursor::getPos() const
{
	return Circle(_pos, RADIUS);
}



Scene::StageSelectScene::StageSelectScene()
{
	for (int i = 0; i < 4; ++i)
	{
		_cursorList.emplace_back(i);
	}

	Size stageTextureSize(320, 160);

	_stageList.emplace_back(StageButton(L"stage_yusha", Rect(Point(  0, 0), stageTextureSize)));
	_stageList.emplace_back(StageButton(L"stage_boei" , Rect(Point(320, 0), stageTextureSize)));
}


void Scene::StageSelectScene::init()
{

}


void Scene::StageSelectScene::update()
{
	/*
	SoundAsset(L"title_bgm").stop(2.0s);
	GameData::StageData::Instance().read(L"stage_boei");
	changeScene(L"GameScene");
	*/

	for (int i = 0; i < 4; ++i)
	{
		_cursorList[i].update();

		if (InputManager::get(i, Button::Two, InputType::Clicked))
		{
			for (const auto & stage : _stageList)
			{
				if (stage.Region.contains(_cursorList[i].getPos()))
				{

					SoundAsset(L"title_bgm").stop(2.0s);
					GameData::StageData::Instance().read(stage.Name);
					changeScene(L"GameScene");

				}
			}
		}
	}
}


void Scene::StageSelectScene::draw() const
{
	Rect(0, 0, Window::BaseCenter()).draw(Color(240, 240, 240));

	for (const auto & stage : _stageList)
	{
		TextureAsset(stage.Name)
			.scale(stage.Region.w / 960.0)
			.draw(stage.Region.tl);
	}

	for (const auto & cursor : _cursorList)
	{
		cursor.draw();
	}
}
