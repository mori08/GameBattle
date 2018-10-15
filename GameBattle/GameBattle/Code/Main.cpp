#include"Main.h"
#include"InputManager.h"
#include"SkillManager.h"
#include"GameScene.h"


void Main()
{
	Window::SetBaseSize(960, 480);
	Window::Resize(960, 540);

	GameData::SkillManager::instance(); // ‰Šú‰»

	MyApp sceneManager;

	sceneManager.add<Scene::GameScene>(L"GameScene");

	while (System::Update())
	{
		ClearPrint();
		
		sceneManager.updateAndDraw();

#ifdef _DEBUG
		Println(Profiler::FPS(), L"FPS");
		GameData::InputManager::test();
#endif // _DEBUG

		GameData::InputManager::updatePreVec();
	}
}