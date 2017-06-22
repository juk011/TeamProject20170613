#include "stdafx.h"

CSystem::CSystem(void)
{
	m_bIsReady = false;
	IsMain = true;
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

	//게임 인트로화면

	MainGame = new CBaseRender;
	MainGame->Initialize();
	MainGame->Load("./Images/MainGame.bmp");
	MainGame->SetPos(Vector2D(0.0f, 0.0f));


	Start[0] = new CButtonBase;
	Start[0]->Initialize();
	Start[0]->Load("./Images/ui_main/10_1.bmp");
	Start[0]->SetColorKey(RGB(255, 0, 255));
    Start[0]->SetPosAndSize(Vector2D(145, 300),240,80,135,89);
	Start[1] = new CButtonBase;
	Start[1]->Initialize();
	Start[1]->Load("./Images/ui_main/10_2.bmp");
	Start[1]->SetColorKey(RGB(255, 0, 255));
	Start[1]->SetPos(Vector2D(145, 300));
	Start[2] = new CButtonBase;
	Start[2]->Initialize();
	Start[2]->Load("./Images/ui_main/10_3.bmp");
	Start[2]->SetPos(Vector2D(145, 300));


	Exit[0] = new CButtonBase;
	Exit[0]->Initialize();
	Exit[0]->Load("./Images/ui_main/11_1.bmp");
	Exit[0]->SetColorKey(RGB(255, 0, 255));
	Exit[0]->SetPosAndSize(Vector2D(145, 420), 240, 80, 135, 89);
	Exit[1] = new CButtonBase;
	Exit[1]->Initialize();
	Exit[1]->Load("./Images/ui_main/11_2.bmp");
	Exit[1]->SetColorKey(RGB(255, 0, 255));
	Exit[1]->SetPos(Vector2D(145, 420));
	Exit[2] = new CButtonBase;
	Exit[2]->Initialize();
	Exit[2]->Load("./Images/ui_main/11_3.bmp");
	Exit[2]->SetPos(Vector2D(145, 420));





	//인게임 화면

	Stage = new CBaseRender;
	Stage->Initialize();
	Stage->Load("./Images/Stage.bmp");
	Stage->SetPos(Vector2D(0.0f, 0.0f));

	m_pSprite = new CBaseRender;
	m_pSprite->Initialize();
	m_pSprite->Load("./Images/Hair.bmp");
	m_pSprite->SetPos(Vector2D(200,100));
	m_pSprite->SetColorKey(RGB(255, 0, 255));

	EyeIcon[0] = new CButtonBase;
	EyeIcon[0]->Initialize();
	EyeIcon[0]->Load("./Images/ui_main/1_1.bmp");
	EyeIcon[0]->SetPosAndSize(Vector2D(345, 60), 96, 48, 0, 0);
	EyeIcon[0]->SetColorKey(RGB(255, 0, 255));

	EyeIcon[1] = new CButtonBase;
	EyeIcon[1]->Initialize();
	EyeIcon[1]->Load("./Images/ui_main/1_3.bmp");
	EyeIcon[1]->SetPos(Vector2D(345, 60));
	EyeIcon[1]->SetColorKey(RGB(255, 0, 255));

	EyeIcon[2] = new CButtonBase;
	EyeIcon[2]->Initialize();
	EyeIcon[2]->Load("./Images/ui_main/1_2.bmp");
	EyeIcon[2]->SetPos(Vector2D(345, 60));
	EyeIcon[2]->SetColorKey(RGB(255, 0, 255));


	MouthIcon[0] = new CButtonBase;
	MouthIcon[0]->Initialize();
	MouthIcon[0]->Load("./Images/ui_main/3_1.bmp");
	MouthIcon[0]->SetPosAndSize(Vector2D(345, 110), 96, 48, 0, 0);
	MouthIcon[0]->SetColorKey(RGB(255, 0, 255));

	MouthIcon[1] = new CButtonBase;
	MouthIcon[1]->Initialize();
	MouthIcon[1]->Load("./Images/ui_main/3_3.bmp");
	MouthIcon[1]->SetPos(Vector2D(345, 110));
	MouthIcon[1]->SetColorKey(RGB(255, 0, 255));

	MouthIcon[2] = new CButtonBase;
	MouthIcon[2]->Initialize();
	MouthIcon[2]->Load("./Images/ui_main/3_2.bmp");
	MouthIcon[2]->SetPos(Vector2D(345, 110));
	MouthIcon[2]->SetColorKey(RGB(255, 0, 255));

	HairIcon[0] = new CButtonBase;
	HairIcon[0]->Initialize();
	HairIcon[0]->Load("./Images/ui_main/4_1.bmp");
	HairIcon[0]->SetPosAndSize(Vector2D(345, 160), 96, 48, 0, 0);
	HairIcon[0]->SetColorKey(RGB(255, 0, 255));

	HairIcon[1] = new CButtonBase;
	HairIcon[1]->Initialize();
	HairIcon[1]->Load("./Images/ui_main/4_3.bmp");
	HairIcon[1]->SetPos(Vector2D(345, 160));
	HairIcon[1]->SetColorKey(RGB(255, 0, 255));

	HairIcon[2] = new CButtonBase;
	HairIcon[2]->Initialize();
	HairIcon[2]->Load("./Images/ui_main/4_2.bmp");
	HairIcon[2]->SetPos(Vector2D(345, 160));
	HairIcon[2]->SetColorKey(RGB(255, 0, 255));

	ClothesIcon[0] = new CButtonBase;
	ClothesIcon[0]->Initialize();
	ClothesIcon[0]->Load("./Images/ui_main/5_1.bmp");
	ClothesIcon[0]->SetPosAndSize(Vector2D(345, 210), 96, 48, 0, 0);
	ClothesIcon[0]->SetColorKey(RGB(255, 0, 255));

	ClothesIcon[1] = new CButtonBase;
	ClothesIcon[1]->Initialize();
	ClothesIcon[1]->Load("./Images/ui_main/5_3.bmp");
	ClothesIcon[1]->SetPos(Vector2D(345, 210));
	ClothesIcon[1]->SetColorKey(RGB(255, 0, 255));

	ClothesIcon[2] = new CButtonBase;
	ClothesIcon[2]->Initialize();
	ClothesIcon[2]->Load("./Images/ui_main/5_2.bmp");
	ClothesIcon[2]->SetPos(Vector2D(345, 210));
	ClothesIcon[2]->SetColorKey(RGB(255, 0, 255));

	ShoesIcon[0] = new CButtonBase;
	ShoesIcon[0]->Initialize();
	ShoesIcon[0]->Load("./Images/ui_main/6_1.bmp");
	ShoesIcon[0]->SetPosAndSize(Vector2D(345, 260), 96, 48, 0, 0);
	ShoesIcon[0]->SetColorKey(RGB(255, 0, 255));

	ShoesIcon[1] = new CButtonBase;
	ShoesIcon[1]->Initialize();
	ShoesIcon[1]->Load("./Images/ui_main/6_3.bmp");
	ShoesIcon[1]->SetPos(Vector2D(345, 260));
	ShoesIcon[1]->SetColorKey(RGB(255, 0, 255));

	ShoesIcon[2] = new CButtonBase;
	ShoesIcon[2]->Initialize();
	ShoesIcon[2]->Load("./Images/ui_main/6_2.bmp");
	ShoesIcon[2]->SetPos(Vector2D(345, 260));
	ShoesIcon[2]->SetColorKey(RGB(255, 0, 255));


	Body = new CBaseRender;
	Body->Initialize();
	Body->Load("./Images/Character/body.bmp");

	Body->SetPos(Vector2D(80, 30));
	Body->SetPos(Vector2D(80, 50));
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

	
		if (IsMain)
		{
			MainGame->Render();
			Start[0]->Render();
			Exit[0]->Render();

		}


		if (!IsMain)
		{




			Stage->Render();


			EyeIcon[0]->Render();
			if (PtInRect(&EyeIcon[0]->rc, m_vMouseXY))
			{
				EyeIcon[1]->Render();
				if(m_bIsMouseLeft)
				{
					EyeIcon[2]->Render();
				}
			}

			MouthIcon[0]->Render();
			if (PtInRect(&MouthIcon[0]->rc, m_vMouseXY))
			{
				MouthIcon[1]->Render();
				if (m_bIsMouseLeft)
				{
					MouthIcon[2]->Render();
				}
			}

			HairIcon[0]->Render();
			if (PtInRect(&HairIcon[0]->rc, m_vMouseXY))
			{
				HairIcon[1]->Render();
				if (m_bIsMouseLeft)
				{
					HairIcon[2]->Render();
				}
			}
			ClothesIcon[0]->Render();
			if (PtInRect(&ClothesIcon[0]->rc, m_vMouseXY))
			{
				ClothesIcon[1]->Render();
				if (m_bIsMouseLeft)
				{
					ClothesIcon[2]->Render();
				}
			}
			ShoesIcon[0]->Render();
			if (PtInRect(&ShoesIcon[0]->rc, m_vMouseXY))
			{
				ShoesIcon[1]->Render();
				if (m_bIsMouseLeft)
				{
					ShoesIcon[2]->Render();
				}
			}



		}

		

	
		if (PtInRect(&Start[0]->rc, m_vMouseXY))   //스타트 버튼 체크 
		{
			Start[1]->Render();
			if (m_bIsMouseLeft)
			{
			
				Start[2]->Render();
				IsMain = false;
				Start[0]->Terminate();
				Start[1]->Terminate();
				Start[2]->Terminate();
				 Exit[0]->Terminate();
				 Exit[1]->Terminate();
				 Exit[2]->Terminate();
			}
		}

		if (PtInRect(&Exit[0]->rc, m_vMouseXY))
		{
			Exit[1]->Render();
			if (m_bIsMouseLeft)
			{
				PostQuitMessage(0);
			}
		}


		


		

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
	Stage->Terminate();

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

