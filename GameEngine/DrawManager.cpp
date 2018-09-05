#include "DrawManager.h"

namespace HCHEngine
{
	DrawManager* DrawManager::S = NULL;

	HDC DrawManager::GetDC()
	{
		return m_backDC;
	}

	void DrawManager::PutText(string str, int left, int top, int right, int bottom, UINT DTformat)
	{
		Rect rect;
		rect.SetRect(left, top, right, bottom);
		DrawText(m_backDC, str.c_str(), strlen(str.c_str()), &rect.ToWinRECT(), DTformat);
	}

	void DrawManager::PutText(char* str, int left, int top, int right, int bottom, UINT DTformat)
	{
		Rect rect;
		rect.SetRect(left, top, right, bottom);
		DrawText(m_backDC, str, strlen(str), &rect.ToWinRECT(), DTformat);
	}

	void DrawManager::Draw(HDC hdc)
	{
		TransparentBlt(hdc, 0, 0, m_iWindowWidth, m_iWindowHeight, m_backDC, 0, 0, m_iWindowWidth, m_iWindowHeight, RGB(255, 0, 255));
	}

	void  DrawManager::ClearDC()
	{
		m_backBitMap->DrawBack();
	}

	BitMap* DrawManager::LoadBitMap(string strBitMapName)
	{
		BitMap* newBitMap = new BitMap();
		newBitMap->Init(strBitMapName);
		m_mapBitMap.insert(make_pair(strBitMapName, newBitMap));

		return newBitMap;
	}

	BitMap* DrawManager::GetBitMap(string strBitMapName)
	{
		auto iter = m_mapBitMap.find(strBitMapName);

		if (iter == m_mapBitMap.end())
		{
			return LoadBitMap(strBitMapName);
		}

		return iter->second;
	}

	void DrawManager::Init(HDC hdc, int iWindowWidth, int iWindowHeight)
	{
		m_backBitMap = new BitMap;
		m_backBitMap->InitBack(hdc, iWindowWidth, iWindowHeight);
		m_backDC = CreateCompatibleDC(hdc);
		m_iWindowWidth = iWindowWidth;
		m_iWindowHeight = iWindowHeight;
		m_newBitMap = CreateCompatibleBitmap(hdc, m_iWindowWidth, m_iWindowHeight);
		m_oldBitMap = (HBITMAP)SelectObject(m_backDC, m_newBitMap);
		SetBkMode(m_backDC, TRANSPARENT);//글자 배경투명 시작
	}

	void DrawManager::Release()
	{
		for (auto iter = m_mapBitMap.begin(); iter != m_mapBitMap.end(); iter++)
		{
			iter->second->Release();
			SAFE_DELETE(iter->second);
		}
		m_backBitMap->Release();
		SAFE_DELETE(m_backBitMap);
		m_mapBitMap.clear();

		SetBkMode(m_backDC, OPAQUE);//글자배경 투명 해제
		SelectObject(m_backDC, m_oldBitMap);
		DeleteObject(m_newBitMap);
		DeleteDC(m_backDC);
	}

	DrawManager* DrawManager::GetInstnace()
	{
		if (S == NULL)
		{
			S = new DrawManager;
		}

		return S;
	}

	void DrawManager::Destroy()
	{
		SAFE_DELETE(S);
	}

	DrawManager::DrawManager()
	{
	}


	DrawManager::~DrawManager()
	{
	}
}
