#pragma once
class CClothes
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
	CClothes(void);
	virtual ~CClothes(void);

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

__inline void CClothes::SetPos(Vector2D vPos)
{
	m_vPos = vPos;
}

__inline void CClothes::SetColorKey(COLORREF crKey)
{
	m_eRenderType = eRenderType::eRenderType_Sprite;
	m_ColorKey = crKey;
}

__inline Vector2D CClothes::GetPos() const
{
	return m_vPos;
}


