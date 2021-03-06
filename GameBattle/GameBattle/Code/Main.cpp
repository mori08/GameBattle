#include"Main.h"
#include"InputManager.h"
#include"SkillManager.h"

#include"GameScene.h"
#include"TitleScene.h"
#include"StageSelectScene.h"
#include"ResultScene.h"


void asseter(const String & direname);


void Main()
{
	double scl = 2;

	//Window::Resize(Size(960 * scl, 480 * scl));
	Window::SetFullscreen(true, Size(1920, 1080));
	Window::SetBaseSize(Size(1920, 1080));

	asseter(L"Asset/");

	GameData::SkillManager::instance(); // 初期化

	MyApp sceneManager;

	sceneManager.add<Scene::TitleScene>(L"TitleScene");
	sceneManager.add<Scene::StageSelectScene>(L"StageSelectScene");
	sceneManager.add<Scene::GameScene>(L"GameScene");
	sceneManager.add<Scene::ResultScene>(L"ResultScene");

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


void asseter(const String & direname)
{
	// 指定されたディレクトリのファイルパスを配列に
	Array<FilePath> contents = FileSystem::DirectoryContents(direname);

	for (const auto& content : contents)
	{

		String filename = FileSystem::FileName(content);


		// 指定されたパスがディレクトリであるとき
		if (FileSystem::IsDirectory(content))
		{
			asseter(direname + filename + L"/"); // 関数を再び呼ぶ
		}


		// 指定されたパスがファイルであるとき
		else if (FileSystem::IsFile(content))
		{

			// 拡張子がpngのとき
			if (FileSystem::Extension(content) == L"png")
			{
				TextureAsset::Register(FileSystem::BaseName(content), direname + filename);
			}

			// 拡張子がmp3のとき
			else if (FileSystem::Extension(content) == L"mp3")
			{
				SoundAsset::Register(FileSystem::BaseName(content), direname + filename);
			}

		}
	}
}