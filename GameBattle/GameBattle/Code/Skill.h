#pragma once


#include"Player.h"


namespace GameData
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
		virtual void update(int time, const GameObject::Player & player, const std::shared_ptr<Generator> & generator) = 0;

		/// <summary>
		/// �����蔻��m�F
		/// </summary>
		/// <param name="collider"> ���̗̂̈� </param>
		/// <returns> �^�O </returns>
		virtual String collision(const Rect & collider) = 0;

		/// <summary>
		/// �`��
		/// </summary>
		/// <param name="time"> �X�L���i�s�� </param>
		/// <param name="player"> �v���C���[ </param>
		virtual void draw(int time, const GameObject::Player & player) const = 0;

	};

}