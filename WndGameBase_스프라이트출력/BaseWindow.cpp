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

	//������ Ŭ���� ����/�ʱ�ȭ
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

	RegisterClassEx(&wcex); //������ Ŭ���� ���

	int msgID = MessageBox(NULL, L"��üȭ������ ��ȯ�ұ��?", L"***����", MB_OKCANCEL);
	
	
	////������ ����
	//m_hWnd = CreateWindow(szTitle, szTitle, WS_BORDER | WS_POPUP,
	//	0, 0, 0, 0, NULL, NULL, hInstance, NULL);

	RECT rtRect; //�簢�� ����ü

	rtRect.left = 0;
	rtRect.top = 0;
	rtRect.right = WIDTH;
	rtRect.bottom = HEIGHT;

	////������ ������ ������ �Լ�
	//AdjustWindowRect(&rtRect, WS_BORDER | WS_BORDER | WS_POPUP, false);

	// ������ ��üȭ��
	DEVMODE devmode;

	ZeroMemory(&devmode, sizeof(DEVMODE));
	devmode.dmSize = sizeof(DEVMODE);
	devmode.dmBitsPerPel = 32;
	devmode.dmPelsWidth = WIDTH;
	devmode.dmPelsHeight = HEIGHT;
	devmode.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

	if (msgID == 1)
	{
		//������ ����
		m_hWnd = CreateWindow(szTitle, szTitle, WS_BORDER | WS_POPUP,
			0, 0, 0, 0, NULL, NULL, hInstance, NULL);

		//������ ������ ������ �Լ�
		AdjustWindowRect(&rtRect, WS_BORDER | WS_BORDER | WS_POPUP, true);

		ChangeDisplaySettings(&devmode, CDS_FULLSCREEN);
	}
	else if (msgID == 2)
	{
		//������ ����
		m_hWnd = CreateWindow(szTitle, szTitle, WS_BORDER | WS_CAPTION,
			0, 0, 0, 0, NULL, NULL, hInstance, NULL);

		AdjustWindowRect(&rtRect, WS_BORDER | WS_BORDER | WS_CAPTION, false);
	}

	//������ ��ġ
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