#pragma once

class CFrameSkip;
class CButtonBase;

class CSystem : public CSingleton<CSystem>,
	            public CBaseWindow,
				public CTimeManager,
				public IInputHandler
{
private:
	bool m_bIsReady;	  // 시작하기전 대기.	
	bool IsMain;   
	CFrameSkip*		m_pGameFrame;
	CInputManager*	m_pInputManager;
	CImageManager*	m_pImageManager;

private:
	Vector2D	m_vMouseXY;
	bool m_bIsMouseLeft;
	bool m_bIsMouseRight;
	bool m_bIsMouseMid;
public:                 //여기서 그림생성
	CBaseRender* Stage;
	CBaseRender* m_pSprite;
	CBaseRender* Body;
	CBaseRender* MainGame;

	CButtonBase* Eye[3];
	CButtonBase* Mouth[3];
	CButtonBase* Hair[3];
	CButtonBase* Clothes[3];
	CButtonBase* Shoes[3];

	CButtonBase* EyeHG[3];
	CButtonBase* MouthHG[3];
	CButtonBase* HairHG[3];
	CButtonBase* ClothesHG[3];
	CButtonBase* ShoesHG[3];

	CButtonBase* Start[3];
	CButtonBase* Exit[3];

	CButtonBase* LeftArrow[3];
	CButtonBase* RightArrow[3];
	CButtonBase* EyeIcon[3];
	CButtonBase* MouthIcon[3];
	CButtonBase* HairIcon[3];
	CButtonBase* ClothesIcon[3];
	CButtonBase* ShoesIcon[3];

public:
	CSystem(void);
	virtual ~CSystem(void);

public:
	bool Initialize(void);
	void Update(void);
	void Terminate(void);
	void Run(void);
public:
	inline void SetReady(bool bIsReady) {	m_bIsReady = bIsReady;  }

private:
	void KeyboardHandler();
	void MouseHandler(MOUSESTATE diMouseState);
};

#define g_pSystem	CSystem::GetSingleton()

#define NORMAL  0  //기본상태
#define OVERLAP 1  //마우스와 겹침
#define CLIKED  2  //마우스 클릭됨 
 
