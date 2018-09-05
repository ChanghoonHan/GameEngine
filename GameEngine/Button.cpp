#include "Button.h"

namespace HCHEngine
{
	void Button::Init(string FirstBitMap, string SecondBitMap, int x, int y, int width, int height, pIntFunc callback)
	{
		m_buttonBitMap[BUTTONBMP_1] = DrawManager::GetInstnace()->GetBitMap(FirstBitMap);
		m_buttonBitMap[BUTTONBMP_2] = DrawManager::GetInstnace()->GetBitMap(SecondBitMap);
		m_collider.SetRect(x, y, x + width, y + height);
		m_pCallBack = callback;
		m_iX = x;
		m_iY = y;
		m_iWidth = width;
		m_iHeight = height;
		m_bIsSelect = false;
		m_pushBMP = false;
	}

	bool Button::Update()
	{
		if (OperatorManager::GetInstance()->IsKeyDown(VK_LBUTTON))
		{
			if (m_collider.collWithPoint(*OperatorManager::GetInstance()->GetMousePos()))
			{
				m_bIsSelect = true;
			}
		}

		if (OperatorManager::GetInstance()->IsKeyPress(VK_LBUTTON))
		{
			if (m_collider.collWithPoint(*OperatorManager::GetInstance()->GetMousePos()) && m_bIsSelect)
			{
				m_pushBMP = true;
			}
			else
			{
				m_pushBMP = false;
			}
		}

		if (OperatorManager::GetInstance()->IsKeyUp(VK_LBUTTON))
		{
			if (m_collider.collWithPoint(*OperatorManager::GetInstance()->GetMousePos()) && m_bIsSelect)
			{
				m_pushBMP = false;
				m_bIsSelect = false;
				m_pCallBack();
				return true;
			}
			m_pushBMP = false;
			m_bIsSelect = false;
		}

		return false;
	}

	void Button::Draw()
	{
		if (!m_pushBMP)
		{
			m_buttonBitMap[BUTTONBMP_1]->Draw(m_iX, m_iY, m_iWidth, m_iHeight);
		}
		else
		{
			m_buttonBitMap[BUTTONBMP_2]->Draw(m_iX, m_iY, m_iWidth, m_iHeight);
		}
	}

	Button::Button()
	{
	}


	Button::~Button()
	{
	}
}