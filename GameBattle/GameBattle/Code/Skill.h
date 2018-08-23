#pragma once


#include"GameObject.h"


namespace GameObject
{
	class Player;
}


namespace Skill
{

	class Skill
	{
	public:

		/// <summary>
		/// �X�V
		/// </summary>
		/// <param name="time"> �X�L���̐i�s�� </param>
		/// <param name="player"> �v���C���[ </param>
		/// <param name="generator"> �I�u�W�F�N�g�̐������X�g </param>
		virtual void update(int time, const GameObject::Player & player, const std::shared_ptr<GameData::Generator> & generator) = 0;

		/// <summary>
		/// �����蔻��m�F
		/// </summary>
		/// <param name="collider"> ���̗̂̈� </param>
		/// <returns> �^�O </returns>
		virtual String collision(int time, const GameObject::Player & player, const Rect & collider) = 0;

		/// <summary>
		/// �`��
		/// </summary>
		/// <param name="time"> �X�L���i�s�� </param>
		/// <param name="player"> �v���C���[ </param>
		virtual void draw(int time, const GameObject::Player & player) const = 0;

		/// <summary>
		/// �I������
		/// </summary>
		/// <param name="time"> �X�L���i�s�� </param>
		/// <returns> �I������Ƃ� true , �����łȂ��Ƃ� false </returns>
		virtual bool finish(int time) const = 0;

	};

}