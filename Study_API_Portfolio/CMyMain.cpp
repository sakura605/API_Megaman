#include "stdafx.h"
#include "CMyMain.h"
#include "CBackGround.h"
#include "CUI_Manager.h"
#include "CInGameScene.h"
#include "CZero_Mgr.h"
#include "GlobalValue.h"

//--------DeltaTime�� ���� ���
#include <mmsystem.h>
#include <time.h>
#include <stdlib.h>
#pragma comment(lib, "winmm.lib")
//--------DeltaTime�� ���� ���

//--------GDI+ Image ����� ���� ��� �߰�
#include <Ole2.h>
#include <gdiplus.h>
#pragma comment(lib, "Gdiplus.lib")
using namespace Gdiplus;
//--------GDI+ Image ����� ���� ��� �߰�
CMyMain g_CMyMain;

CMyMain::CMyMain()
{
}


CMyMain::~CMyMain()
{
}

void CMyMain::MainInit(HWND hWnd)
{
	m_hWnd = hWnd;

	srand((unsigned)time(NULL));

	GetClientRect(hWnd, &m_Rect);

	m_LastTime = timeGetTime();	//���� �ð� ��������

	//---------- GDI+ �ʱ�ȭ
	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);
	//---------- GDI+ �ʱ�ȭ

	//---------- �ĸ� BackDC����
	HDC hdc = GetDC(hWnd);						//���� DC��������
	m_hBackDC = CreateCompatibleDC(hdc);		//����DC�� �ֵ��� ���纻�� �����.
	m_hBackBitmap = CreateCompatibleBitmap(hdc, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
												//BackDC�� �ٿ��� ��Ʈ�� �̹����� �ϳ� �����.
	SelectObject(m_hBackDC, m_hBackBitmap);		//BackDC�� Bitmap(�̹���)�� �ٿ��ش�.
	ReleaseDC(hWnd, hdc);
	//---------- �ĸ� BackDC����
	
	for (int ii = 0; ii < Type_Length; ii++)
	{
		CAnimData* a_Node = new CAnimData();
		a_Node->LoadAnimList((Ani_Type)ii);
 		m_CharAniList.push_back(a_Node);
	}

	//---------��׶��� �ʱ�ȭ
	g_BGround.BG_Init(hWnd);
	//---------��׶��� �ʱ�ȭ

	//---------UI �Ŵ��� �ʱ�ȭ
	g_GUI_Mgr.UIMgr_Init();
	//---------UI �Ŵ��� �ʱ�ȭ

	//--------�ΰ��� �Ŵ��� �ʱ�ȭ
	g_Ingame_Mgr.Ingame_Init(hWnd);
	//--------�ΰ��� �Ŵ��� �ʱ�ȭ

	//--------ĳ���� �Ŵ��� �ʱ�ȭ
	g_Zero.Init_Unit(hWnd);
	//--------ĳ���� �Ŵ��� �ʱ�ȭ
}

void CMyMain::MainUpdate(HWND hWnd)
{
	//DeltaTime ������ ���
	timeBeginPeriod(1);
	m_CurTime = timeGetTime();
	m_DeltaTime = ((m_CurTime - m_LastTime) * 0.001);
	m_LastTime = m_CurTime;
	timeEndPeriod(1);
	//DeltaTime ������ ���

	if (m_hBackDC == NULL)
		return;

	GetClientRect(hWnd, &m_Rect);

	if (g_GameState == GAME_MENU)
	{
		//---------UI �Ŵ��� ������Ʈ
		g_GUI_Mgr.UIMgr_Update(hWnd, m_DeltaTime);
		//---------UI �Ŵ��� ������Ʈ
	}

	else if (g_GameState == GAME_START)
	{
		g_Ingame_Mgr.Ingame_Update(hWnd, m_DeltaTime);

		//--------ĳ���� �Ŵ��� ������Ʈ
		g_Zero.Update_Unit(hWnd, m_DeltaTime, m_Rect);
		//--------ĳ���� �Ŵ��� ������Ʈ
	}
}

void CMyMain::MainRender(HWND hWnd)
{
	if (m_hBackDC == NULL)
		return;
	if (g_GameState == GAME_MENU)
	{
		//------------��׶��� ����
		g_BGround.BG_Render(m_hBackDC, m_Rect);
		//------------��׶��� ����

		//---------UI �Ŵ��� ����
		g_GUI_Mgr.UIMgr_Render(m_hBackDC, m_Rect);
		//---------UI �Ŵ��� ����
	}

	else if (g_GameState == GAME_START)
	{
		g_Ingame_Mgr.Ingame_Render(m_hBackDC, m_Rect);

		//--------ĳ���� �Ŵ��� ����
		g_Zero.Render_Unit(m_hBackDC);
		//--------ĳ���� �Ŵ��� ����
	}


	//--------------���� ���۸�
	static HDC hdc;
	hdc = GetDC(hWnd);
	//ȭ�� ��ȯ
	BitBlt(hdc, 0, 0, m_Rect.right, m_Rect.bottom, m_hBackDC, 0, 0, SRCCOPY);
	//ȭ�� ��ȯ
	ReleaseDC(hWnd, hdc);
	//--------------���� ���۸�
}

void CMyMain::MainDestroy()
{
	//----------��׶��� ����
	g_BGround.BG_Destroy();
	//----------��׶��� ����

	//-------- GUI �����...
	g_GUI_Mgr.UIMgr_Destroy();
	//-------- GUI �����...

	//-------- �ΰ��Ӿ� �����
	g_Ingame_Mgr.Ingame_Destroy();
	//-------- �ΰ��Ӿ� �����

	//------ĳ���� �Ŵ��� �����
	g_Zero.Destroy_Unit();
	//------ĳ���� �Ŵ��� �����

	//------------------�ĸ� BackDC ����
	if (m_hBackBitmap != NULL)
	{
		DeleteObject(m_hBackBitmap);
		m_hBackBitmap = NULL;
	}

	if (m_hBackDC != NULL)
	{
		DeleteObject(m_hBackDC);
		m_hBackDC = NULL;
	}
	//------------------�ĸ� BackDC ����

	//------------------GDI+����
	if (m_gdiplusToken != NULL)
	{
		GdiplusShutdown(m_gdiplusToken);
		m_gdiplusToken = NULL;
	}
	//------------------GDI+����
}
