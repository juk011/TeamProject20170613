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

	RightArrow[0] = new CButtonBase;
	RightArrow[0]->Initialize();
	RightArrow[0]->Load("./Images/ui_main/7_1.bmp");
	RightArrow[0]->SetPosAndSize(Vector2D(700, 230), 38, 49, 0, 0);
	RightArrow[0]->SetColorKey(RGB(252, 0, 255));

	RightArrow[1] = new CButtonBase;
	RightArrow[1]->Initialize();
	RightArrow[1]->Load("./Images/ui_main/7_2.bmp");
	RightArrow[1]->SetPos(Vector2D(693, 230));
	RightArrow[1]->SetColorKey(RGB(252, 0, 255));
	
	RightArrow[2] = new CButtonBase;
	RightArrow[2]->Initialize();
	RightArrow[2]->Load("./Images/ui_main/7_3.bmp");
	RightArrow[2]->SetPos(Vector2D(700, 230));
	RightArrow[2]->SetColorKey(RGB(252, 0, 255));

	LeftArrow[0] = new CButtonBase;
	LeftArrow[0]->Initialize();
	LeftArrow[0]->Load("./Images/ui_main/8_1.bmp");
	LeftArrow[0]->SetPosAndSize(Vector2D(450, 230), 38, 49, 0, 0);
	LeftArrow[0]->SetColorKey(RGB(252, 0, 255));

	LeftArrow[1] = new CButtonBase;
	LeftArrow[1]->Initialize();
	LeftArrow[1]->Load("./Images/ui_main/8_2.bmp");
	LeftArrow[1]->SetPosAndSize(Vector2D(450, 230), 38, 49, 0, 0);
	LeftArrow[1]->SetColorKey(RGB(252, 0, 255));
	
	LeftArrow[2] = new CButtonBase;
	LeftArrow[2]->Initialize();
	LeftArrow[2]->Load("./Images/ui_main/8_3.bmp");
	LeftArrow[2]->SetPosAndSize(Vector2D(450, 230), 38, 49, 0, 0);
	LeftArrow[2]->SetColorKey(RGB(252, 0, 255));

	Body = new CBaseRender;
	Body->Initialize();
	Body->Load("./Images/Character/Body.bmp");
	Body->SetPos(Vector2D(80, 50));
	Body->SetColorKey(RGB(255, 0, 255));

	Eye[0] = new CButtonBase;
	Eye[0]->Initialize();
	Eye[0]->Load("./Images/Character/eye/chicken_eye.bmp");
	Eye[0]->SetPos(Vector2D(80, 50));
	Eye[0]->SetColorKey(RGB(255, 0, 255));

	Eye[1] = new CButtonBase;
	Eye[1]->Initialize();
	Eye[1]->Load("./Images/Character/eye/doughnut_eye.bmp");
	Eye[1]->SetPos(Vector2D(80, 50));
	Eye[1]->SetColorKey(RGB(255, 0, 255));

	Eye[2] = new CButtonBase;
	Eye[2]->Initialize();
	Eye[2]->Load("./Images/Character/eye/sea_eye.bmp");
	Eye[2]->SetPos(Vector2D(80, 50));
	Eye[2]->SetColorKey(RGB(255, 0, 255));

	EyeHG[0] = new CEye;
	EyeHG[0]->Initialize();
	EyeHG[0]->Load("./Images/choose_Character/eye/chicken_eye.bmp");
	EyeHG[0]->SetPos(Vector2D(500, 50));
	EyeHG[0]->SetColorKey(RGB(255, 12, 255));


	EyeHG[1] = new CEye;
	EyeHG[1]->Initialize();
	EyeHG[1]->Load("./Images/choose_Character/eye/doughnut_eye.bmp");
    EyeHG[1]->SetPos(Vector2D(500, 50));
    EyeHG[1]->SetColorKey(RGB(255, 12, 255));

	EyeHG[2] = new CEye;
	EyeHG[2]->Initialize();
	EyeHG[2]->Load("./Images/choose_Character/eye/sea_eye.bmp");
    EyeHG[2]->SetPos(Vector2D(500, 50));
	EyeHG[2]->SetColorKey(RGB(255, 12, 255));

	HairHG[0] = new CHair;
	HairHG[0]->Initialize();
	HairHG[0]->Load("./Images/choose_Character/hair/chicken_hair.bmp");
	HairHG[0]->SetPos(Vector2D(500, 50));
	HairHG[0]->SetColorKey(RGB(255, 12, 255));

	HairHG[1] = new CHair;
	HairHG[1]->Initialize();
	HairHG[1]->Load("./Images/choose_Character/hair/doughnut_hair.bmp");
	HairHG[1]->SetPos(Vector2D(500, 50));
	HairHG[1]->SetColorKey(RGB(255, 12, 255));

	HairHG[2] = new CHair;
	HairHG[2]->Initialize();
	HairHG[2]->Load("./Images/choose_Character/hair/sea_hair.bmp");
	HairHG[2]->SetPos(Vector2D(500, 50));
	HairHG[2]->SetColorKey(RGB(255, 12, 255));

	LipHG[0] = new CLip;
	LipHG[0]->Initialize();
	LipHG[0]->Load("./Images/choose_Character/lips/chicken_lips.bmp");
	LipHG[0]->SetPos(Vector2D(500, 50));
	LipHG[0]->SetColorKey(RGB(255, 12, 255));

	LipHG[1] = new CLip;
	LipHG[1]->Initialize();
	LipHG[1]->Load("./Images/choose_Character/lips/doughnut_lips.bmp");
	LipHG[1]->SetPos(Vector2D(500, 50));
	LipHG[1]->SetColorKey(RGB(255, 12, 255));

	LipHG[2] = new CLip;
	LipHG[2]->Initialize();
	LipHG[2]->Load("./Images/choose_Character/lips/sea_lips.bmp");
	LipHG[2]->SetPos(Vector2D(500, 50));
	LipHG[2]->SetColorKey(RGB(255, 12, 255));

	ClothesHG[0] = new CClothes;
	ClothesHG[0]->Initialize();
	ClothesHG[0]->Load("./Images/choose_Character/clothe/chicken_clothes.bmp");
	ClothesHG[0]->SetPos(Vector2D(500, 50));
	ClothesHG[0]->SetColorKey(RGB(255, 12, 255));

	ClothesHG[1] = new CClothes;
	ClothesHG[1]->Initialize();
	ClothesHG[1]->Load("./Images/choose_Character/clothe/doughnut_clothes.bmp");
	ClothesHG[1]->SetPos(Vector2D(500, 50));
	ClothesHG[1]->SetColorKey(RGB(255, 12, 255));

	ClothesHG[2] = new CClothes;
	ClothesHG[2]->Initialize();
	ClothesHG[2]->Load("./Images/choose_Character/clothe/sea_clothes.bmp");
	ClothesHG[2]->SetPos(Vector2D(500, 50));
	ClothesHG[2]->SetColorKey(RGB(255, 12, 255));

	ShoesHG[0] = new CShoes;
	ShoesHG[0]->Initialize();
	ShoesHG[0]->Load("./Images/choose_Character/shoes/chicken_shoes.bmp");
	ShoesHG[0]->SetPos(Vector2D(500, 50));
	ShoesHG[0]->SetColorKey(RGB(255, 12, 255));

	ShoesHG[1] = new CShoes;
	ShoesHG[1]->Initialize();
	ShoesHG[1]->Load("./Images/choose_Character/shoes/doughnut_shoes.bmp");
	ShoesHG[1]->SetPos(Vector2D(500, 50));
	ShoesHG[1]->SetColorKey(RGB(255, 12, 255));

	ShoesHG[2] = new CShoes;
	ShoesHG[2]->Initialize();
	ShoesHG[2]->Load("./Images/choose_Character/shoes/sea_shoes.bmp");
	ShoesHG[2]->SetPos(Vector2D(500, 50));
	ShoesHG[2]->SetColorKey(RGB(255, 12, 255));

	imageKinds = 0; // 1 눈, 2 입, 3 머리, 4 옷, 5 신발

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

	
		if (IsMain) // 메인화면
		{
			MainGame->Render();
			Start[0]->Render();
			Exit[0]->Render();

		}
		else // 게임 실행 화면
		{
			Stage->Render();

		    Body->Render();

			RightArrow[0]->Render();
	
			if (PtInRect(&RightArrow[0]->rc, m_vMouseXY))
			{
				RightArrow[1]->Render();
				if (m_bIsMouseLeft)
				{
					RightArrow[2]->Render();
					switch (imageKinds)
					{
					case 1:
						if (EyeHG[0]->IsActive == true)
						{
							EyeHG[0]->IsActive = false;
							EyeHG[1]->IsActive = true;
							Sleep(150);
						}
						else if (EyeHG[1]->IsActive == true)
						{
							EyeHG[1]->IsActive = false;
							EyeHG[2]->IsActive = true;
						}
						break;
					case 2:
						if (LipHG[0]->IsActive == true)
						{
							LipHG[0]->IsActive = false;
							LipHG[1]->IsActive = true;
							Sleep(150);
						}
						else if (LipHG[1]->IsActive == true)
						{
							LipHG[1]->IsActive = false;
							LipHG[2]->IsActive = true;
						}
						break;
					case 3:
						if (HairHG[0]->IsActive == true)
						{
							HairHG[0]->IsActive = false;
							HairHG[1]->IsActive = true;
							Sleep(150);
						}
						else if (HairHG[1]->IsActive == true)
						{
							HairHG[1]->IsActive = false;
							HairHG[2]->IsActive = true;
						}
						break;
					case 4:
						if (ClothesHG[0]->IsActive == true)
						{
							ClothesHG[0]->IsActive = false;
							ClothesHG[1]->IsActive = true;
							Sleep(150);
						}
						else if (ClothesHG[1]->IsActive == true)
						{
							ClothesHG[1]->IsActive = false;
							ClothesHG[2]->IsActive = true;
						}
						break;
					case 5:
						if (ShoesHG[0]->IsActive == true)
						{
							ShoesHG[0]->IsActive = false;
							ShoesHG[1]->IsActive = true;
							Sleep(150);
						}
						else if (ShoesHG[1]->IsActive == true)
						{
							ShoesHG[1]->IsActive = false;
							ShoesHG[2]->IsActive = true;
						}
						break;
					}	
				}
			}

			LeftArrow[0]->Render();
			if (PtInRect(&LeftArrow[0]->rc, m_vMouseXY))
			{
				LeftArrow[1]->Render();
				if (m_bIsMouseLeft)
				{
					LeftArrow[2]->Render();
					switch (imageKinds)
					{
					case 1:
						if (EyeHG[2]->IsActive == true)
						{
							EyeHG[2]->IsActive = false;
							EyeHG[1]->IsActive = true;
							Sleep(150);
						}
						else if (EyeHG[1]->IsActive == true)
						{
							EyeHG[1]->IsActive = false;
							EyeHG[0]->IsActive = true;
						}
						break;
					case 2:
						if (LipHG[2]->IsActive == true)
						{
							LipHG[2]->IsActive = false;
							LipHG[1]->IsActive = true;
							Sleep(150);
						}
						else if (LipHG[1]->IsActive == true)
						{
							LipHG[1]->IsActive = false;
							LipHG[0]->IsActive = true;
						}
						break;
					case 3:
						if (HairHG[2]->IsActive == true)
						{
							HairHG[2]->IsActive = false;
							HairHG[1]->IsActive = true;
							Sleep(150);
						}
						else if (HairHG[1]->IsActive == true)
						{
							HairHG[1]->IsActive = false;
							HairHG[0]->IsActive = true;
						}
						break;
					case 4:
						if (ClothesHG[2]->IsActive == true)
						{
							ClothesHG[2]->IsActive = false;
							ClothesHG[1]->IsActive = true;
							Sleep(150);
						}
						else if (ClothesHG[1]->IsActive == true)
						{
							ClothesHG[1]->IsActive = false;
							ClothesHG[0]->IsActive = true;
						}
						break;
					case 5:
						if (ShoesHG[2]->IsActive == true)
						{
							ShoesHG[2]->IsActive = false;
							ShoesHG[1]->IsActive = true;
							Sleep(150);
						}
						else if (ShoesHG[1]->IsActive == true)
						{
							ShoesHG[1]->IsActive = false;
							ShoesHG[0]->IsActive = true;
						}
						break;
					}
				}
			}

			EyeIcon[0]->Render();
			if (PtInRect(&EyeIcon[0]->rc, m_vMouseXY))
			{	
				EyeIcon[1]->Render();
				if (m_bIsMouseLeft)
				{
					imageKinds = 1;
					reset();
					EyeHG[0]->IsActive = true;
					EyeIcon[2]->Render();
				}
			}
		
			MouthIcon[0]->Render();
			if (PtInRect(&MouthIcon[0]->rc, m_vMouseXY))
			{			
				MouthIcon[1]->Render();
				if (m_bIsMouseLeft)
				{
					imageKinds = 2;
					reset();
					LipHG[0]->IsActive = true;
					MouthIcon[2]->Render();
				}
			}

			HairIcon[0]->Render();
			if (PtInRect(&HairIcon[0]->rc, m_vMouseXY))
			{
				HairIcon[1]->Render();
				if (m_bIsMouseLeft)
				{	
					imageKinds = 3;
					reset();
					HairHG[0]->IsActive = true;
					HairIcon[2]->Render();
				}
			}

			ClothesIcon[0]->Render();
			if (PtInRect(&ClothesIcon[0]->rc, m_vMouseXY))
			{
				ClothesIcon[1]->Render();
				if (m_bIsMouseLeft)
				{
					imageKinds = 4;
					reset();
					ClothesHG[0]->IsActive = true;
					ClothesIcon[2]->Render();
				}
			}

			ShoesIcon[0]->Render();
			if (PtInRect(&ShoesIcon[0]->rc, m_vMouseXY))
			{
				ShoesIcon[1]->Render();
				if (m_bIsMouseLeft)
				{
					imageKinds = 5;
					reset();
					ShoesHG[0]->IsActive = true;
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

		HairHG[0]->Render();
		HairHG[1]->Render();
		HairHG[2]->Render();
		EyeHG[0]->Render();
		EyeHG[1]->Render();
		EyeHG[2]->Render();
		LipHG[0]->Render();
		LipHG[1]->Render();
		LipHG[2]->Render();
		ClothesHG[0]->Render();
		ClothesHG[1]->Render(); 
		ClothesHG[2]->Render();
		ShoesHG[0]->Render();
		ShoesHG[1]->Render();
		ShoesHG[2]->Render();

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

void CSystem::reset(void)
{
	for (int i = 0; i<3; i++)
		EyeHG[i]->IsActive = false;

	for (int i = 0; i<3; i++)
		LipHG[i]->IsActive = false;

	for (int i = 0; i<3; i++)
		HairHG[i]->IsActive = false;

	for (int i = 0; i < 3; i++)
		ClothesHG[i]->IsActive = false;

	for (int i = 0; i < 3; i++)
		ShoesHG[i]->IsActive = false;
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

