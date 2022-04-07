#pragma once

//----- GDI+ Image 사용을 위한 헤더 추가
#include <ole2.h>      
#include <gdiplus.h>
#pragma comment(lib, "Gdiplus.lib")
using namespace Gdiplus;
//----- GDI+ Image 사용을 위한 헤더 추가

#include "Vector2D.h"
#include <vector>
using namespace std;


class CInGameScene
{
	Image* m_ReadyMsg[79];
	Image* m_HPBarBody;
	Image* m_HpBar;
	float m_HpBarImgWidth;
	float m_HpBarImgHeight;

	Image* m_Map;
	float m_MapImgWidth;
	float m_MapImgHeight;

	HDC		m_BGImgDC;
	HBITMAP m_hTexImgBMP;	//로딩된 BMP파일의 핸들
	int		m_TexImgWidth;	//이미지의 가로 사이즈
	int		m_TexImgHeight;	//이미지의 세로 사이즈

	HDC		m_MapImgDC;
	HBITMAP m_hTexImgBMP2;		//로딩된 BMP파일의 핸들
	int		m_TexImgWidth2;		//이미지의 가로 사이즈
	int		m_TexImgHeight2;	//이미지의 세로 사이즈

	int ImgNum = 0;
	bool GameReady = false;

public:
	vector<Image*> m_MapImg;
	Vector2D m_MapImgPos[100];
public:
	CInGameScene();
	~CInGameScene();

	void Ingame_Init(HWND a_hWnd);
	void Ingame_Update(HWND a_hWnd, float a_DeltaTime);
	void Ingame_Render(HDC a_MainDC, RECT& a_RT);
	void Ingame_Destroy();
};

extern CInGameScene g_Ingame_Mgr;
