#pragma once
class CButtonBase
{
public:
	enum eRenderType
	{
		eRenderType_Unknown,
		eRenderType_Image,
		eRenderType_Sprite,
	};
public:
	eRenderType m_eRenderType;

	int m_nImageID;
	Vector2D m_vPos;
	

	COLORREF m_ColorKey;
	RECT rc;

public:
	CButtonBase(void);
	virtual ~CButtonBase(void);

	bool Load(const char* szURL);

	virtual bool Initialize();
	virtual void Terminate();
	virtual bool Pulse();
	virtual void Render();


public:
	__inline void SetPos(Vector2D vPos);
	__inline void SetPosAndSize(Vector2D vPos, int width, int height, int xPos, int yPos);
	__inline void SetColorKey(COLORREF crKey);
	__inline Vector2D GetPos() const;

};

__inline void CButtonBase::SetPos(Vector2D vPos)
{
	m_vPos = vPos;
}



__inline void CButtonBase::SetColorKey(COLORREF crKey)
{
	m_eRenderType = eRenderType::eRenderType_Sprite;
	m_ColorKey = crKey;
}

__inline Vector2D CButtonBase::GetPos() const
{
	return m_vPos;
}

__inline RECT RectMake(int x, int y, int width, int height)
{
	RECT rc;
	rc.left = x;
	rc.right = x + width;
	rc.top = y;
	rc.bottom = y + height;
	return rc;
}

__inline void CButtonBase::SetPosAndSize(Vector2D vPos, int width, int height, int xPos, int yPos)
{
	m_vPos = vPos;
	rc = RectMake(vPos.x+xPos, vPos.y+yPos, width, height);
}

