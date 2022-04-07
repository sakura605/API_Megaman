#pragma once
#include "CAnimData.h"
class CMyMain
{
	HWND		m_hWnd = NULL;
	RECT		m_Rect;
	ULONG_PTR	m_gdiplusToken = NULL;

	//----------------BackDC ������ ����
	HDC		m_hBackDC = NULL;
	HBITMAP	m_hBackBitmap = NULL;
	//----------------BackDC ������ ����

	//----------------��Ÿ Ÿ���� ��� ���� ����
	float m_DeltaTime;
	DWORD m_LastTime = 0;
	DWORD m_CurTime = 0;
	//----------------��Ÿ Ÿ���� ��� ���� ����

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

