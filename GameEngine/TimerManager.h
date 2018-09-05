#pragma once
#include "GlobalHeader.h"

namespace HCHEngine
{
	class TimerManager
	{
		static TimerManager* S;

		DWORD m_dwCurTime;
		DWORD m_dwLastTime;
		float m_fElapsedTime;

		TimerManager();
		~TimerManager();
	public:
		void Init();
		void Update();

		float GetElapsedTime();

		static TimerManager* GetInstance();
		static void Destroy();
	};
}


