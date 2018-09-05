#include "GameManager.h"
#include "CollisionManager.h"

namespace HCHEngine
{
	GameManager* GameManager::S = NULL;

	void GameManager::Init(HWND hWnd, int iWindowWidth, int iWindowHeight)
	{
		m_hWnd = hWnd;
		m_iWindowWidth = iWindowWidth;
		m_iWindowHeight = iWindowHeight;

		::RECT rcClient, rcWindow;
		GetClientRect(m_hWnd, &rcClient);
		GetWindowRect(m_hWnd, &rcWindow);

		int iWindowBezelX = (rcWindow.right - rcWindow.left) - (rcClient.right - rcClient.left);
		int iWindowBezelY = (rcWindow.bottom - rcWindow.top) - (rcClient.bottom - rcClient.top);

		MoveWindow(m_hWnd, 0, 0, iWindowWidth + iWindowBezelX, iWindowHeight + iWindowBezelY, true);

		TimerManager::GetInstance()->Init();
		OperatorManager::GetInstance()->Init(m_hWnd);

		HDC hdc = GetDC(m_hWnd);
		DrawManager::GetInstnace()->Init(hdc, iWindowWidth, iWindowHeight);

		ReleaseDC(m_hWnd, hdc);

		m_pCurScene = m_vecScene[0];
		m_pCurScene->Init();
	}

	bool GameManager::Play()
	{
		bool isGameExit;

		OperatorManager::GetInstance()->Update();
		TimerManager::GetInstance()->Update();

		HDC hdc = GetDC(m_hWnd);
		DrawManager::GetInstnace()->ClearDC();

		m_pCurScene->InputOperator(TimerManager::GetInstance()->GetElapsedTime());
		m_pCurScene->Update(TimerManager::GetInstance()->GetElapsedTime());
		isGameExit = !m_pCurScene->Draw();//게임 종료
		
		DrawManager::GetInstnace()->Draw(hdc);
		ReleaseDC(m_hWnd, hdc);

		return isGameExit;
	}

	void GameManager::Release()
	{
		DrawManager::GetInstnace()->Release();
		CollisionManager::GetInstance()->Release();

		CollisionManager::Destroy();
		TimerManager::Destroy();
		OperatorManager::Destroy();
		DrawManager::Destroy();

		for (auto iter = m_vecScene.begin(); iter != m_vecScene.end(); iter++)
		{
			if (*iter != NULL)
			{
				(*iter)->Release();
				delete(*iter);
			}
		}

		m_vecScene.clear();
	}

	void GameManager::RegisterScene(Scene* pScene)
	{
		m_vecScene.push_back(pScene);
	}

	void GameManager::LoadScene(int iSceneIndex)
	{
		Scene* m_pLastScene = m_pCurScene;
		m_pCurScene = m_vecScene[iSceneIndex];

		m_pLastScene->Release();
		m_pCurScene->Init();
	}

	GameManager* GameManager::GetInstance()
	{
		if (S == NULL)
		{
			S = new GameManager;
		}

		return S;
	}

	void GameManager::Destroy()
	{
		SAFE_DELETE(S);
	}

	GameManager::GameManager()
	{
	}

	GameManager::~GameManager()
	{
	}
}
