#include<Siv3D.hpp>
#include"StageData.h"
#include"TestObject.h"

void Main()
{
	Window::Resize(960, 540);

	GameObject::TestObject test;

	while (System::Update())
	{
		GameData::StageData::Instance().draw();
		test.update();
		test.draw();
	}
}