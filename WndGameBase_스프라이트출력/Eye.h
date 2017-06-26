#pragma once
class CEye
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
	CEye(void);
	virtual ~CEye(void);

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

__inline void CEye::SetPos(Vector2D vPos)
{
	m_vPos = vPos;
}

__inline void CEye::SetColorKey(COLORREF crKey)
{
	m_eRenderType = eRenderType::eRenderType_Sprite;
	m_ColorKey = crKey;
}

__inline Vector2D CEye::GetPos() const
{
	return m_vPos;
}


