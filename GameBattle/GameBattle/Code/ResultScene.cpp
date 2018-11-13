#include "ResultScene.h"


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

}


void Scene::ResultScene::draw() const
{
	Rect(0, 0, Window::BaseSize()).draw(Color(240, 240, 240));

	for (int i = 0; i < 4; ++i)
	{
		Point pos (110 + 200 * i, 180 + 60 * _rank[i]);
		Size  size(140, 180 + 60 * _rank[i]);

		Rect(pos, size).draw(_colorList[i]);

		TextureAsset(L"player_" + ToString(i))(0, 160, 128, 160).drawAt(pos + Point(70, -80));
	}
}
