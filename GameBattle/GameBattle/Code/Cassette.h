#pragma once


#include"GameObject.h"


namespace GameObject
{

	class Cassette : public GameObject
	{
	private:

		size_t _id;

		String _skillKey;

		bool   _eraseFlag;

	public:

		Cassette(const size_t & id);

		void update() override;

		void draw() const override;

		bool eraser() const override;

		void collisionUpdate(const GameData::TagData & tag) override;

	};

}