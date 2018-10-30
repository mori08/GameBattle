#include"Main.h"
#include"InputManager.h"
#include"SkillManager.h"
#include"GameScene.h"


void asseter(const String & direname);


void Main()
{
	Window::SetBaseSize(960, 480);
	Window::Resize(960, 540);

	asseter(L"Asset/");

	GameData::SkillManager::instance(); // ������

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


void asseter(const String & direname)
{
	// �w�肳�ꂽ�f�B���N�g���̃t�@�C���p�X��z���
	Array<FilePath> contents = FileSystem::DirectoryContents(direname);

	for (const auto& content : contents)
	{

		String filename = FileSystem::FileName(content);


		// �w�肳�ꂽ�p�X���f�B���N�g���ł���Ƃ�
		if (FileSystem::IsDirectory(content))
		{
			asseter(direname + filename + L"/"); // �֐����ĂьĂ�
		}


		// �w�肳�ꂽ�p�X���t�@�C���ł���Ƃ�
		else if (FileSystem::IsFile(content))
		{

			// �g���q��png�̂Ƃ�
			if (FileSystem::Extension(content) == L"png")
			{
				TextureAsset::Register(FileSystem::BaseName(content), direname + filename);
			}

			// �g���q��mp3�̂Ƃ�
			else if (FileSystem::Extension(content) == L"mp3")
			{
				SoundAsset::Register(FileSystem::BaseName(content), direname + filename);
			}

		}
	}
}