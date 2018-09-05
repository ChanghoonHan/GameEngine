#include "Circle.h"
#include <math.h>

namespace HCHEngine
{
	bool Circle::CheckCollWithCircle(Circle& anothorCircle)
	{
		if (powf((m_raidus + anothorCircle.m_raidus), 2) >= 
			(powf(m_center.fX - anothorCircle.m_center.fX, 2) + powf(m_center.fY - anothorCircle.m_center.fY, 2)))
		{
			return true;
		}

		return false;
	}

	void Circle::SetCircle(float left, float top, float right, float bottom)
	{
		m_left = left;
		m_top = top;
		m_right = right;
		m_bottom = bottom;
		m_raidus = (m_right - m_left) / 2;

		m_center.fX = (float)(m_right + m_left) / 2;
		m_center.fY = (float)(m_bottom + m_top) / 2;
	}

	Circle::Circle(float left, float top, float right, float bottom)
	{
		SetCircle(left, top, right, bottom);
	}

	Circle::Circle()
	{
		SetCircle(0,0,0,0);
	}

	Circle::~Circle()
	{
	}
}