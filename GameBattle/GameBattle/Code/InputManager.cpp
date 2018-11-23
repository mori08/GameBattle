#include "InputManager.h"


bool GameData::InputManager::get(int id, const Button & button, const InputType & inputType)
{
	if (id < 0 || id >= PLAYER_NUM)
	{
#ifdef _DEBUG
		Println(L"error > InputManager‚É—^‚¦‚ç‚ê‚½id‚ª•s“KØ‚Å‚·");
#endif // _DEBUG

		return keyInput(button, inputType);
	}

	if (Gamepad(id).isConnected())
	{
		return Instatnce(id).padInput(Gamepad(id), button, inputType);
	}

	return keyInput(button, inputType);
}


bool GameData::InputManager::get(int id, int buttonId, const InputType & inputType)
{
	switch (buttonId)
	{
	case 0: return get(id, Button::One  , inputType);

	case 1: return get(id, Button::Two  , inputType);
	
	case 2: return get(id, Button::Three, inputType);
	
	case 3: return get(id, Button::Four , inputType);
	}

	return false;
}

void GameData::InputManager::updatePreVec()
{
	for (int i = 0; i < PLAYER_NUM; ++i)
	{
		if (Gamepad(i).isConnected())
		{
			Instatnce(i).preVec = Vec2(Gamepad(i).x, Gamepad(i).y);
		}
	}
}


bool GameData::InputManager::keyInput(const Button & button, const InputType & inputType)
{
	Key key;

	switch(button)
	{
	case Button::Left:  key = Input::KeyA;         break;

	case Button::Right: key = Input::KeyD;         break;

	case Button::Up:    key = Input::KeyW;         break;

	case Button::Down:  key = Input::KeyS;         break;

	case Button::One:   key = Input::KeyO;         break;
		
	case Button::Two:   key = Input::KeySemicolon; break;

	case Button::Three: key = Input::KeyL;         break;

	case Button::Four:  key = Input::KeyK;         break;

	default: return false;
	}

	switch (inputType)
	{
	case InputType::Clicked:  return key.clicked;

	case InputType::Pressed:  return key.pressed;

	case InputType::Released: return key.released;
	}

	return false;
}


bool GameData::InputManager::padInput(const Gamepad & pad, const Button & button, const InputType & inputType)
{
	Key key;

	switch (button)
	{
	case Button::Left:  key = pad.povLeft;     break;

	case Button::Right: key = pad.povRight;    break;

	case Button::Up:    key = pad.povForward;  break;

	case Button::Down:  key = pad.povBackward; break;

	case Button::One:   key = pad.button(0);   break;

	case Button::Two:   key = pad.button(1);   break;

	case Button::Three: key = pad.button(2);   break;

	case Button::Four:  key = pad.button(3);   break;

	case Button::START: key = pad.button(9);   break;

	default: return false;
	}

	bool analogFlag = false;

	switch(button)
	{
	case Button::Left:  analogFlag = analogInput(-pad.x, -preVec.x, inputType); break;

	case Button::Right: analogFlag = analogInput( pad.x,  preVec.x, inputType); break;
	
	case Button::Up:    analogFlag = analogInput(-pad.y, -preVec.y, inputType); break;
	
	case Button::Down:  analogFlag = analogInput( pad.y,  preVec.y, inputType); break;
	}

	switch (inputType)
	{
	case InputType::Clicked:  return key.clicked  || analogFlag;

	case InputType::Pressed:  return key.pressed  || analogFlag;

	case InputType::Released: return key.released || analogFlag;
	}

	return false;
	
}


bool GameData::InputManager::analogInput(double value, double preValue, InputType inputType)
{
	static const double BORDER = 0.99;

	bool input    = value    > BORDER;
	bool preInput = preValue > BORDER;

	switch (inputType)
	{
	case InputType::Pressed:  return  input;
	case InputType::Clicked:  return  input && !preInput;
	case InputType::Released: return !input &&  preInput;
	}

	return false;
}
