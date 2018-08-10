#pragma once


#include<Siv3D.hpp>


namespace GameData
{

	class StageData
	{
	private:

		static const int WIDTH    = 120; // ��

		static const int HEIGHT   = 60;  // ����

		static const int CELLSIZE = 16;  // �P�}�X�̂P�ӂ̒���

		int cell[HEIGHT][WIDTH];         // �}�X���Ƃ̃X�e�[�W�f�[�^

	public:

		static const int EMPTY      = 0; // �����Ȃ�

		static const int HARF_BLOCK = 1; // �ォ��͒ʉ߂ł���u���b�N

		static const int BLOCK      = 2; // �u���b�N

	private:

		StageData()
		{
			read();
		}

		StageData(const StageData &) {}

		StageData(StageData &&) {}

	public:

		static StageData & Instance()
		{
			static StageData stageData;

			return stageData;
		}

		/// <summary>
		/// �����`���X�e�[�W�ƌ������Ă��邩�擾���܂��B
		/// </summary>
		/// <param name="collider"> �����` </param>
		/// <returns> �������Ă���Ƃ� true , �����łȂ��Ƃ� false </returns>
		int get(const Rect & rect) const;

		/// <summary>
		/// �X�e�[�W�̃T�C�Y���擾���܂��B
		/// </summary>
		Size getSize() const
		{
			return CELLSIZE*Size(WIDTH, HEIGHT);
		}

		/// <summary>
		/// �}�b�v�̃f�[�^��`�悷��
		/// </summary>
		void draw() const;

	private:

		/// <summary>
		/// �w�肳�ꂽ���W�̃X�e�[�W�̃f�[�^���擾���܂��B
		/// </summary>
		/// <param name="pos"> ���W </param>
		/// <returns> �X�e�[�W�̃f�[�^ </returns>
		int getCell(const Point & pos) const;

		/// <summary>
		/// CSV�t�@�C���̓ǂݍ���
		/// </summary>
		void read();

	};

}