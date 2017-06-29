#include "stdafx.h"
#include "BaseWindow.h"


CBaseWindow::CBaseWindow(void) : m_bIsActive(false)
{
}


CBaseWindow::~CBaseWindow(void)
{
}

bool CBaseWindow::Initialize()
{
	HINSTANCE hInstance = GetModuleHandle(NULL);

	TCHAR szTitle[MAX_LOADSTRING];
	LoadString( hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING );

	//윈도우 클래스 정의/초기화
	WNDCLASSEX wcex;
	wcex.cbSize			= sizeof(WNDCLASSEX); 
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)MainWndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_WNDGAMEBASE);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= szTitle;
	wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	RegisterClassEx(&wcex); //윈도우 클래스 등록

	int msgID = MessageBox(NULL, L"전체화면으로 전환할까요?", L"***게임", MB_OKCANCEL);
	
	
	////윈도우 생성
	//m_hWnd = CreateWindow(szTitle, szTitle, WS_BORDER | WS_POPUP,
	//	0, 0, 0, 0, NULL, NULL, hInstance, NULL);

	RECT rtRect; //사각형 구조체

	rtRect.left = 0;
	rtRect.top = 0;
	rtRect.right = WIDTH;
	rtRect.bottom = HEIGHT;

	////윈도우 형식을 재정의 함수
	//AdjustWindowRect(&rtRect, WS_BORDER | WS_BORDER | WS_POPUP, false);

	// 윈도우 전체화면
	DEVMODE devmode;

	ZeroMemory(&devmode, sizeof(DEVMODE));
	devmode.dmSize = sizeof(DEVMODE);
	devmode.dmBitsPerPel = 32;
	devmode.dmPelsWidth = WIDTH;
	devmode.dmPelsHeight = HEIGHT;
	devmode.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

	if (msgID == 1)
	{
		//윈도우 생성
		m_hWnd = CreateWindow(szTitle, szTitle, WS_BORDER | WS_POPUP,
			0, 0, 0, 0, NULL, NULL, hInstance, NULL);

		//윈도우 형식을 재정의 함수
		AdjustWindowRect(&rtRect, WS_BORDER | WS_BORDER | WS_POPUP, true);

		ChangeDisplaySettings(&devmode, CDS_FULLSCREEN);
	}
	else if (msgID == 2)
	{
		//윈도우 생성
		m_hWnd = CreateWindow(szTitle, szTitle, WS_BORDER | WS_CAPTION,
			0, 0, 0, 0, NULL, NULL, hInstance, NULL);

		AdjustWindowRect(&rtRect, WS_BORDER | WS_BORDER | WS_CAPTION, false);
	}

	//윈도우 위치
	SetWindowPos(m_hWnd, NULL, 0, 0, rtRect.right - rtRect.left, rtRect.bottom - rtRect.top, SWP_SHOWWINDOW);

	if (!m_hWnd)
	{
		return false;
	}
	m_bIsActive = true;

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	return true;
}

void CBaseWindow::Terminate()
{
}