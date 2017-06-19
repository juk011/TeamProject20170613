#pragma once

class CFrameSkip;

class CSystem : public CSingleton<CSystem>,
	            public CBaseWindow,
				public CTimeManager,
				public IInputHandler
{
private:
	bool m_bIsReady;						// 시작하기전 대기.
	CFrameSkip*		m_pGameFrame;
	CInputManager*	m_pInputManager;
	CImageManager*	m_pImageManager;

private:
	Vector2D	m_vMouseXY;
	bool m_bIsMouseLeft;
	bool m_bIsMouseRight;
	bool m_bIsMouseMid;
public:                 //여기서 그림생성
	CBaseRender* m_pImage;
	CBaseRender* m_pSprite;
	CBaseRender* Body;
<<<<<<< HEAD
=======
	CBaseRender* EyeIcon;
	CBaseRender* MouthIcon;
	CBaseRender* HairIcon;
	CBaseRender* ClothesIcon;
	CBaseRender* ShoesIcon;
>>>>>>> bb4c5cb8cdcf1f3b8ceea5115aefc20d31051fff


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
