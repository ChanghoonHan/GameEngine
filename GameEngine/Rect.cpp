#include "Rect.h"

namespace HCHEngine
{
	void Rect::SetRect(int left, int top, int right, int bottom)
	{
		m_left = left;
		m_top = top;
		m_right = right;
		m_bottom = bottom;
	}

	::RECT Rect::ToWinRECT()
	{
		::RECT rect;
		rect.left = m_left;
		rect.top = m_top;
		rect.right = m_right;
		rect.bottom = m_bottom;

		return rect;
	}

	bool Rect::collWithRect(Rect otherRect)
	{
		if (m_left < otherRect.m_right && m_top <= otherRect.m_bottom &&
			m_right > otherRect.m_left && m_bottom > otherRect.m_top)
			return true;
		else
			return false;
	}

	bool Rect::collWithPoint(Point otherPoint)
	{
		if (otherPoint.iX >= m_left && otherPoint.iX <= m_right &&
			otherPoint.iY >= m_top && otherPoint.iY <= m_bottom)
		{
			return true;
		}

		return false;
	}

	Rect::Rect()
	{
	}

	Rect::~Rect()
	{
	}
}
