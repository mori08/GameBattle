#pragma once


#include<Siv3D.hpp>


namespace GameData
{

	class InputManager
	{
	private:

	private:

		InputManager();

	public:

		InputManager(const InputManager&)            = delete;
		InputManager& operator=(const InputManager&) = delete;
		InputManager(InputManager&&)                 = delete;
		InputManager& operator=(InputManager&&)      = delete;

	public:

		static InputManager & Instance()
		{
			static InputManager instatnce;
			return instatnce;
		}

	public:



	};

}