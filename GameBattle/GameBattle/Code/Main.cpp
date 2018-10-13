#include<Siv3D.hpp>
#include"StageData.h"
#include"GameCamera.h"
#include"GameObjectManager.h"
#include"InputManager.h"
#include"SkillManager.h"

void Main()
{
	Window::SetBaseSize(960, 480);
	Window::Resize(960, 540);
	
	GameData::GameObjectManager gameObject;
	GameData::SkillManager::instance(); // èâä˙âª

	Texture texture(L"Asset/Texture/back2.png");

	while (System::Update())
	{
		ClearPrint();
		
#ifdef _DEBUG
		Println(Profiler::FPS(), L"FPS");
#endif // _DEBUG


		gameObject.update();

		GameData::GameCamera::Instance().update();

		{
			const auto t1 = GameData::GameCamera::Instance().createTransformer();

			texture.draw();

			GameData::StageData::Instance().draw();
			gameObject.draw();
		}

		GameData::InputManager::test();
		GameData::InputManager::updatePreVec();
	}
}