#include "stdafx.h"
#include "CMyMain.h"
#include "CBackGround.h"
#include "CUI_Manager.h"
#include "CInGameScene.h"
#include "CZero_Mgr.h"
#include "GlobalValue.h"

//--------DeltaTime을 위한 헤더
#include <mmsystem.h>
#include <time.h>
#include <stdlib.h>
#pragma comment(lib, "winmm.lib")
//--------DeltaTime을 위한 헤더

//--------GDI+ Image 사용을 위한 헤더 추가
#include <Ole2.h>
#include <gdiplus.h>
#pragma comment(lib, "Gdiplus.lib")
using namespace Gdiplus;
//--------GDI+ Image 사용을 위한 헤더 추가
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

	m_LastTime = timeGetTime();	//현재 시간 가져오기

	//---------- GDI+ 초기화
	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);
	//---------- GDI+ 초기화

	//---------- 후면 BackDC생성
	HDC hdc = GetDC(hWnd);						//메인 DC가져오기
	m_hBackDC = CreateCompatibleDC(hdc);		//메인DC의 쌍둥이 복사본을 만든다.
	m_hBackBitmap = CreateCompatibleBitmap(hdc, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
												//BackDC에 붙여줄 비트맵 이미지를 하나 만든다.
	SelectObject(m_hBackDC, m_hBackBitmap);		//BackDC에 Bitmap(이미지)를 붙여준다.
	ReleaseDC(hWnd, hdc);
	//---------- 후면 BackDC생성
	
	for (int ii = 0; ii < Type_Length; ii++)
	{
		CAnimData* a_Node = new CAnimData();
		a_Node->LoadAnimList((Ani_Type)ii);
 		m_CharAniList.push_back(a_Node);
	}

	//---------백그라운드 초기화
	g_BGround.BG_Init(hWnd);
	//---------백그라운드 초기화

	//---------UI 매니저 초기화
	g_GUI_Mgr.UIMgr_Init();
	//---------UI 매니저 초기화

	//--------인게임 매니저 초기화
	g_Ingame_Mgr.Ingame_Init(hWnd);
	//--------인게임 매니저 초기화

	//--------캐릭터 매니저 초기화
	g_Zero.Init_Unit(hWnd);
	//--------캐릭터 매니저 초기화
}

void CMyMain::MainUpdate(HWND hWnd)
{
	//DeltaTime 얻어오는 방법
	timeBeginPeriod(1);
	m_CurTime = timeGetTime();
	m_DeltaTime = ((m_CurTime - m_LastTime) * 0.001);
	m_LastTime = m_CurTime;
	timeEndPeriod(1);
	//DeltaTime 얻어오는 방법

	if (m_hBackDC == NULL)
		return;

	GetClientRect(hWnd, &m_Rect);

	if (g_GameState == GAME_MENU)
	{
		//---------UI 매니저 업데이트
		g_GUI_Mgr.UIMgr_Update(hWnd, m_DeltaTime);
		//---------UI 매니저 업데이트
	}

	else if (g_GameState == GAME_START)
	{
		g_Ingame_Mgr.Ingame_Update(hWnd, m_DeltaTime);

		//--------캐릭터 매니저 업데이트
		g_Zero.Update_Unit(hWnd, m_DeltaTime, m_Rect);
		//--------캐릭터 매니저 업데이트
	}
}

void CMyMain::MainRender(HWND hWnd)
{
	if (m_hBackDC == NULL)
		return;
	if (g_GameState == GAME_MENU)
	{
		//------------백그라운드 랜더
		g_BGround.BG_Render(m_hBackDC, m_Rect);
		//------------백그라운드 랜더

		//---------UI 매니저 랜더
		g_GUI_Mgr.UIMgr_Render(m_hBackDC, m_Rect);
		//---------UI 매니저 랜더
	}

	else if (g_GameState == GAME_START)
	{
		g_Ingame_Mgr.Ingame_Render(m_hBackDC, m_Rect);

		//--------캐릭터 매니저 랜더
		g_Zero.Render_Unit(m_hBackDC);
		//--------캐릭터 매니저 랜더
	}


	//--------------더블 버퍼링
	static HDC hdc;
	hdc = GetDC(hWnd);
	//화면 전환
	BitBlt(hdc, 0, 0, m_Rect.right, m_Rect.bottom, m_hBackDC, 0, 0, SRCCOPY);
	//화면 전환
	ReleaseDC(hWnd, hdc);
	//--------------더블 버퍼링
}

void CMyMain::MainDestroy()
{
	//----------백그라운드 제거
	g_BGround.BG_Destroy();
	//----------백그라운드 제거

	//-------- GUI 지우기...
	g_GUI_Mgr.UIMgr_Destroy();
	//-------- GUI 지우기...

	//-------- 인게임씬 지우기
	g_Ingame_Mgr.Ingame_Destroy();
	//-------- 인게임씬 지우기

	//------캐릭터 매니저 지우기
	g_Zero.Destroy_Unit();
	//------캐릭터 매니저 지우기

	//------------------후면 BackDC 제거
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
	//------------------후면 BackDC 제거

	//------------------GDI+해제
	if (m_gdiplusToken != NULL)
	{
		GdiplusShutdown(m_gdiplusToken);
		m_gdiplusToken = NULL;
	}
	//------------------GDI+해제
}
