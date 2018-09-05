#pragma once

enum GAMESTATE
{
	READY,
	PLAY,
	GAMEOVER,
};

class Scene
{
	public:
		virtual void Init() = 0;
		virtual void InputOperator(float fElapsedTime) = 0;
		virtual void Update(float fElapsedTime) = 0;
		virtual bool Draw() = 0;
		virtual void Release() = 0;

		Scene();
		virtual ~Scene();
};

