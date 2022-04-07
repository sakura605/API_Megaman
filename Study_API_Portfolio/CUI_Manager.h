#pragma once

//----- GDI+ Image 사용을 위한 헤더 추가
#include <ole2.h>      
#include <gdiplus.h>
#pragma comment(lib, "Gdiplus.lib")
using namespace Gdiplus;
//----- GDI+ Image 사용을 위한 헤더 추가
#include "Vector2D.h"

enum MenuSelect
{
	GAMESTART,
	CONTINUE,
	OPTION
};

class CUI_Manager
{
	Image* m_TitleLogo = NULL;
	Image* m_TitleMenu = NULL;
	Image* m_GameStartOn = NULL;
	Image* m_GameStartOff = NULL;
	Image* m_ContinueOn = NULL;
	Image* m_ContinueOff = NULL;
	Image* m_OptionOn = NULL;
	Image* m_OptionOff = NULL;
	Image* m_ZeroCursor_Ani[11];
public:
	CUI_Manager();
	~CUI_Manager();

private:
	Vector2D a_CursorPos;
	MenuSelect m_MenuSel;
	int Sel;
	bool m_Choice;
	bool m_TitleMenuOnOff = true;
	float m_OnOffTime = 0.0f;
	int ImgNum = 0;
	float AniTickCnt = 0.05f;

public:
	void UIMgr_Init();
	void UIMgr_Update(HWND a_hWnd, float a_DeltaTime);
	void UIMgr_Render(HDC a_MainDC, RECT& a_RT);
	void UIMgr_Destroy();
};

extern CUI_Manager g_GUI_Mgr;