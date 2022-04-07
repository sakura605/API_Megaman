#pragma once
#include "Vector2D.h"
#include "CAniMgr.h"

class CZero_Mgr : public CAniMgr
{
	float m_Speed = 300.0f;
	float m_JumpForce = 30.0f;
	float m_Gravity = 4.0f;

public:
	HBRUSH NULL_Brush;
	HPEN GreenPen;

	Vector2D m_CurPos;			//주인공 좌표 계산용 변수
	Vector2D a_KDirVec;			//주인공이 바라보는 방향
	float a_IsLeft = false;		//주인공이 바라보는 방향 플래그 변수
	bool a_GameReady = false;	//게임 스테이트
	

	bool a_Run = false;			//달리고 있는지?
	bool a_Jump = false;		//점프 중인지?
	bool a_JumpAtk = false;		//점프 어택 중인지?
	bool a_Crouch = false;		//크라우치 상태인지?
	bool a_Dash = false;		//대쉬 상태인지?
	bool a_IsleftSlide = false;		//벽 슬라이딩 상태인지?
	bool a_IsrightSlide = false;
	float a_DashForce = 0.0f;	//대쉬할때 주는 힘
	int a_AtkNum = 0;			//몇번째 공격중인지?

	Image* m_DashFog[16];
	Image* m_SlideFog[4];
	Image* m_DashBoost[10];
	bool m_ImgCount = false;
	int m_DashFogImgNum = 0;
	int m_DashBoostImgNum = 0;
	int m_SlideFogImgNum = 0;

public:
	CZero_Mgr();
	~CZero_Mgr();

public:
	virtual void Init_Unit(HWND a_hWnd);
	virtual void Update_Unit(HWND a_hWnd, float a_DeltaTime, RECT& a_RT);
	virtual void Render_Unit(HDC a_HDC);
	virtual void Destroy_Unit();

	void ChangeAction(AniState state);
	void AniDataInit();
	AniState m_AniState;
};

extern CZero_Mgr g_Zero;

