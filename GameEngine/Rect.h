#pragma once
#include "GlobalHeader.h"

namespace HCHEngine
{
	class Rect
	{
	public:
		int m_left;
		int m_top;
		int m_right;
		int m_bottom;

		void SetRect(int left, int top, int right, int bottom);
		::RECT ToWinRECT();

		bool collWithRect(HCHEngine::Rect otherRect);
		bool collWithPoint(HCHEngine::Point point);

		Rect();
		~Rect();
	};
}


