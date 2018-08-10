#include<Siv3D.hpp>
#include"StageData.h"
#include"GameCamera.h"
#include"Player.h"

void Main()
{
	Window::SetBaseSize(960, 480);
	Window::Resize(960, 540);
	GameObject::Player test(1);

	while (System::Update())
	{
		ClearPrint();
		
		test.update();
		GameData::GameCamera::Instance().update();

		const auto t1 = GameData::GameCamera::Instance().createTransformer();
		{
			GameData::StageData::Instance().draw();
			test.draw();
		}
	}
}