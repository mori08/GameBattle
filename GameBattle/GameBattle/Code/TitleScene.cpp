#include "TitleScene.h"


void Scene::TitleScene::init()
{

}


void Scene::TitleScene::update()
{
	if (Input::KeySpace.clicked)
	{
		changeScene(L"GameScene");
	}
}


void Scene::TitleScene::draw() const
{
	font(L"START").draw(Window::Center());

	font(L"EXIT").draw(Window::Center() + Point(0, 20));
}
