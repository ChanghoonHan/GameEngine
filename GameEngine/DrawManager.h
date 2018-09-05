#pragma once
#include "GlobalHeader.h"

class BitMap;
namespace HCHEngine
{
	class DrawManager
	{
		static DrawManager* S;

		HDC m_backDC;
		HBITMAP m_newBitMap;
		HBITMAP m_oldBitMap;

		int m_iWindowWidth;
		int m_iWindowHeight;

		map<string, BitMap*> m_mapBitMap;
		BitMap* LoadBitMap(string strBitMapName);
		BitMap* m_backBitMap;

		DrawManager();
		~DrawManager();

	public:
		HDC GetDC();
		void PutText(string str, int left, int top, int right, int bottom, UINT DTformat = DT_CENTER);
		void PutText(char*, int left, int top, int right, int bottom, UINT DTformat = DT_CENTER);
		void Draw(HDC hdc);
		void ClearDC();

		BitMap* GetBitMap(string strBitMapName);
		void Init(HDC hdc, int iWindowWidth, int iWindowHeight);
		void Release();

		static DrawManager* GetInstnace();
		static void Destroy();
	};
}


