#include<Siv3D.hpp>
#include"StageData.h"
#include"Player.h"

void Main()
{
	Window::Resize(960, 540);

	GameObject::Player test(1);

	while (System::Update())
	{
		GameData::StageData::Instance().draw();
		test.update();
		test.draw();
	}
}