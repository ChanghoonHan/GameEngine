#include "TimerManager.h"

namespace HCHEngine
{
	TimerManager* TimerManager::S = NULL;

	void TimerManager::Init()
	{
		m_dwCurTime = GetTickCount();
		m_dwLastTime = m_dwCurTime;
		m_fElapsedTime = 0;
	}

	void TimerManager::Update()
	{
		m_dwCurTime = GetTickCount();
		m_fElapsedTime = (m_dwCurTime - m_dwLastTime) / 1000.0f;
		m_dwLastTime = m_dwCurTime;
	}

	float TimerManager::GetElapsedTime()
	{
		return m_fElapsedTime;
	}

	TimerManager* TimerManager::GetInstance()
	{
		if (S == NULL)
		{
			S = new TimerManager;
		}

		return S;
	}

	void TimerManager::Destroy()
	{
		SAFE_DELETE(S);
	}

	TimerManager::TimerManager()
	{
	}


	TimerManager::~TimerManager()
	{
	}
}

