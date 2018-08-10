#include<Siv3D.hpp>
#include"StageData.h"
#include"GameCamera.h"
#include"Player.h"

void Main()
{
	Window::SetBaseSize(960, 480);
	Window::Resize(960, 540);
	GameObject::Player test0(0);
	GameObject::Player test1(1);

	while (System::Update())
	{
		ClearPrint();
		
		test0.update();
		test1.update();

		GameData::GameCamera::Instance().update();

		const auto t1 = GameData::GameCamera::Instance().createTransformer();
		{
			GameData::StageData::Instance().draw();
			test0.draw();
			test1.draw();
		}
	}
}