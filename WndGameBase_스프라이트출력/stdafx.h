// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>
#include <mmsystem.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#define MAX_LOADSTRING 128
#define MAX_IMAGE	   128
#define WIDTH          800
#define HEIGHT         600


#include "resource.h"
#include "Singleton.h"
#include "Vector2d.h"
#include "BaseWindow.h"
#include "BaseRender.h"
#include "TimeManager.h"
#include "FrameSkip.h"
#include "Gdi.h"
#include "InputHandler.h"
#include "InputManager.h"
#include "ImageInfo.h"
#include "ImageManager.h"
#include "ButtonBase.h"
#include "System.h"
#include "MainProc.h"
#include "Hair.h"
#include "Eye.h"
#include "Lip.h"
#include "Clothes.h"
#include "Shoes.h"