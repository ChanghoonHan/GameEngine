#include "BitMap.h"

void BitMap::Init(string bitMapName)
{
	m_hdc = CreateCompatibleDC(DrawManager::GetInstnace()->GetDC());
	m_NBitMap = (HBITMAP)LoadImage(NULL, bitMapName.c_str(), IMAGE_BITMAP, 0, 0,
		LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	BITMAP bmp_info;
	GetObject(m_NBitMap, sizeof(BITMAP), &bmp_info);
	m_imageHeight = bmp_info.bmHeight;
	m_imageWidth = bmp_info.bmWidth;

	m_OBitMap = (HBITMAP)SelectObject(m_hdc, m_NBitMap);
}

void BitMap::Draw(int x, int y, int width, int height, int rendX, int rendY, int rendWidth, int rendHeight)
{
	if (width == -1)
	{
		width = m_imageWidth;
	}

	if (height == -1)
	{
		height = m_imageHeight;
	}

	if (rendX == -1)
	{
		rendX = 0;
	}

	if (rendY == -1)
	{
		rendY = 0;
	}

	if (rendWidth == -1)
	{
		rendWidth = m_imageWidth;
	}

	if (rendHeight == -1)
	{
		rendHeight = m_imageHeight;
	}

	TransparentBlt(DrawManager::GetInstnace()->GetDC(), x, y, width, height,
		m_hdc, rendX, rendY, rendWidth, rendHeight, RGB(255, 0, 255));
}

void BitMap::InitBack(HDC hdc, int iWindowWidth, int iWindoHeight)
{
	m_hdc = CreateCompatibleDC(hdc);
	m_NBitMap = CreateCompatibleBitmap(hdc, iWindowWidth, iWindoHeight);
	m_imageHeight = iWindowWidth;
	m_imageWidth = iWindowWidth;

	m_OBitMap = (HBITMAP)SelectObject(m_hdc, m_NBitMap);
}

void BitMap::DrawBack()
{
	BitBlt(DrawManager::GetInstnace()->GetDC(), 0, 0, m_imageWidth, m_imageHeight, m_hdc, 0, 0, SRCCOPY);
}

void BitMap::Release()
{
	(HBITMAP)SelectObject(m_hdc, m_OBitMap);
	DeleteObject(m_NBitMap);
	DeleteDC(m_hdc);
	m_NBitMap = NULL;
}

BitMap::BitMap()
{
	m_NBitMap = NULL;
}

BitMap::~BitMap()
{
	Release();
}
