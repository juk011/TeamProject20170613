#pragma once
class CHair
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

	bool IsActive;

public:
	CHair(void);
	virtual ~CHair(void);

	bool Load(const char* szURL);

	virtual bool Initialize();
	virtual void Terminate();
	virtual bool Pulse();
	virtual void Render();

public:
	__inline void SetPos(Vector2D vPos);
	__inline void SetColorKey(COLORREF crKey);
	__inline Vector2D GetPos() const;
};

__inline void CHair::SetPos(Vector2D vPos)
{
	m_vPos = vPos;
}

__inline void CHair::SetColorKey(COLORREF crKey)
{
	m_eRenderType = eRenderType::eRenderType_Sprite;
	m_ColorKey = crKey;
}

__inline Vector2D CHair::GetPos() const
{
	return m_vPos;
}


