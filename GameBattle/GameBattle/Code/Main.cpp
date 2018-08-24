#include<Siv3D.hpp>
#include"StageData.h"
#include"GameCamera.h"
#include"GameObjectManager.h"

void Main()
{
	Window::SetBaseSize(960, 480);
	Window::Resize(960, 540);
	
	GameData::GameObjectManager gameObject;

	while (System::Update())
	{
		//ClearPrint();
		
		gameObject.update();

		GameData::GameCamera::Instance().update();

		const auto t1 = GameData::GameCamera::Instance().createTransformer();
		{
			GameData::StageData::Instance().draw();
			gameObject.draw();
		}
	}
}