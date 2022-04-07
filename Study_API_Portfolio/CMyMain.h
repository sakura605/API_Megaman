#pragma once
#include "CAnimData.h"
class CMyMain
{
	HWND		m_hWnd = NULL;
	RECT		m_Rect;
	ULONG_PTR	m_gdiplusToken = NULL;

	//----------------BackDC 생성용 변수
	HDC		m_hBackDC = NULL;
	HBITMAP	m_hBackBitmap = NULL;
	//----------------BackDC 생성용 변수

	//----------------델타 타임을 얻기 위한 변수
	float m_DeltaTime;
	DWORD m_LastTime = 0;
	DWORD m_CurTime = 0;
	//----------------델타 타임을 얻기 위한 변수

public:
	vector<CAnimData*> m_CharAniList;

public:
	CMyMain();
	~CMyMain();

	void MainInit(HWND hWnd);
	void MainUpdate(HWND hWnd);
	void MainRender(HWND hWnd);
	void MainDestroy();
};

extern CMyMain g_CMyMain;

