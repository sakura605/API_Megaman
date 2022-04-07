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

	Vector2D m_CurPos;			//���ΰ� ��ǥ ���� ����
	Vector2D a_KDirVec;			//���ΰ��� �ٶ󺸴� ����
	float a_IsLeft = false;		//���ΰ��� �ٶ󺸴� ���� �÷��� ����
	bool a_GameReady = false;	//���� ������Ʈ
	

	bool a_Run = false;			//�޸��� �ִ���?
	bool a_Jump = false;		//���� ������?
	bool a_JumpAtk = false;		//���� ���� ������?
	bool a_Crouch = false;		//ũ���ġ ��������?
	bool a_Dash = false;		//�뽬 ��������?
	bool a_IsleftSlide = false;		//�� �����̵� ��������?
	bool a_IsrightSlide = false;
	float a_DashForce = 0.0f;	//�뽬�Ҷ� �ִ� ��
	int a_AtkNum = 0;			//���° ����������?

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

