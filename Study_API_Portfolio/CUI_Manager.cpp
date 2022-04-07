#include "stdafx.h"
#include "CUI_Manager.h"
#include "GlobalValue.h"
CUI_Manager g_GUI_Mgr;

CUI_Manager::CUI_Manager()
{
}


CUI_Manager::~CUI_Manager()
{
}

void CUI_Manager::UIMgr_Init()
{
	Sel = 0;
	m_Choice = false;
	a_CursorPos.x = 900.0f;
	a_CursorPos.y = 490.0f;

	//이미지 로드
	{
		m_TitleLogo = Image::FromFile(_T(".\\Resources\\TitleLogo.png"));
		m_TitleMenu = Image::FromFile(_T(".\\Resources\\Menu\\TitleMenu.png"));
		m_GameStartOn = Image::FromFile(_T(".\\Resources\\Menu\\GameStartOn.png"));
		m_GameStartOff = Image::FromFile(_T(".\\Resources\\Menu\\GameStartOff.png"));
		m_ContinueOn = Image::FromFile(_T(".\\Resources\\Menu\\ContinueOn.png"));
		m_ContinueOff = Image::FromFile(_T(".\\Resources\\Menu\\ContinueOff.png"));
		m_OptionOn = Image::FromFile(_T(".\\Resources\\Menu\\OptionOn.png"));
		m_OptionOff = Image::FromFile(_T(".\\Resources\\Menu\\OptionOff.png"));

		m_ZeroCursor_Ani[0] = Image::FromFile(_T(".\\Resources\\Menu\\Zero_Cursor.gif"));
		m_ZeroCursor_Ani[1] = Image::FromFile(_T(".\\Resources\\Menu\\Z04_Attack_1\\Z04_Attack_1_frame_001.gif"));
		m_ZeroCursor_Ani[2] = Image::FromFile(_T(".\\Resources\\Menu\\Z04_Attack_1\\Z04_Attack_1_frame_002.gif"));
		m_ZeroCursor_Ani[3] = Image::FromFile(_T(".\\Resources\\Menu\\Z04_Attack_1\\Z04_Attack_1_frame_003.gif"));
		m_ZeroCursor_Ani[4] = Image::FromFile(_T(".\\Resources\\Menu\\Z04_Attack_1\\Z04_Attack_1_frame_004.gif"));
		m_ZeroCursor_Ani[5] = Image::FromFile(_T(".\\Resources\\Menu\\Z04_Attack_1\\Z04_Attack_1_frame_005.gif"));
		m_ZeroCursor_Ani[6] = Image::FromFile(_T(".\\Resources\\Menu\\Z04_Attack_1\\Z04_Attack_1_frame_006.gif"));
		m_ZeroCursor_Ani[7] = Image::FromFile(_T(".\\Resources\\Menu\\Z04_Attack_1\\Z04_Attack_1_frame_007.gif"));
		m_ZeroCursor_Ani[8] = Image::FromFile(_T(".\\Resources\\Menu\\Z04_Attack_1\\Z04_Attack_1_frame_008.gif"));
		m_ZeroCursor_Ani[9] = Image::FromFile(_T(".\\Resources\\Menu\\Z04_Attack_1\\Z04_Attack_1_frame_009.gif"));
		m_ZeroCursor_Ani[10] = Image::FromFile(_T(".\\Resources\\Menu\\Z04_Attack_1\\Z04_Attack_1_frame_010.gif"));
	}
}

void CUI_Manager::UIMgr_Update(HWND a_hWnd, float a_DeltaTime)
{
	TCHAR str[128];
	_stprintf_s(str, _T("aa : %f\n"), a_DeltaTime);
	OutputDebugString(str);    //<--- Debug 모드로만 실행해야 실행된다.

	if (Sel == 0)
		m_MenuSel = GAMESTART;
	else if (Sel == 1)
		m_MenuSel = CONTINUE;
	else if (Sel == 2)
		m_MenuSel = OPTION;

	m_OnOffTime += a_DeltaTime;
	if (0.5f < m_OnOffTime)
	{
		m_TitleMenuOnOff = !m_TitleMenuOnOff;
		m_OnOffTime = 0.0f;
	}


	if ((GetAsyncKeyState(VK_RETURN) & 0x0001))
	{
		m_Choice = true;
	}

	if (m_Choice == true)
	{
		AniTickCnt -= a_DeltaTime;
		if (AniTickCnt < 0.0f)
		{
			ImgNum++;

			if (2 < ImgNum)
				float a = a_DeltaTime;
			AniTickCnt = 0.01f;
			if (9 < ImgNum)
			{
				ImgNum = 0;
				m_Choice = false;
				if (Sel == 0)
					g_GameState = GAME_START;
			}
		}
	}

	else
	{
		if ((GetAsyncKeyState(VK_DOWN) & 0x0001))
		{
			Sel++;
			a_CursorPos.y += 100.0f;
			if (2 < Sel)
			{
				a_CursorPos.y = 490.0f;
				Sel = 0;
			}
		}

		if ((GetAsyncKeyState(VK_UP) & 0x0001))
		{
			Sel--;
			a_CursorPos.y -= 100.0f;
			if (Sel < 0)
			{
				a_CursorPos.y = 690.0f;
				Sel = 2;
			}
		}
	}
	
}

void CUI_Manager::UIMgr_Render(HDC a_MainDC, RECT & a_RT)
{
	Graphics graphics(a_MainDC);

	if (m_ZeroCursor_Ani[ImgNum] != NULL)
	{
		graphics.DrawImage(m_ZeroCursor_Ani[ImgNum],
			a_CursorPos.x - ((float)m_ZeroCursor_Ani[ImgNum]->GetWidth() * 1.7f) / 2,
			a_CursorPos.y - ((float)m_ZeroCursor_Ani[ImgNum]->GetHeight() *1.7f) / 2,
			(float)m_ZeroCursor_Ani[ImgNum]->GetWidth() * 1.7f,
			(float)m_ZeroCursor_Ani[ImgNum]->GetHeight() * 1.7f);
	}

	if (m_TitleLogo != NULL)
		graphics.DrawImage(m_TitleLogo, 700.0f, 70.0f, (float)m_TitleLogo->GetWidth() / 1.5f, (float)m_TitleLogo->GetHeight() / 1.5f);

	if (m_TitleMenuOnOff == true)
	{
		if (m_TitleMenu != NULL)
			graphics.DrawImage(m_TitleMenu, 900.0f, 400.0f, (float)m_TitleMenu->GetWidth() * 3.0f, (float)m_TitleMenu->GetHeight() * 3.0f);
	}

	if (m_MenuSel == GAMESTART)
	{
		if (m_GameStartOn != NULL)
			graphics.DrawImage(m_GameStartOn, 980.0f, 500.0f, (float)m_GameStartOn->GetWidth() * 3.0f, (float)m_GameStartOn->GetHeight() * 3.0f);
		if(m_ContinueOff != NULL)
			graphics.DrawImage(m_ContinueOff, 980.0f, 600.0f, (float)m_ContinueOff->GetWidth() * 3.0f, (float)m_ContinueOff->GetHeight() * 3.0f);
		if (m_OptionOff != NULL)
			graphics.DrawImage(m_OptionOff, 980.0f, 700.0f, (float)m_OptionOff->GetWidth() * 3.0f, (float)m_OptionOff->GetHeight() * 3.0f);
	}

	if (m_MenuSel == CONTINUE)
	{
		if (m_GameStartOff != NULL)
			graphics.DrawImage(m_GameStartOff, 980.0f, 500.0f, (float)m_GameStartOff->GetWidth() * 3.0f, (float)m_GameStartOff->GetHeight() * 3.0f);
		if (m_ContinueOn != NULL)
			graphics.DrawImage(m_ContinueOn, 980.0f, 600.0f, (float)m_ContinueOn->GetWidth() * 3.0f, (float)m_ContinueOn->GetHeight() * 3.0f);
		if (m_OptionOff != NULL)
			graphics.DrawImage(m_OptionOff, 980.0f, 700.0f, (float)m_OptionOff->GetWidth() * 3.0f, (float)m_OptionOff->GetHeight() * 3.0f);
	}

	if (m_MenuSel == OPTION)
	{
		if (m_GameStartOff != NULL)
			graphics.DrawImage(m_GameStartOff, 980.0f, 500.0f, (float)m_GameStartOff->GetWidth() * 3.0f, (float)m_GameStartOff->GetHeight() * 3.0f);
		if (m_ContinueOff != NULL)
			graphics.DrawImage(m_ContinueOff, 980.0f, 600.0f, (float)m_ContinueOff->GetWidth() * 3.0f, (float)m_ContinueOff->GetHeight() * 3.0f);
		if (m_OptionOn != NULL)
			graphics.DrawImage(m_OptionOn, 980.0f, 700.0f, (float)m_OptionOn->GetWidth() * 3.0f, (float)m_OptionOn->GetHeight() * 3.0f);
	}
}

void CUI_Manager::UIMgr_Destroy()
{
	for (int i = 0; i < 11; i++)
	{
		if (m_ZeroCursor_Ani[ImgNum] != NULL)
		{
			delete m_ZeroCursor_Ani[ImgNum];
			m_ZeroCursor_Ani[ImgNum] = NULL;
		}
	}

	if (m_OptionOff != NULL)
	{
		delete m_OptionOff;
		m_OptionOff = NULL;
	}

	if (m_OptionOn != NULL)
	{
		delete m_OptionOn;
		m_OptionOn = NULL;
	}

	if (m_ContinueOff != NULL)
	{
		delete m_ContinueOff;
		m_ContinueOff = NULL;
	}

	if (m_ContinueOn != NULL)
	{
		delete m_ContinueOn;
		m_ContinueOn = NULL;
	}
	if (m_GameStartOff != NULL)
	{
		delete m_GameStartOff;
		m_GameStartOff = NULL;
	}

	if (m_GameStartOn != NULL)
	{
		delete m_GameStartOn;
		m_GameStartOn = NULL;
	}

	if (m_TitleMenu != NULL)
	{
		delete m_TitleMenu;
		m_TitleMenu = NULL;
	}

	if (m_TitleLogo != NULL)
	{
		delete m_TitleLogo;
		m_TitleLogo = NULL;
	}
}
