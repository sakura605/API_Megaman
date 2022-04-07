#pragma once
class CBackGround
{
	HDC		m_BGImgDC;
	HBITMAP m_hTexImgBMP;	//로딩된 BMP파일의 핸들
	int		m_TexImgWidth;	//이미지의 가로 사이즈
	int		m_TexImgHeight;	//이미지의 세로 사이즈

public:
	CBackGround();
	~CBackGround();

public:
	void BG_Init(HWND a_hWnd);	//초기화 함수
	void BG_Update();
	void BG_Render(HDC a_hdc, RECT& a_RT);
	void BG_Destroy();
};

extern CBackGround g_BGround;