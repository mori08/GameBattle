#include<Siv3D.hpp>
#include"StageData.h"

void Main()
{
	Window::Resize(960, 540);

	while (System::Update())
	{
		GameData::StageData::Instance().draw();
	}
}