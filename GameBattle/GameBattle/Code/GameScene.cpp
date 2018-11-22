#include"GameScene.h"
#include"GameCamera.h"
#include"StageData.h"
#include"InputManager.h"


using namespace GameData;


Scene::GameScene::GameScene()
{
	_time = 0;
}


void Scene::GameScene::init()
{
	_pause = false;
	_stopGame = false;

	if (m_data->_bgm)
	{
		SoundAsset(L"battle_bgm").setLoop(true);
		SoundAsset(L"battle_bgm").play();
	}

	GameData::GameCamera::Instance().init();
}


void Scene::GameScene::update()
{
	if (InputManager::get(0, Button::START, InputType::Clicked))
	{
		_pause = !_pause;
		_stopGame = false;
		if (_pause) { SoundAsset(L"poseOpen").play(); }
		else { SoundAsset(L"poseClose").play(); }
	}

	if(_pause)
	{

		if (InputManager::get(0, Button::Up, InputType::Clicked) || InputManager::get(0, Button::Down, InputType::Clicked))
		{
			_stopGame = !_stopGame;
		}

		if (InputManager::get(0, Button::Two, InputType::Clicked))
		{
			if (_stopGame)
			{
				SoundAsset(L"poseClose").play();
				changeScene(L"TitleScene");
				SoundAsset(L"battle_bgm").stop(2.0s);
			}
			else
			{
				SoundAsset(L"cursor").stop();
				SoundAsset(L"cursor").play();
				_pause = !_pause;
				_stopGame = false;
			}
		}

		return;
	}

	++_time;
	
	_gameObjectManager.update();

	GameData::GameCamera::Instance().update();

	if (_time >= 7200 || Input::KeySpace.clicked)
	{
		changeScene(L"ResultScene");
		SoundAsset(L"battle_bgm").stop(2.0s);

		m_data->_scoreList.clear();

		for (int i = 0; i < 4; ++i)
		{
			m_data->_scoreList.emplace_back(GameObject::GameObject::getPlayerScore(i));
		}
	}
}


void Scene::GameScene::draw() const
{
	{
		const auto t1 = GameData::GameCamera::Instance().createTransformer();

		GameData::StageData::Instance().draw();

		_gameObjectManager.draw();
	}

	{
		Graphics2D::SetTransform(Mat3x2::Scale(m_data->_scl, Point::Zero));

		GameObject::GameObject::drawPlayerBoard(m_data->_scl);

		if(_pause)
		{
			Rect(Point::Zero, Window::BaseCenter()).draw(Color(0, 128));

			if (!_stopGame)
			{
				font(L"‚Â‚Ã‚¯‚é").regionCenter(Window::BaseCenter() / 2 + Point(200, 0)).draw(Color(0, 0, 255, 128));
			}
			else
			{
				font(L"‚â‚ß‚é").regionCenter(Window::BaseCenter() / 2 + Point(200, 50)).draw(Color(0, 0, 255, 128));
			}

			font(L"‚Â‚Ã‚¯‚é").drawAt(Window::BaseCenter() / 2 + Point(200, 0));
			font(L"‚â‚ß‚é").drawAt(Window::BaseCenter() / 2 + Point(200, 50));
		}

		Graphics2D::SetTransform(Mat3x2::Scale(1, Point::Zero));
	}
}
