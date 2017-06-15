#include "stdafx.h"

CSystem::CSystem(void)
{
	m_bIsReady = false;
}

CSystem::~CSystem(void)
{

}

bool CSystem::Initialize(void)
{
	CBaseWindow::Initialize();
	CTimeManager::Initialize();

	m_pGameFrame = new CFrameSkip;
	m_pGameFrame->SetFramePerSec(60);

	m_pInputManager = new CInputManager;
	m_pInputManager->Initialize();
	g_pInputManager->SetInputHandler(this);

	m_pImageManager = new CImageManager;
	m_pImageManager->Initialize();

	m_pImage = new CBaseRender;
	m_pImage->Initialize();
	m_pImage->Load("./Images/MainGame.bmp");
	m_pImage->SetPos(Vector2D(0.0f, 0.0f));

	m_pSprite = new CBaseRender;
	m_pSprite->Initialize();
	m_pSprite->Load("./Images/sprite.bmp");
	m_pSprite->SetPos(Vector2D(200.0f, 0.0f));
	m_pSprite->SetColorKey(RGB(255, 255, 255));

	return true;
}

void CSystem::Update(void)
{
	CTimeManager::Pulse();
	m_pInputManager->Pulse();

	float fTimeStep = CTimeManager::GetTimeStep();

	if (m_pGameFrame->Update(fTimeStep))
	{
		/*
		g_pGdi->WhitePen();
		g_pGdi->WhiteBrush();
		g_pGdi->Rect(0, 0, 640, 480);
        */

		m_pImage->Render();
		m_pSprite->Render();

#ifdef _DEBUG
		static unsigned int nCount = 0;
		TCHAR buffer[128];

		g_pGdi->TransparentText();
#ifdef _UNICODE


		wsprintf(buffer, L"[FPS:%5d][Time:%5d][GameFPS:%5d]", (int)GetFPS(), (int)GetTime(), (int)(nCount / GetTime()));
		g_pGdi->TextAtPos(10, 10, buffer);

		wsprintf(buffer, L"마우스좌표XY(%3d,%3d)", (int)m_vMouseXY.x, (int)m_vMouseXY.y);
		g_pGdi->TextAtPos(10, 30, buffer);
		wsprintf(buffer, L"마우스버튼 L(%c) M(%c) R(%c)", (m_bIsMouseLeft) ? 'o' : 'x', (m_bIsMouseMid) ? 'o' : 'x', (m_bIsMouseRight) ? 'o' : 'x');
		g_pGdi->TextAtPos(10, 50, buffer);
#else
		sprintf(buffer, "[FPS:%5.1f][Time:%5.1f][GameFPS:%5.1f]", GetFPS(), GetTime(), nCount / GetTime());
		g_pGdi->TextAtPos(10, 10, buffer);

		sprintf(buffer, "마우스좌표XY(%3d,%3d)", (int)m_vMouseXY.x, (int)m_vMouseXY.y);
		g_pGdi->TextAtPos(10, 30, buffer);
		sprintf(buffer, "마우스버튼 L(%c) M(%c) R(%c)", (m_bIsMouseLeft) ? 'o' : 'x', (m_bIsMouseMid) ? 'o' : 'x', (m_bIsMouseRight) ? 'o' : 'x');
		g_pGdi->TextAtPos(10, 50, buffer);
#endif
		g_pGdi->OpaqueText();
		nCount++;

#endif

		g_pGdi->Blt();
	}
}

void CSystem::Terminate(void)
{
	CBaseWindow::Terminate();
	CTimeManager::Terminate();

	g_pInputManager->SetInputHandler(NULL);

	m_pSprite->Terminate();
	m_pImage->Terminate();

	delete m_pImageManager;
	delete m_pInputManager;
	delete m_pGameFrame;
}

void CSystem::Run(void)
{
	MSG msg;

	PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else	return;

		}
		else if (m_bIsReady)
		{
			Update();
		}
		else
		{
			WaitMessage();
		}
	}
}

void CSystem::KeyboardHandler()
{

}

void CSystem::MouseHandler(MOUSESTATE diMouseState)
{
	m_bIsMouseLeft  =	(diMouseState.btn[0]) ? true : false;
	m_bIsMouseMid   =	(diMouseState.btn[2]) ? true : false;
	m_bIsMouseRight =	(diMouseState.btn[1]) ?  true : false;
	m_vMouseXY.x = diMouseState.x;
	m_vMouseXY.y = diMouseState.y;
}

