#pragma once


#include"GameObject.h"


namespace GameObject
{

	class AttackObject : public GameObject
	{
	protected:

		int  _id;   // �v���C���[�̎��ʔԍ�

		int  _time; // �I�u�W�F�N�g����������Ă��炩���鎞��

		bool _eraseFlag = false; // �I�u�W�F�N�g���폜����

		int  _endTime; // time�ƒl���������Ȃ��

	public:

		bool eraser() const override;

		void collisionUpdate(const GameData::TagData & tagData) override;

	protected:

		/// <summary>
		/// ��{�I�ȉ������U���̓���
		/// </summary>
		/// <param name="gravity"> �d�͂ɂ�鉺�����̉����x </param>
		void shooting(double gravity);

		/// <summary>
		/// ���������I�ȓ���
		/// </summary>
		void walking();
	};

}