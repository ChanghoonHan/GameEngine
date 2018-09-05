#include "OperatorManager.h"

namespace HCHEngine
{
	OperatorManager* OperatorManager::S = NULL;

	void OperatorManager::Init(HWND hWnd)
	{
		m_mousePos.iX = 0;
		m_mousePos.iY = 0;
		m_hWnd = hWnd;
		m_vecKeys.clear();
	}

	void OperatorManager::RegisterKey(int iKeyValue)
	{
		for (auto iter = m_vecKeys.begin(); iter != m_vecKeys.end(); iter++)
		{
			if (iter->iKeyValue == iKeyValue)
			{
				return;
			}
		}

		KeyINFO newKey;
		newKey.bKeyDown = false;
		newKey.bKeyUp = false;
		newKey.bKeyPress = false;
		newKey.iKeyValue = iKeyValue;

		m_vecKeys.push_back(newKey);
	}

	void OperatorManager::KeyClear()
	{
		m_vecKeys.clear();
	}

	void OperatorManager::Update()
	{
		::POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(m_hWnd, &pt);
		m_mousePos.iX = pt.x;
		m_mousePos.iY = pt.y;

		for (auto iter = m_vecKeys.begin(); iter != m_vecKeys.end(); iter++)
		{
			if (GetKeyState(iter->iKeyValue) & 0x8000)
			{
				if (!iter->bKeyPress)
				{
					iter->bKeyDown = true;
				}
				else
				{
					iter->bKeyDown = false;
				}

				iter->bKeyUp = false;
				iter->bKeyPress = true;
			}
			else
			{
				if (iter->bKeyPress)
				{
					iter->bKeyUp = true;
				}
				else
				{
					iter->bKeyUp = false;
				}

				iter->bKeyDown = false;
				iter->bKeyPress = false;
			}
		}
	}

	bool OperatorManager::IsKeyDown(int iKeyValue)
	{
		for (auto iter = m_vecKeys.begin(); iter != m_vecKeys.end(); iter++)
		{
			if (iter->iKeyValue == iKeyValue)
			{
				return iter->bKeyDown;
			}
		}

		return false;
	}

	bool OperatorManager::IsKeyUp(int iKeyValue)
	{
		for (auto iter = m_vecKeys.begin(); iter != m_vecKeys.end(); iter++)
		{
			if (iter->iKeyValue == iKeyValue)
			{
				return iter->bKeyUp;
			}
		}

		return false;
	}

	bool OperatorManager::IsKeyPress(int iKeyValue)
	{
		for (auto iter = m_vecKeys.begin(); iter != m_vecKeys.end(); iter++)
		{
			if (iter->iKeyValue == iKeyValue)
			{
				return iter->bKeyPress;
			}
		}

		return false;
	}

	Point* OperatorManager::GetMousePos()
	{
		return &m_mousePos;
	}

	OperatorManager* OperatorManager::GetInstance()
	{
		if (S == NULL)
		{
			S = new OperatorManager;
		}

		return S;
	}

	void OperatorManager::Destroy()
	{
		SAFE_DELETE(S);
	}

	OperatorManager::OperatorManager()
	{
	}


	OperatorManager::~OperatorManager()
	{
	}

}