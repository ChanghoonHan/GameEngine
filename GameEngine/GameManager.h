#pragma once
#include "GlobalHeader.h"

class Scene;
using namespace std;

namespace HCHEngine
{
	class GameManager
	{
		static GameManager* S;

		HWND m_hWnd;
		int m_iWindowWidth;
		int m_iWindowHeight;

		vector<Scene*> m_vecScene;
		Scene* m_pCurScene;

		GameManager();
		~GameManager();

	public:
		void Init(HWND hWnd, int iWindowWidth, int iWindowHeight);
		bool Play();
		void Release();

		void RegisterScene(Scene* pScene);
		void LoadScene(int iSceneIndex);

		static GameManager* GetInstance();
		static void Destroy();
	};
};