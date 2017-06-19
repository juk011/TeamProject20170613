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
	m_pImage->Load("./Images/Stage.bmp");
	m_pImage->SetPos(Vector2D(0.0f, 0.0f));

	m_pSprite = new CBaseRender;
	m_pSprite->Initialize();
	m_pSprite->Load("./Images/Hair.bmp");
	m_pSprite->SetPos(Vector2D(200,100));
<<<<<<< HEAD
	m_pSprite->SetColorKey(RGB(255, 255, 255));

=======
	m_pSprite->SetColorKey(RGB(255, 0, 255));

	EyeIcon = new CBaseRender;
	EyeIcon->Initialize();
	EyeIcon->Load("./Images/ui_main/1_1.bmp");
	EyeIcon->SetPos(Vector2D(345, 60));
	EyeIcon->SetColorKey(RGB(255, 0, 255));

	MouthIcon = new CBaseRender;
	MouthIcon->Initialize();
	MouthIcon->Load("./Images/ui_main/3_1.bmp");
	MouthIcon->SetPos(Vector2D(345, 110));
	MouthIcon->SetColorKey(RGB(255, 0, 255));

	HairIcon = new CBaseRender;
	HairIcon->Initialize();
	HairIcon->Load("./Images/ui_main/4_1.bmp");
	HairIcon->SetPos(Vector2D(345, 160));
	HairIcon->SetColorKey(RGB(255, 0, 255));

	ClothesIcon = new CBaseRender;
	ClothesIcon->Initialize();
	ClothesIcon->Load("./Images/ui_main/5_1.bmp");
	ClothesIcon->SetPos(Vector2D(345, 210));
	ClothesIcon->SetColorKey(RGB(255, 0, 255));

	ShoesIcon = new CBaseRender;
	ShoesIcon->Initialize();
	ShoesIcon->Load("./Images/ui_main/6_1.bmp");
	ShoesIcon->SetPos(Vector2D(345, 260));
	ShoesIcon->SetColorKey(RGB(255, 0, 255));
>>>>>>> bb4c5cb8cdcf1f3b8ceea5115aefc20d31051fff

	Body = new CBaseRender;
	Body->Initialize();
	Body->Load("./Images/Character/body.bmp");
<<<<<<< HEAD
	Body->SetPos(Vector2D(80, 30));
=======
	Body->SetPos(Vector2D(80, 50));
>>>>>>> bb4c5cb8cdcf1f3b8ceea5115aefc20d31051fff
	Body->SetColorKey(RGB(255, 0, 255));

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
		Body->Render();
<<<<<<< HEAD
		
=======
		EyeIcon->Render();
		MouthIcon->Render();
		HairIcon->Render();
		ClothesIcon->Render();
		ShoesIcon->Render();

>>>>>>> bb4c5cb8cdcf1f3b8ceea5115aefc20d31051fff

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

