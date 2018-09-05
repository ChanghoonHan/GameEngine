#pragma once
#include "GlobalHeader.h"


namespace HCHEngine
{
	struct CircleCollider
	{
		string type;
		Circle collider;
		void* colliderOwner;
	};

	struct RectCollider
	{
		string type;
		Rect collider;
		void* colliderOwner;
	};

	class CollisionManager
	{
		static CollisionManager* S;

		vector<CircleCollider*> m_vecCircleColliers;
		//vector<RectCollider*> m_vecRectColliers;

		CollisionManager();
		~CollisionManager();

	public:
		void Init();
		void SetCircleCollider(CircleCollider* pCircleCollider);
		void ResetCircleCollier();
		bool CheckCollCircleCollider(string mainObjectName, string otherObjectName, vector<void*>& returnCollObjects);
		void Release();

		static CollisionManager* GetInstance();
		static void Destroy();
	};
}
