#include "CollisionManager.h"



namespace HCHEngine
{
	CollisionManager* CollisionManager::S = NULL;
	
	void CollisionManager::Init()
	{
		m_vecCircleColliers.clear();
	}

	void CollisionManager::SetCircleCollider(CircleCollider* pCircleCollider)
	{
		m_vecCircleColliers.push_back(pCircleCollider);
	}

	void CollisionManager::ResetCircleCollier()
	{
		m_vecCircleColliers.clear();
	}

	bool CollisionManager::CheckCollCircleCollider(string mainObjectName, string otherObjectName, vector<void*>& returnCollObjects)
	{
		CircleCollider* mainObject = NULL;
		returnCollObjects.clear();

		for (auto iter = m_vecCircleColliers.begin(); iter != m_vecCircleColliers.end(); iter++)
		{
			if ((*iter)->type == mainObjectName)
			{
				mainObject = *iter;
			}
		}

		if (mainObject == NULL)
		{
			return false;
		}

		for (auto iter = m_vecCircleColliers.begin(); iter != m_vecCircleColliers.end(); iter++)
		{
			if ((*iter)->type == otherObjectName)
			{
				if ((*iter)->collider.CheckCollWithCircle(mainObject->collider))
				{
					returnCollObjects.push_back((*iter)->colliderOwner);
				}
			}
		}

		if (returnCollObjects.size() != 0)
		{
			return true;
		}

		return false;
	}

	CollisionManager* CollisionManager::GetInstance()
	{
		if (S == NULL)
		{
			S = new CollisionManager;
		}

		return S;
	}

	void CollisionManager::Release()
	{
		m_vecCircleColliers.clear();
	}

	void CollisionManager::Destroy()
	{
		SAFE_DELETE(S);
	}

	CollisionManager::CollisionManager()
	{

	}

	CollisionManager::~CollisionManager()
	{

	}
}
