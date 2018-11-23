#pragma once


#include"Main.h"


namespace Scene
{
	class StageSelectScene : public MyApp::Scene
	{
	private:

		class SelectCursor
		{
		private:

			int  _id;
			Vec2 _pos;
			Vec2 _velocity;

			Color _color;

		public:

			SelectCursor(int id)
			{
				_id = id;

				_pos = Vec2(Window::BaseSize().x, Window::BaseSize().y) / 4;

				switch(id)
				{
				case 0: _color = Palette::Red;    break;
				case 1: _color = Palette::Cyan;   break;
				case 2: _color = Palette::Yellow; break;
				case 3: _color = Palette::Lime;   break;
				default: break;
				}
			}

			void update();

			void draw() const;

			Circle getPos()const;

		};

		class StageButton
		{
		public:

			StageButton(const String & name,const Rect & region)
				: Name(name)
				, Region(region)
			{
			}

			String Name;
			Rect   Region;
		};

	private:

		Array<SelectCursor> _cursorList;

		Array<StageButton>  _stageList;

		Font font{ 30 };

	public:

		StageSelectScene();

		void init()override;

		void update()override;

		void draw()const override;

	};
}