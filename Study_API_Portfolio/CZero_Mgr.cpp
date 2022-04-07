#include "stdafx.h"
#include "CZero_Mgr.h"
#include "CInGameScene.h"
#include "GlobalValue.h"
CZero_Mgr g_Zero;

CZero_Mgr::CZero_Mgr()
{
}


CZero_Mgr::~CZero_Mgr()
{

}

void CZero_Mgr::Init_Unit(HWND a_hWnd)
{
	NULL_Brush = (HBRUSH)GetStockObject(NULL_BRUSH); //투명블러쉬
	GreenPen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));

	SetAni_Rsc(Type_ZERO);
	if (m_CurAniState == AS_None)
		m_SocketImg = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_1\\Z04_Attack_1_frame_001.gif"));

	LoadUnitSize();

	//주인공 좌표 초기화 부분
	m_CurPos.x = 250.0f;
	m_CurPos.y = -50.0f;
	//주인공 좌표 초기화 부분
	m_Speed = 300.0f;

	AniDataInit();
}

void CZero_Mgr::Update_Unit(HWND a_hWnd, float a_DeltaTime, RECT & a_RT)
{
	a_KDirVec.x = 0.0f;
	a_KDirVec.y = 0.0f;
	a_DashForce = 0.0f;
	static float a_DashTime = 0.4f;	//최대 대쉬 시간
	static float a_JumpTime = 0.5f;	//최대 대쉬 시간

	if (a_GameReady == false)
	{
		m_CurPos.y += (m_Gravity * 4.0f);
		ChangeState(Ready_St);
	}


	if (650.0f <= m_CurPos.y)
	//if (g_Ingame_Mgr.m_MapImgPos[2].y <= m_CurPos.y)
	{
		m_JumpForce = 22.0f;
		m_CurPos.y = 650.0f;
		a_JumpAtk = false;
		a_Jump = false;
		a_JumpTime = 0.5f;
	
		if (a_GameReady == false)
		{
			ChangeState(Ready_End);
			a_GameReady = true;
		}
	}

	if (a_GameReady == true)
	{
		if (m_CurPos.x <= 100.0f)
		{
			m_CurPos.x = 100.0f;
		}

		else if (1450.0f <= m_CurPos.x)
		{
			m_CurPos.x = 1450.0f;
		}

		//if (m_CurPos.x <= 100.0f &&  m_CurPos.y <= 650.0f)
		//{
		//	ChangeAction(Slide_Run);
		//}

		if ((GetAsyncKeyState(VK_RIGHT) & 0x8000))
		{
			if (a_Jump == false)
				ChangeAction(Walk_Run);

			a_KDirVec.x += 1.0f;
			a_IsLeft = false;
		}

		else if ((GetAsyncKeyState(VK_LEFT) & 0x8000))
		{
			if (a_Jump == false)
				ChangeAction(Walk_Run);

			a_KDirVec.x -= 1.0f;
			a_IsLeft = true;
		}

		else if (!(GetAsyncKeyState(VK_RIGHT) & 0x8000) && !(GetAsyncKeyState(VK_LEFT) & 0x8000))
		{
			if (a_Run == true && a_Jump == false)
				ChangeAction(Idle);
		}

		if ((GetAsyncKeyState(VK_DOWN) & 0x0001))
		{
			ChangeAction(Crouch);
		}

		else if (!(GetAsyncKeyState(VK_DOWN) & 0x8000))
		{
			if (a_Crouch == true)
				ChangeAction(Idle);
		}
		
		if ((GetAsyncKeyState('C') & 0x8000))
		{
			if (a_IsleftSlide == false && a_IsrightSlide == false)
			{
				a_JumpTime -= a_DeltaTime;

				if (a_JumpAtk == false)
				{
					ChangeAction(Jump_Run);

					if (a_JumpTime <= 0.0f)
					{
						ChangeAction(Jump_Fall_Run);
					}
					a_KDirVec.y += 1.0f;
				}
			}
		}

		else if (!(GetAsyncKeyState('C') & 0x8000))
		{
			if (a_Jump == true && a_JumpAtk == false)
				ChangeAction(Jump_Fall_Run);

			if ((GetAsyncKeyState(VK_LEFT) & 0x8000))
			{
				if (m_CurPos.x <= 100.0f &&  m_CurPos.y < 650.0f)
				{
					a_IsleftSlide = true;
					m_Gravity = 2.0f;
					ChangeAction(Slide_Run);
				}

				if ((GetAsyncKeyState('X') & 0x8000))
				{
					ChangeAction(Wall_Kick);
					m_CurPos.x += 3.0f;
					m_CurPos.y -= 6.0f;
				}
			}
			else if (!(GetAsyncKeyState(VK_LEFT) & 0x8000))
			{
				if (a_IsleftSlide == true)
				{
					a_IsleftSlide = false;
					m_Gravity = 4.0f;
				}
			}

			if ((GetAsyncKeyState(VK_RIGHT) & 0x8000))
			{
				if (1450.0f <= m_CurPos.x &&  m_CurPos.y < 650.0f)
				{
					a_IsrightSlide = true;
					m_Gravity = 2.0f;
					ChangeAction(Slide_Run);
				}
			}
			else if (!(GetAsyncKeyState(VK_RIGHT) & 0x8000))
			{
				if (a_IsrightSlide == true)
				{
					a_IsrightSlide = false;
					m_Gravity = 4.0f;
				}
			}

		}

		if (a_IsleftSlide == true || a_IsrightSlide == true)
		{
			static float m_AniTick = 0.03f;
			m_AniTick -= a_DeltaTime;
			if (m_AniTick < 0.0f)
			{
				m_SlideFogImgNum++;
				m_AniTick = 0.03f;

				if (3 <= m_SlideFogImgNum)
				{
					m_SlideFogImgNum = 0;
				}
			}
		}

		if (GetAsyncKeyState('X') & 0x0001)
		{
			//if (a_Run == true)
			//	return;

			if (a_Jump == false && a_Crouch == false)
			{
				a_AtkNum++;
				if (a_AtkNum == 1)
					ChangeState(Attack_1);
				else if (a_AtkNum == 2)
					ChangeState(Attack_2);
				else if (a_AtkNum == 3)
					ChangeState(Attack_3);
			}

			else if (a_Crouch == true)
			{
				ChangeAction(Crouch_Attack);
			}

			else if (a_Jump == true && a_Crouch == false)
			{
				ChangeAction(Jump_Attack);
			}

		}

		if ((GetAsyncKeyState('Z') & 0x8000))
		{
			m_ImgCount = true;
			a_DashTime -= a_DeltaTime;

			if (0.0f <= a_DashTime)
			{
				if (a_Crouch == false)
				{
					ChangeAction(Dash_Run);
					m_JumpForce = 0.0f;
					if (a_IsLeft == false)
						a_KDirVec.x += 1.0f;
					else
						a_KDirVec.x -= 1.0f;
				}
			}
			//else
			//{
			//	if (a_Dash == true)
			//	{
			//		ChangeAction(Dash_End);
			//		a_Dash = false;
			//		m_Gravity = 4.0f;
			//	}
			//}
		}

		else if (!(GetAsyncKeyState('Z') & 0x8000))
		{
			if (a_Dash == true)
			{
				ChangeState(Dash_End);
				m_Speed = 300.0f;
				a_Dash = false;
				m_Gravity = 6.0f;
				a_DashTime = 0.4f;
			}
		}

		if (m_ImgCount == true)
		{
			static float m_AniTick = 0.01f;
			m_AniTick -= a_DeltaTime;
			if (m_AniTick < 0.0f)
			{
				m_DashFogImgNum++;
				m_DashBoostImgNum++;

				m_AniTick = 0.01f;

				if (15 <= m_DashFogImgNum)
				{
					m_DashFogImgNum = 0;
					m_ImgCount = false;
				}

				if (9 <= m_DashBoostImgNum)
				{
					m_DashBoostImgNum = 0;
					m_ImgCount = false;
				}
			}
		}
	}

	if ((GetAsyncKeyState(VK_ESCAPE) & 0x0001))
	{
		g_GameState = GAME_MENU;
	}

	m_CurPos.y += m_Gravity;


	a_KDirVec.Normalize();
	m_CurPos = m_CurPos + (a_KDirVec * (a_DeltaTime * (m_Speed + a_DashForce)));

	//--------------------애니메이션 프레임 계산 부분
	CAniMgr::Update_Unit(a_DeltaTime);	//부모쪽 Update_Unit() 함수 호출
	//--------------------애니메이션 프레임 계산 부분
}

void CZero_Mgr::Render_Unit(HDC a_HDC)
{
	Graphics graphics(a_HDC);
	HBRUSH OldBrush = (HBRUSH)SelectObject(a_HDC, NULL_Brush);
	HPEN OldPen = (HPEN)SelectObject(a_HDC, GreenPen);

	if (a_IsLeft == false)
	{
		graphics.DrawImage(m_SocketImg, m_CurPos.x - m_HalfWidth, m_CurPos.y - m_HalfHeight, (float)m_ImgSizeX, (float)m_ImgSizeY);

		if (m_ImgCount == true)
		{
			graphics.DrawImage(m_DashFog[m_DashFogImgNum],
				m_CurPos.x - m_HalfWidth - 70.0f,
				m_CurPos.y + 30.0f, 
				m_DashFog[m_DashFogImgNum]->GetWidth() * 2.0f, m_DashFog[m_DashFogImgNum]->GetHeight() * 2.0f);

			graphics.DrawImage(m_DashBoost[m_DashBoostImgNum], 
				m_CurPos.x - m_HalfWidth - 170.0f,
				m_CurPos.y + 10.0f,
				m_DashBoost[m_DashBoostImgNum]->GetWidth() * 3.0f, m_DashBoost[m_DashBoostImgNum]->GetHeight() * 3.0f);
		}

		if (a_IsrightSlide == true)
		{
			graphics.DrawImage(m_SlideFog[m_SlideFogImgNum],
				m_CurPos.x + m_HalfWidth - 130.0f,
				m_CurPos.y - 10.0f,
				m_SlideFog[m_SlideFogImgNum]->GetWidth() * 3.0f, m_SlideFog[m_SlideFogImgNum]->GetHeight() * 3.0f);
		}

	}
	else
	{
		graphics.DrawImage(m_SocketImg, m_CurPos.x + m_HalfWidth, m_CurPos.y - m_HalfHeight, (float)-m_ImgSizeX, (float)m_ImgSizeY);
		if (m_ImgCount == true)
		{
			graphics.DrawImage(m_DashFog[m_DashFogImgNum],
				m_CurPos.x + m_HalfWidth + 70.0f,
				m_CurPos.y + 30.0f,
				-(m_DashFog[m_DashFogImgNum]->GetWidth() * 2.0f), m_DashFog[m_DashFogImgNum]->GetHeight() * 2.0f);

			graphics.DrawImage(m_DashBoost[m_DashBoostImgNum],
				m_CurPos.x + m_HalfWidth + 170.0f,
				m_CurPos.y + 10.0f,
				-(m_DashBoost[m_DashBoostImgNum]->GetWidth() * 3.0f), m_DashBoost[m_DashBoostImgNum]->GetHeight() * 3.0f);
		}

		if (a_IsleftSlide == true)
		{
			graphics.DrawImage(m_SlideFog[m_SlideFogImgNum],
				m_CurPos.x - m_HalfWidth + 20.0f,
				m_CurPos.y - 10.0f,
				m_SlideFog[m_SlideFogImgNum]->GetWidth() * 3.0f, m_SlideFog[m_SlideFogImgNum]->GetHeight() * 3.0f);
		}
	}

	//Rectangle(a_HDC, m_CurPos.x - m_HalfWidth, m_CurPos.y - m_HalfHeight, m_CurPos.x + m_HalfWidth, m_CurPos.y + m_HalfHeight);
	MoveToEx(a_HDC, 0.0f, 650.0f, NULL);
	//LineTo(a_HDC, 2000.0f, 650.0f);

	MoveToEx(a_HDC, 100.0f, 0.0f, NULL);
	//LineTo(a_HDC, 100.0f, 1000.0f);

	MoveToEx(a_HDC, 1450.0f, 0.0f, NULL);
	//LineTo(a_HDC, 1450.0f, 1000.0f);

	SelectObject(a_HDC, OldBrush);
	SelectObject(a_HDC, OldPen);
}

void CZero_Mgr::Destroy_Unit()
{
	if (NULL_Brush != NULL)
	{
		delete(NULL_Brush);
		NULL_Brush = NULL;
	}

	if (GreenPen != NULL)
	{
		delete(GreenPen);
		GreenPen = NULL;
	}
}

void CZero_Mgr::ChangeAction(AniState state)
{
	switch (state)
	{
	case Idle:
		a_Run = false;
		a_Crouch = false;
		break;

	case Walk_Run:
		a_Run = true;
		break;

	case Crouch:
		a_Crouch = true;
		break;
	case Crouch_Attack:
		break;

	case Jump_Run:
		a_Run = true;
		a_Jump = true;
		m_CurPos.y -= m_JumpForce;
		m_JumpForce = m_JumpForce * 0.97f;
		break;

	case Jump_Fall_Run:
		break;
	case Jump_Attack:
		a_JumpAtk = true;
		break;

	case Dash_Run:
		a_Dash = true;
		a_DashForce += 600.0f;
		m_Gravity = 0;
		break;
	case Dash_End:
		break;
	}
	a_AtkNum = 0;
	ChangeState(state);
}

void CZero_Mgr::AniDataInit()
{

	m_DashFog[0] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashfog\\frame00.gif"));
	m_DashFog[1] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashfog\\frame01.gif"));
	m_DashFog[2] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashfog\\frame02.gif"));
	m_DashFog[3] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashfog\\frame03.gif"));
	m_DashFog[4] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashfog\\frame04.gif"));
	m_DashFog[5] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashfog\\frame05.gif"));
	m_DashFog[6] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashfog\\frame06.gif"));
	m_DashFog[7] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashfog\\frame07.gif"));
	m_DashFog[8] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashfog\\frame08.gif"));
	m_DashFog[9] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashfog\\frame09.gif"));
	m_DashFog[10] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashfog\\frame10.gif"));
	m_DashFog[11] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashfog\\frame11.gif"));
	m_DashFog[12] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashfog\\frame12.gif"));
	m_DashFog[13] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashfog\\frame13.gif"));
	m_DashFog[14] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashfog\\frame14.gif"));
	m_DashFog[15] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashfog\\frame15.gif"));

	m_SlideFog[0] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\slidefog\\frame01.gif"));
	m_SlideFog[1] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\slidefog\\frame02.gif"));
	m_SlideFog[2] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\slidefog\\frame03.gif"));
	m_SlideFog[3] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\slidefog\\frame04.gif"));

	m_DashBoost[0] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashboost\\frame01.gif"));
	m_DashBoost[1] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashboost\\frame02.gif"));
	m_DashBoost[2] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashboost\\frame03.gif"));
	m_DashBoost[3] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashboost\\frame04.gif"));
	m_DashBoost[4] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashboost\\frame05.gif"));
	m_DashBoost[5] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashboost\\frame06.gif"));
	m_DashBoost[6] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashboost\\frame07.gif"));
	m_DashBoost[7] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashboost\\frame08.gif"));
	m_DashBoost[8] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashboost\\frame09.gif"));
	m_DashBoost[9] = Image::FromFile(_T(".\\Resources\\ZeroAni\\Zero_Effect\\dashboost\\frame10.gif"));
	
}