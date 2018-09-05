#pragma once
#include "GlobalHeader.h"

namespace HCHEngine
{
	class OperatorManager
	{
		struct KeyINFO
		{
			int iKeyValue;
			bool bKeyDown;
			bool bKeyUp;
			bool bKeyPress;
		};

	private:
		static OperatorManager* S;

		Point m_mousePos;
		HWND m_hWnd;

		vector<KeyINFO> m_vecKeys;

		OperatorManager();
		~OperatorManager();

	public:
		void Init(HWND hWnd);
		void RegisterKey(int iKeyValue);
		void Update();
		void KeyClear();

		bool IsKeyDown(int iKeyValue);
		bool IsKeyUp(int iKeyValue);
		bool IsKeyPress(int iKeyValue);
		Point* GetMousePos();

		static OperatorManager* GetInstance();
		static void Destroy();
	};
};


