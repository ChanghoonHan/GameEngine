#pragma once
#include "GlobalHeader.h"

using namespace std;

namespace HCHEngine
{
	class GameEngineMain
	{
		string m_strWindowTittle;
		int m_iWindowWidth;
		int m_iWindowHeight;

	public:
		int StartEngine(HINSTANCE hInstance);
		GameEngineMain(string strWindowTittle = "Default", int iWindowWidth = 1024, int iWindowHeight = 768);
		~GameEngineMain();
	};
}