#include "StdAfx.h"
#include "Shoes.h"


CShoes::CShoes(void)
{
	m_eRenderType = eRenderType::eRenderType_Image;
	m_nImageID = -1;
	m_ColorKey = RGB(0, 0, 0);
	IsActive = false;
}


CShoes::~CShoes(void)
{
}


bool CShoes::Initialize()
{
	return true;
}

void CShoes::Terminate()
{
}

bool CShoes::Pulse()
{
	return true;
}

void CShoes::Render()
{
	if (IsActive)
	{

		HDC m_hdcImage = g_pImageManager->FindImage(m_nImageID);
		int w = g_pImageManager->GetBmpInfo(m_nImageID)->bmWidth;
		int h = g_pImageManager->GetBmpInfo(m_nImageID)->bmHeight;
		HDC hdc = g_pGdi->GetDrawDC();

		if (m_hdcImage)
		{
			switch (m_eRenderType)
			{
			case eRenderType::eRenderType_Image:
				BitBlt(hdc, m_vPos.x, m_vPos.y, w, h, m_hdcImage, 0, 0, SRCCOPY);
				break;
			case eRenderType::eRenderType_Sprite:
				TransparentBlt(hdc, m_vPos.x, m_vPos.y, w, h, m_hdcImage, 0, 0, w, h, m_ColorKey);
				break;
			default:
				break;
			}
		}
	}
}

bool CShoes::Load(const char* szURL)
{
	m_nImageID = g_pImageManager->ImageLoad(szURL);

	if (m_nImageID == -1)
	{
		return false;
	}

	return true;
}

