// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>
#include <mmsystem.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
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

