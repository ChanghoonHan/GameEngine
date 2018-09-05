#pragma once
#include "Point.h"

namespace HCHEngine
{
	class Circle
	{

	public:
		float m_left;
		float m_top;
		float m_right;
		float m_bottom;
		float m_raidus;
		PointF m_center;

		bool CheckCollWithCircle(Circle& anothorCircle);
		void SetCircle(float left, float top, float right, float bottom);
		Circle(float left, float top, float right, float bottom);
		Circle();
		~Circle();
	};
}

