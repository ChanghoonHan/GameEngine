#pragma once
#include "GlobalHeader.h"

using namespace std;

class BitMap
{
	HDC m_hdc;

	HBITMAP m_NBitMap;
	HBITMAP m_OBitMap;
	int m_imageWidth;
	int m_imageHeight;

public:
	void Draw(int x, int y, int width = -1, int height = -1, 
		int rendX = -1, int rendY = -1, int rendWidth = -1, int rendHeight = -1);
	void Init(string bitMapName);

	void InitBack(HDC hdc, int iWindowWidth, int iWindoHeight);
	void DrawBack();

	void Release();

	BitMap();
	~BitMap();
};