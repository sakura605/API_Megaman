#include "stdafx.h"
#include "CAniMgr.h"
#include "CMyMain.h"
#include "CZero_Mgr.h"

CAniMgr g_AniMgr;

CAniMgr::CAniMgr()
{
	m_SocketImg = NULL;
	m_RefAniData = NULL;

	m_CurAniState = AS_None;
	m_NowImgCount = 0;
	m_CurAniInx = 0;
	m_AniTickCount = 0;
	m_EachAniDelay = 0.01f;
}


CAniMgr::~CAniMgr()
{
}

void CAniMgr::SetAni_Rsc(Ani_Type a_AniType)
{
	if (a_AniType <= Type_None || Type_Length <= a_AniType)
		return;

	m_AniType = a_AniType;

	if (a_AniType < g_CMyMain.m_CharAniList.size())
		m_RefAniData = g_CMyMain.m_CharAniList[(int)a_AniType];

	ChangeState(Ready_St);

	LoadUnitSize();
}

void CAniMgr::LoadUnitSize()
{
	if (m_SocketImg != NULL)
	{
		m_ImgSizeX = m_SocketImg->GetWidth()* 3.0f;
		m_ImgSizeY = m_SocketImg->GetHeight()*3.0f;

		m_HalfWidth = m_ImgSizeX / 2;
		m_HalfHeight = m_ImgSizeY / 2;
	}
}

void CAniMgr::Init_Unit(HWND a_hWnd)
{
}

void CAniMgr::Update_Unit(float a_DeltaTime)
{
 	AniFrameUpdate(a_DeltaTime);
}

void CAniMgr::Render_Unit(HWND a_hDC)
{
}

void CAniMgr::Destroy_Unit()
{
}

bool CAniMgr::ChangeState(AniState newState)
{
	//스테이트 변경해 주는 부분
	if (m_CurAniState == newState)
		return false;

	if (newState < AS_None || AniLength <= newState)
		return false;

	m_NowImgCount = m_RefAniData->m_MotionList[(int)newState]->m_ImgList.size();
	m_CurAniInx = 0;
	m_AniTickCount = 0;

	if (newState == Idle || newState == Walk_Run || newState == Jump_Fall_Run || newState == Jump_Run)
		m_EachAniDelay = 0.04f;
	else if (newState == Dash_End)
		m_EachAniDelay = 0.01f;
	else if (newState == Slide_Run)
		m_EachAniDelay = 0.1f;
	else
		m_EachAniDelay = 0.02f;

	m_SocketImg = m_RefAniData->m_MotionList[(int)newState]->m_ImgList[0];
	m_ImgSizeX = m_SocketImg->GetWidth() * 3.0f;
	m_ImgSizeY = m_SocketImg->GetHeight() * 3.0f;

	m_HalfWidth = m_ImgSizeX / 2;
	m_HalfHeight = m_ImgSizeY / 2;

	m_CurAniState = newState;

	return true;
}

void CAniMgr::AniFrameUpdate(float a_DeltaTime)
{
	//애니메이션 프레임 계산
	if (m_CurAniState == AS_None)
		return;

	if (m_NowImgCount <= 0)
		return;

	m_AniTickCount = m_AniTickCount + a_DeltaTime;

	if (m_EachAniDelay < m_AniTickCount)
	{
		m_CurAniInx++;

		if (m_NowImgCount <= m_CurAniInx)
		{
			m_CurAniInx = 0;

			if (m_CurAniState == Ready_End || m_CurAniState == Dash_End)
				ChangeState(Idle);

			if (m_CurAniState == Dash_Beg)
				ChangeState(Dash_Run);

			if (m_CurAniState == Attack_1 || m_CurAniState == Attack_2 || m_CurAniState == Attack_3)
			{
				g_Zero.a_AtkNum = 0;
				ChangeState(Idle);
			}

			if (m_CurAniState == Jump_Run)
				m_CurAniInx = 2;
			if (m_CurAniState == Crouch)
				m_CurAniInx = 1;

			if (m_CurAniState == Crouch_Attack)
				ChangeState(Crouch);
			if (m_CurAniState == Jump_Attack)
				ChangeState(Jump_Fall_Run);
			if (m_CurAniState == Dash_End)
				ChangeState(Idle);

			//if (m_CurAniState == Slide_Run)
			//	m_CurAniInx = 5;
		}

		m_SocketImg = m_RefAniData->m_MotionList[(int)m_CurAniState]->m_ImgList[m_CurAniInx];
		m_AniTickCount = 0;
	}
	//애니메이션 프레임 계산
}
