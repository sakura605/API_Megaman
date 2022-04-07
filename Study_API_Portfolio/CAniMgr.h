#pragma once
#include "Vector2D.h"
#include "CAnimData.h"

class CAniMgr
{
public:
	Ani_Type m_AniType;			//UI애니메이션인지 캐릭터 애니메이션인지
	CAnimData* m_RefAniData;	//캐릭터 타입에 따라 애니메이션 데이터를 바꿔 낄 것임

	//애니메이션 관련 변수
	Image*		m_SocketImg;	//애니 소켓처럼 사용할 포인터
	Image*		m_ReadyMsg;
	AniState	m_CurAniState;	//현재 애니메이션 상태

	int		m_NowImgCount;		//애니 소켓처럼 사용할 이미지 카운트
	float	m_EachAniDelay;		//프레임 간격 시간
	float	m_AniTickCount;		//다음 프레임까지 시간 Add
	int		m_CurAniInx;		//현재 Ani Index
	//애니메이션 관련 변수

	int		m_ImgSizeX;			//이미지 가로 사이즈
	int		m_ImgSizeY;			//이미지 세로 사이즈
	int		m_HalfWidth = 15;	//이미지 가로 반사이즈
	int		m_HalfHeight = 15;	//이미지 세로 반사이즈

public:
	CAniMgr();
	~CAniMgr();

	void SetAni_Rsc(Ani_Type a_AniType);
	void LoadUnitSize();

	//virtual - 상속 받는 쪽에서 함수를 재정의해서 사용하기 위해
	virtual void Init_Unit(HWND a_hWnd);
	virtual void Update_Unit(float a_DeltaTime);
	virtual void Render_Unit(HWND a_hDC);
	virtual void Destroy_Unit();

	bool ChangeState(AniState newState);
	void AniFrameUpdate(float a_DeltaTime);
};

extern CAniMgr g_AniMgr;
