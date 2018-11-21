#pragma once


#include<Siv3D.hpp>


namespace GameData
{

	class StageData
	{
	public:

		static const int CELLSIZE   = 16; // �P�}�X�̂P�ӂ̒���

		static const int EMPTY      = 0;  // �����Ȃ�

		static const int HARF_BLOCK = 1;  // �ォ��͒ʉ߂ł���u���b�N

		static const int BLOCK      = 2;  // �u���b�N

	private:

		int _width; // ��

		int _height;  // ����

		String _name; // �X�e�[�W��

		static const int CASSETTE_POS = 3;     // �J�Z�b�g�o���ӏ�

		static const int PLAYER_POS = 4;       // �v���C���[�������W

		std::vector<std::vector<int>> cell;    // �}�X���Ƃ̃X�e�[�W�f�[�^

		std::vector<Vec2> playerPos;           // �v���C���[�����̍��W
	public:

		Array<Vec2> cassettePos;               // �J�Z�b�g�𐶐�������W

		Array<int> cassetteGenerateFrameCount; // �J�Z�b�g�����܂ł̃t���[����

	private:

		StageData();

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
			return CELLSIZE*Size(_width, _height);
		}

		/// <summary>
		/// �v���C���[�𐶐�������W���擾���܂��B
		/// </summary>
		/// <param name="id"> �v���C���[�̎��ʔԍ� </param>
		/// <returns> 
		Vec2 getPlayerPos(int id)const;

		/// <summary>
		/// �J�Z�b�g���o����������W�������_���Ō��肵�܂��B
		/// </summary>
		/// <param name="id"> ���I���珜�O������W�̔ԍ� </param>
		/// <returns> ���W�Ƃ��̎��ʔԍ� </returns>
		std::pair<Vec2, size_t> getCassettePos(const size_t & id) const;

		/// <summary>
		/// �}�b�v�̃f�[�^��`�悷��
		/// </summary>
		void draw() const;

		/// <summary>
		/// �w�肳�ꂽ���W�̃X�e�[�W�̃f�[�^���擾���܂��B
		/// </summary>
		/// <param name="pos"> ���W </param>
		/// <returns> �X�e�[�W�̃f�[�^ </returns>
		int getCell(const Point & pos) const;

		/// <summary>
		/// CSV�t�@�C���̓ǂݍ���
		/// </summary>
		/// <param name="stageName"> �X�e�[�W�� </param>
		void read(const String & stageName);

	};

}