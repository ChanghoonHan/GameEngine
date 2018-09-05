#pragma once
#include "GlobalHeader.h"

namespace HCHEngine
{
	enum BUTTONBMP
	{
		BUTTONBMP_1,
		BUTTONBMP_2,
		BUTTOMBMP_END
	};

	class Button
	{
		BitMap* m_buttonBitMap[BUTTOMBMP_END];
		Rect m_collider;
		pIntFunc m_pCallBack;
		bool m_pushBMP;
		bool m_bIsSelect;
		int m_iX;
		int m_iY;
		int m_iWidth;
		int m_iHeight;

	public:
		void Init(string FirstBitMap, string SecondBitMap, int x, int y, int width, int height, pIntFunc callback);
		void Draw();
		bool Update();

		Button();
		~Button();
	};
}
