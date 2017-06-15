#pragma once
class CBaseRender
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

public:
	CBaseRender(void);
	virtual ~CBaseRender(void);

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

__inline void CBaseRender::SetPos(Vector2D vPos)
{
	m_vPos = vPos;
}

__inline void CBaseRender::SetColorKey(COLORREF crKey)
{
	m_eRenderType = eRenderType::eRenderType_Sprite;
	m_ColorKey = crKey;
}

__inline Vector2D CBaseRender::GetPos() const
{
	return m_vPos;
}
