#include "ResultScene.h"

#include "InputManager.h"


Scene::ResultScene::ResultScene()
	: _rank(4)
{

}


void Scene::ResultScene::init()
{
	for (int i = 0; i < m_data->_scoreList.size(); ++i)
	{
		_rank[i] = 1;

		for (int j = 0; j < i; ++j)
		{
			if (m_data->_scoreList[i] < m_data->_scoreList[j])
			{
				++_rank[i];
			}

			if (m_data->_scoreList[i] > m_data->_scoreList[j])
			{
				++_rank[j];
			}
		}
	}

	_colorList.emplace_back(Palette::Red);
	_colorList.emplace_back(Palette::Blue);
	_colorList.emplace_back(Palette::Yellow);
	_colorList.emplace_back(Palette::Green);
}


void Scene::ResultScene::update()
{
	++_time;

	if (_time > 300)
	{
		if (
			GameData::InputManager::get(0, GameData::Button::Two, GameData::InputType::Clicked)
			||
			GameData::InputManager::get(1, GameData::Button::Two, GameData::InputType::Clicked)
			||
			GameData::InputManager::get(2, GameData::Button::Two, GameData::InputType::Clicked)
			||
			GameData::InputManager::get(3, GameData::Button::Two, GameData::InputType::Clicked)
			)
		{
			changeScene(L"TitleScene");
		}
	}
}


void Scene::ResultScene::draw() const
{
	Graphics2D::SetTransform(Mat3x2::Scale(m_data->_scl, Point::Zero));

	Rect(0, 0, Window::BaseSize()).draw(Color(240, 240, 240));

	for (int i = 0; i < 4; ++i)
	{
		Point pos (110 + 200 * i, 240 + 60 * _rank[i]);
		Size  size(140, 180 + 60 * _rank[i]);

		Rect(pos, size).draw(_colorList[i]);

		TextureAsset(L"player_" + ToString(i))(0, 160, 128, 160).drawAt(pos + Point(70, -80));
	}
}
