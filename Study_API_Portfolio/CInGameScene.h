#pragma once

//----- GDI+ Image ����� ���� ��� �߰�
#include <ole2.h>      
#include <gdiplus.h>
#pragma comment(lib, "Gdiplus.lib")
using namespace Gdiplus;
//----- GDI+ Image ����� ���� ��� �߰�

#include "Vector2D.h"
#include <vector>
using namespace std;


class CInGameScene
{
	Image* m_ReadyMsg[79];
	Image* m_HPBarBody;
	Image* m_HpBar;
	float m_HpBarImgWidth;
	float m_HpBarImgHeight;

	Image* m_Map;
	float m_MapImgWidth;
	float m_MapImgHeight;

	HDC		m_BGImgDC;
	HBITMAP m_hTexImgBMP;	//�ε��� BMP������ �ڵ�
	int		m_TexImgWidth;	//�̹����� ���� ������
	int		m_TexImgHeight;	//�̹����� ���� ������

	HDC		m_MapImgDC;
	HBITMAP m_hTexImgBMP2;		//�ε��� BMP������ �ڵ�
	int		m_TexImgWidth2;		//�̹����� ���� ������
	int		m_TexImgHeight2;	//�̹����� ���� ������

	int ImgNum = 0;
	bool GameReady = false;

public:
	vector<Image*> m_MapImg;
	Vector2D m_MapImgPos[100];
public:
	CInGameScene();
	~CInGameScene();

	void Ingame_Init(HWND a_hWnd);
	void Ingame_Update(HWND a_hWnd, float a_DeltaTime);
	void Ingame_Render(HDC a_MainDC, RECT& a_RT);
	void Ingame_Destroy();
};

extern CInGameScene g_Ingame_Mgr;
