#include "stdafx.h"
#include "CInGameScene.h"
#include "CAniMgr.h"

CInGameScene g_Ingame_Mgr;

CInGameScene::CInGameScene()
{
}


CInGameScene::~CInGameScene()
{
}

void CInGameScene::Ingame_Init(HWND a_hWnd)
{
	HDC hdc = GetDC(a_hWnd);				//WM_PAINT 밖에서 HDC 얻어오는 방법
	m_BGImgDC = CreateCompatibleDC(hdc);	//MainDC의 복사본을 만든다.
	m_hTexImgBMP = (HBITMAP)LoadImage(NULL, _T(".\\Resources\\InGameBG.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	//BMP파일을 로딩한다.
	SelectObject(m_BGImgDC, m_hTexImgBMP);	//복사본 DC에 로딩된 HBITMAP을 선택해서 복사본 DC를 준비시킨다.
	ReleaseDC(a_hWnd, hdc);	//얻어온 Main HDC를 해제해준다.

	BITMAP bm;
	GetObject(m_hTexImgBMP, sizeof(BITMAP), &bm);	//비트맵 정보 얻기
	m_TexImgWidth = bm.bmWidth;		//BMP원본의 가로 사이즈
	m_TexImgHeight = bm.bmHeight;	//BMP원본의 가로 사이즈


	hdc = GetDC(a_hWnd);				//WM_PAINT 밖에서 HDC 얻어오는 방법
	m_MapImgDC = CreateCompatibleDC(hdc);	//MainDC의 복사본을 만든다.
	m_hTexImgBMP2 = (HBITMAP)LoadImage(NULL, _T(".\\Resources\\IngameMap2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	//BMP파일을 로딩한다.
	SelectObject(m_MapImgDC, m_hTexImgBMP2);	//복사본 DC에 로딩된 HBITMAP을 선택해서 복사본 DC를 준비시킨다.
	ReleaseDC(a_hWnd, hdc);						//얻어온 Main HDC를 해제해준다.

	GetObject(m_hTexImgBMP2, sizeof(BITMAP), &bm);	//비트맵 정보 얻기
	m_TexImgWidth2 = bm.bmWidth;		//BMP원본의 가로 사이즈
	m_TexImgHeight2 = bm.bmHeight;	//BMP원본의 가로 사이즈
	
	//시작 레디 메시지 이미지 로드
	{
		m_ReadyMsg[0] = Image::FromFile(_T(".\\Resources\\Ready\\ready001.gif"));
		m_ReadyMsg[1] = Image::FromFile(_T(".\\Resources\\Ready\\ready002.gif"));
		m_ReadyMsg[2] = Image::FromFile(_T(".\\Resources\\Ready\\ready003.gif"));
		m_ReadyMsg[3] = Image::FromFile(_T(".\\Resources\\Ready\\ready004.gif"));
		m_ReadyMsg[4] = Image::FromFile(_T(".\\Resources\\Ready\\ready005.gif"));
		m_ReadyMsg[5] = Image::FromFile(_T(".\\Resources\\Ready\\ready006.gif"));
		m_ReadyMsg[6] = Image::FromFile(_T(".\\Resources\\Ready\\ready007.gif"));
		m_ReadyMsg[7] = Image::FromFile(_T(".\\Resources\\Ready\\ready008.gif"));
		m_ReadyMsg[8] = Image::FromFile(_T(".\\Resources\\Ready\\ready009.gif"));
		m_ReadyMsg[9] = Image::FromFile(_T(".\\Resources\\Ready\\ready010.gif"));
		m_ReadyMsg[10] = Image::FromFile(_T(".\\Resources\\Ready\\ready011.gif"));
		m_ReadyMsg[11] = Image::FromFile(_T(".\\Resources\\Ready\\ready012.gif"));
		m_ReadyMsg[12] = Image::FromFile(_T(".\\Resources\\Ready\\ready013.gif"));
		m_ReadyMsg[13] = Image::FromFile(_T(".\\Resources\\Ready\\ready014.gif"));
		m_ReadyMsg[14] = Image::FromFile(_T(".\\Resources\\Ready\\ready015.gif"));
		m_ReadyMsg[15] = Image::FromFile(_T(".\\Resources\\Ready\\ready016.gif"));
		m_ReadyMsg[16] = Image::FromFile(_T(".\\Resources\\Ready\\ready017.gif"));
		m_ReadyMsg[17] = Image::FromFile(_T(".\\Resources\\Ready\\ready018.gif"));
		m_ReadyMsg[18] = Image::FromFile(_T(".\\Resources\\Ready\\ready019.gif"));
		m_ReadyMsg[19] = Image::FromFile(_T(".\\Resources\\Ready\\ready020.gif"));
		m_ReadyMsg[20] = Image::FromFile(_T(".\\Resources\\Ready\\ready021.gif"));
		m_ReadyMsg[21] = Image::FromFile(_T(".\\Resources\\Ready\\ready022.gif"));
		m_ReadyMsg[22] = Image::FromFile(_T(".\\Resources\\Ready\\ready023.gif"));
		m_ReadyMsg[23] = Image::FromFile(_T(".\\Resources\\Ready\\ready024.gif"));
		m_ReadyMsg[24] = Image::FromFile(_T(".\\Resources\\Ready\\ready025.gif"));
		m_ReadyMsg[25] = Image::FromFile(_T(".\\Resources\\Ready\\ready026.gif"));
		m_ReadyMsg[26] = Image::FromFile(_T(".\\Resources\\Ready\\ready027.gif"));
		m_ReadyMsg[27] = Image::FromFile(_T(".\\Resources\\Ready\\ready028.gif"));
		m_ReadyMsg[28] = Image::FromFile(_T(".\\Resources\\Ready\\ready029.gif"));
		m_ReadyMsg[29] = Image::FromFile(_T(".\\Resources\\Ready\\ready030.gif"));
		m_ReadyMsg[30] = Image::FromFile(_T(".\\Resources\\Ready\\ready031.gif"));
		m_ReadyMsg[31] = Image::FromFile(_T(".\\Resources\\Ready\\ready032.gif"));
		m_ReadyMsg[32] = Image::FromFile(_T(".\\Resources\\Ready\\ready033.gif"));
		m_ReadyMsg[33] = Image::FromFile(_T(".\\Resources\\Ready\\ready034.gif"));
		m_ReadyMsg[34] = Image::FromFile(_T(".\\Resources\\Ready\\ready035.gif"));
		m_ReadyMsg[35] = Image::FromFile(_T(".\\Resources\\Ready\\ready036.gif"));
		m_ReadyMsg[36] = Image::FromFile(_T(".\\Resources\\Ready\\ready037.gif"));
		m_ReadyMsg[37] = Image::FromFile(_T(".\\Resources\\Ready\\ready038.gif"));
		m_ReadyMsg[38] = Image::FromFile(_T(".\\Resources\\Ready\\ready039.gif"));
		m_ReadyMsg[39] = Image::FromFile(_T(".\\Resources\\Ready\\ready040.gif"));
		m_ReadyMsg[40] = Image::FromFile(_T(".\\Resources\\Ready\\ready041.gif"));
		m_ReadyMsg[41] = Image::FromFile(_T(".\\Resources\\Ready\\ready042.gif"));
		m_ReadyMsg[42] = Image::FromFile(_T(".\\Resources\\Ready\\ready043.gif"));
		m_ReadyMsg[43] = Image::FromFile(_T(".\\Resources\\Ready\\ready044.gif"));
		m_ReadyMsg[44] = Image::FromFile(_T(".\\Resources\\Ready\\ready045.gif"));
		m_ReadyMsg[45] = Image::FromFile(_T(".\\Resources\\Ready\\ready046.gif"));
		m_ReadyMsg[46] = Image::FromFile(_T(".\\Resources\\Ready\\ready047.gif"));
		m_ReadyMsg[47] = Image::FromFile(_T(".\\Resources\\Ready\\ready048.gif"));
		m_ReadyMsg[48] = Image::FromFile(_T(".\\Resources\\Ready\\ready049.gif"));
		m_ReadyMsg[49] = Image::FromFile(_T(".\\Resources\\Ready\\ready050.gif"));
		m_ReadyMsg[50] = Image::FromFile(_T(".\\Resources\\Ready\\ready051.gif"));
		m_ReadyMsg[51] = Image::FromFile(_T(".\\Resources\\Ready\\ready052.gif"));
		m_ReadyMsg[52] = Image::FromFile(_T(".\\Resources\\Ready\\ready053.gif"));
		m_ReadyMsg[53] = Image::FromFile(_T(".\\Resources\\Ready\\ready054.gif"));
		m_ReadyMsg[54] = Image::FromFile(_T(".\\Resources\\Ready\\ready055.gif"));
		m_ReadyMsg[55] = Image::FromFile(_T(".\\Resources\\Ready\\ready056.gif"));
		m_ReadyMsg[56] = Image::FromFile(_T(".\\Resources\\Ready\\ready057.gif"));
		m_ReadyMsg[57] = Image::FromFile(_T(".\\Resources\\Ready\\ready058.gif"));
		m_ReadyMsg[58] = Image::FromFile(_T(".\\Resources\\Ready\\ready059.gif"));
		m_ReadyMsg[59] = Image::FromFile(_T(".\\Resources\\Ready\\ready060.gif"));
		m_ReadyMsg[60] = Image::FromFile(_T(".\\Resources\\Ready\\ready061.gif"));
		m_ReadyMsg[61] = Image::FromFile(_T(".\\Resources\\Ready\\ready062.gif"));
		m_ReadyMsg[62] = Image::FromFile(_T(".\\Resources\\Ready\\ready063.gif"));
		m_ReadyMsg[63] = Image::FromFile(_T(".\\Resources\\Ready\\ready064.gif"));
		m_ReadyMsg[64] = Image::FromFile(_T(".\\Resources\\Ready\\ready065.gif"));
		m_ReadyMsg[65] = Image::FromFile(_T(".\\Resources\\Ready\\ready066.gif"));
		m_ReadyMsg[66] = Image::FromFile(_T(".\\Resources\\Ready\\ready067.gif"));
		m_ReadyMsg[67] = Image::FromFile(_T(".\\Resources\\Ready\\ready068.gif"));
		m_ReadyMsg[68] = Image::FromFile(_T(".\\Resources\\Ready\\ready069.gif"));
		m_ReadyMsg[69] = Image::FromFile(_T(".\\Resources\\Ready\\ready070.gif"));
		m_ReadyMsg[70] = Image::FromFile(_T(".\\Resources\\Ready\\ready071.gif"));
		m_ReadyMsg[71] = Image::FromFile(_T(".\\Resources\\Ready\\ready072.gif"));
		m_ReadyMsg[72] = Image::FromFile(_T(".\\Resources\\Ready\\ready073.gif"));
		m_ReadyMsg[73] = Image::FromFile(_T(".\\Resources\\Ready\\ready074.gif"));
		m_ReadyMsg[74] = Image::FromFile(_T(".\\Resources\\Ready\\ready075.gif"));
		m_ReadyMsg[75] = Image::FromFile(_T(".\\Resources\\Ready\\ready076.gif"));
		m_ReadyMsg[76] = Image::FromFile(_T(".\\Resources\\Ready\\ready077.gif"));
		m_ReadyMsg[77] = Image::FromFile(_T(".\\Resources\\Ready\\ready078.gif"));
		m_ReadyMsg[78] = Image::FromFile(_T(".\\Resources\\Ready\\ready079.gif"));
	}


	m_HPBarBody = Image::FromFile(_T(".\\Resources\\UI\\HPBar.png"));
	m_HpBar = Image::FromFile(_T(".\\Resources\\UI\\HealthBar.png"));
	m_HpBarImgWidth = m_HpBar->GetWidth() *2.0f;
	m_HpBarImgHeight = m_HpBar->GetHeight() * 1.35f;

	m_Map = Image::FromFile(_T(".\\Resources\\Map\\Map.png"));
	m_MapImgWidth = m_Map->GetWidth() * 2.0f;;
	m_MapImgHeight = m_Map->GetHeight() * 2.0f;;

	for (int i = 0; i < 100; i++)
	{
		m_MapImg.push_back(m_Map);
	}
}

void CInGameScene::Ingame_Update(HWND a_hWnd, float a_DeltaTime)
{
	static float AniTickCnt = 0.01f;
	AniTickCnt -= a_DeltaTime;

	if (GameReady == false)
	{
		if (AniTickCnt < 0.0f)
		{
			ImgNum++;
			AniTickCnt = 0.01f;

			if (78 <= ImgNum)
				GameReady = true;
		}
	}
}

void CInGameScene::Ingame_Render(HDC a_hdc, RECT & a_RT)
{
	StretchBlt(a_hdc, 0, 0, a_RT.right, a_RT.bottom, m_BGImgDC, 0, 0, m_TexImgWidth, m_TexImgHeight, SRCCOPY);
	//StretchBlt(a_hdc, 0, 0, a_RT.right, a_RT.bottom, m_MapImgDC, 0, 0, m_TexImgWidth, m_TexImgHeight, SRCCOPY);

	Graphics graphics(a_hdc);

	if (GameReady == false)
	{
		graphics.DrawImage(m_ReadyMsg[ImgNum], 450.0f, 150.0f,
			(float)m_ReadyMsg[ImgNum]->GetWidth(), (float)m_ReadyMsg[ImgNum]->GetHeight());
	}
	graphics.DrawImage(m_HPBarBody, 50.0f, 150.0f, (float)m_HPBarBody->GetWidth(), m_HPBarBody->GetHeight());
	graphics.DrawImage(m_HpBar, Rect(77.0f, 159.0f, m_HpBarImgWidth, m_HpBarImgHeight));

	//for (int i = 0; i < 3; i++)
	//{
	//	m_MapImgPos[i].x = i * (m_MapImgWidth - 5.0f);
	//	m_MapImgPos[i].y = 700.0f - (i * 100.0f);
	//	graphics.DrawImage(m_MapImg[i], m_MapImgPos[i].x, m_MapImgPos[i].y, m_MapImgWidth, m_MapImgHeight);
	//}
}

void CInGameScene::Ingame_Destroy()
{
	for (int i = 0; i < m_MapImg.size(); i++)
	{
		if (m_MapImg[i] != NULL)
		{
			delete m_MapImg[i];
			m_MapImg[i] = NULL;
		}
	}
	m_MapImg.clear();
}
