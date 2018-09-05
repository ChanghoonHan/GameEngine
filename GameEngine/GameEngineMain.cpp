#include "GameEngineMain.h"

namespace HCHEngine
{
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	int GameEngineMain::StartEngine(HINSTANCE hInstance)
	{
		srand(GetTickCount());

		MSG Message;
		WNDCLASS WndClass;

		WndClass.cbClsExtra = 0;
		WndClass.cbWndExtra = 0;
		WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		WndClass.hInstance = hInstance;
		WndClass.lpfnWndProc = WndProc;
		WndClass.lpszClassName = m_strWindowTittle.c_str();
		WndClass.lpszMenuName = NULL;
		WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
		RegisterClass(&WndClass);

		HWND hWnd = CreateWindow(m_strWindowTittle.c_str(), m_strWindowTittle.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
			CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
		ShowWindow(hWnd, SW_SHOWDEFAULT);

		GameManager::GetInstance()->Init(hWnd, m_iWindowWidth, m_iWindowHeight);

		while (true)
		{
			/// 메시지큐에 메시지가 있으면 메시지 처리
			if (PeekMessage(&Message, NULL, 0U, 0U, PM_REMOVE))
			{
				if (Message.message == WM_QUIT)
					break;

				TranslateMessage(&Message);
				DispatchMessage(&Message);
			}
			else
			{
				if (GameManager::GetInstance()->Play())
				{
					SendMessage(hWnd, WM_DESTROY, 0, 0);
				}
			}
		}

		GameManager::GetInstance()->Release();
		GameManager::GetInstance()->Destroy();

		return (int)Message.wParam;
	}

	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
	{
		switch (iMessage)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}

		return(DefWindowProc(hWnd, iMessage, wParam, lParam));
	}

	GameEngineMain::GameEngineMain(string strWindowTittle, int iWindowWidth, int iWindowHeight)
	{
		m_strWindowTittle = strWindowTittle;
		m_iWindowWidth = iWindowWidth;
		m_iWindowHeight = iWindowHeight;
	}

	GameEngineMain::~GameEngineMain()
	{
	}
}