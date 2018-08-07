#pragma once


#include<Siv3D.hpp>


namespace GameData
{

	class StageData
	{
	private:

		static const int WIDTH = 60;

		static const int HEIGHT = 30;

		static const int CELLSIZE = 16;

		bool cell[HEIGHT][WIDTH];

	private:

		StageData()
		{
			read();
		}

		StageData(const StageData & sd) {}

		StageData(StageData && sd) {}

	public:

		static StageData & Instance()
		{
			static StageData stageData;

			return stageData;
		}

		/// <summary>
		/// �w�肳�ꂽ���W�̃X�e�[�W�̃f�[�^���擾���܂��B
		/// </summary>
		/// <param name="pos"> ���W </param>
		/// <returns> �X�e�[�W�̃f�[�^ </returns>
		bool get(const Point & pos) const;

		/// <summary>
		/// �����`���X�e�[�W�ƌ������Ă��邩�擾���܂��B
		/// </summary>
		/// <param name="collider"> �����` </param>
		/// <returns> �������Ă���Ƃ� true , �����łȂ��Ƃ� false </returns>
		bool get(const Rect & rect) const;

		/// <summary>
		/// �}�b�v�̃f�[�^��`�悷��
		/// </summary>
		void draw() const;

	private:

		void read();

	};

}