#pragma once
#include <string>
#include <Windows.h>
#include <vector>
#include <functional>
#include <map>
#include "GameEngineMain.h"
#include "GameManager.h"
#include "Scene.h"
#include "BitMap.h"
#include "DrawManager.h"
#include "Point.h"
#include "Rect.h"
#include "Circle.h"
#include "OperatorManager.h"
#include "TimerManager.h"
#include <random>

using namespace std;
using namespace HCHEngine;

typedef std::function<int()> pIntFunc;

#define SAFE_DELETE( p ) { if( p ) { delete ( p ); ( p ) = NULL; } }
#define SAFE_DELETE_ARRAY( p ) { if( p ) { delete[] ( p ); ( p ) = NULL; } }
#define SAFE_RELEASE(p) { if ( (p) ) { (p)->Release(); (p) = 0; } }