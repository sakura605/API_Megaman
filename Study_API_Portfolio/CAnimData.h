#pragma once

#include <vector>
using namespace std;

//------GDI+ Image 사용을 위한 헤더 추가
#include <Ole2.h>
#include <gdiplus.h>
#pragma comment(lib,"Gdiplus.lib")
using namespace Gdiplus;
//------GDI+ Image 사용을 위한 헤더 추가

enum Ani_Type
{
	Type_None,
	Type_ZERO,
	Type_Length,
};

enum AniState
{
	AS_None,
	Ready_St,
	Ready_End,
	Idle,
	Walk_Beg,
	Walk_Run,
	Dash_Beg,
	Dash_Run,
	Dash_End,
	Jump_Run,
	Jump_Fall_Beg,
	Jump_Fall_Run,
	Jump_Fall_End,
	Jump_Attack,
	Crouch,
	Crouch_Attack,
	Attack_1,
	Attack_2,
	Attack_3,
	Attack_End,
	Slide_Beg,
	Slide_Run,
	Slide_End,
	Wall_Kick,
	AniLength,
};


class CMotion
{
public:
	vector<Image*> m_ImgList;	//프레임 로딩

public:
	CMotion() {}
	~CMotion()
	{
		for (int ii = 0; ii < m_ImgList.size(); ii++)
		{
			if (m_ImgList[ii] != NULL)
			{
				delete m_ImgList[ii];
				m_ImgList[ii] = NULL;
			}
		}
		m_ImgList.clear();
	}

	void LoadTexImg(const TCHAR* a_FName)
	{
		//해당 경로에서 이미지 불러오기
		Image* a_pBitmap = Image::FromFile(a_FName);
		m_ImgList.push_back(a_pBitmap);
	}
};

class CAnimData
{
public:
	vector<CMotion*> m_MotionList;
public:
	CAnimData();
	~CAnimData();

	void LoadAnimList(Ani_Type a_AniType);
};

