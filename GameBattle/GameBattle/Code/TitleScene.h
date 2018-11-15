#pragma once

#include"Main.h"


namespace Scene
{
	class TitleScene : public MyApp::Scene
	{
	private:

		class Panel
		{
		private:

			Vec2 _pos;

			float _scl;

			float _speed;

			String _panelName;

		public:

			Panel(double  x, double scl, const String & panelName)
				: _pos(x, 550)
				, _scl(scl)
				, _speed(-_scl*_scl)
				, _panelName(panelName)
			{
			}

			bool operator < (const Panel& panel)const
			{
				return _scl < panel._scl;
			}

			void update()
			{
				_pos.y += _speed;
			}

			void draw() const
			{
				TextureAsset(_panelName).scale(_scl).drawAt(_pos, AlphaF(0.3 + _scl / 2.0));
			}

			bool eraser() const
			{
				return _pos.y < -100;
			}

		};

	private:

		Font font;

		Array<String> _panelNameList;

		Array<Panel> _panelList;

		int _panelId;

	public:

		TitleScene()
			: font(20, L"ü‡ÉSÉVÉbÉN Medium")
		{
		}

		bool isStart;

		void init()override;

		void update()override;

		void draw()const override;
	};
}