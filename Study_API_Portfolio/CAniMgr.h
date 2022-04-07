#pragma once
#include "Vector2D.h"
#include "CAnimData.h"

class CAniMgr
{
public:
	Ani_Type m_AniType;			//UI�ִϸ��̼����� ĳ���� �ִϸ��̼�����
	CAnimData* m_RefAniData;	//ĳ���� Ÿ�Կ� ���� �ִϸ��̼� �����͸� �ٲ� �� ����

	//�ִϸ��̼� ���� ����
	Image*		m_SocketImg;	//�ִ� ����ó�� ����� ������
	Image*		m_ReadyMsg;
	AniState	m_CurAniState;	//���� �ִϸ��̼� ����

	int		m_NowImgCount;		//�ִ� ����ó�� ����� �̹��� ī��Ʈ
	float	m_EachAniDelay;		//������ ���� �ð�
	float	m_AniTickCount;		//���� �����ӱ��� �ð� Add
	int		m_CurAniInx;		//���� Ani Index
	//�ִϸ��̼� ���� ����

	int		m_ImgSizeX;			//�̹��� ���� ������
	int		m_ImgSizeY;			//�̹��� ���� ������
	int		m_HalfWidth = 15;	//�̹��� ���� �ݻ�����
	int		m_HalfHeight = 15;	//�̹��� ���� �ݻ�����

public:
	CAniMgr();
	~CAniMgr();

	void SetAni_Rsc(Ani_Type a_AniType);
	void LoadUnitSize();

	//virtual - ��� �޴� �ʿ��� �Լ��� �������ؼ� ����ϱ� ����
	virtual void Init_Unit(HWND a_hWnd);
	virtual void Update_Unit(float a_DeltaTime);
	virtual void Render_Unit(HWND a_hDC);
	virtual void Destroy_Unit();

	bool ChangeState(AniState newState);
	void AniFrameUpdate(float a_DeltaTime);
};

extern CAniMgr g_AniMgr;
