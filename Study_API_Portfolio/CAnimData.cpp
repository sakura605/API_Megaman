#include "stdafx.h"
#include "CAnimData.h"


CAnimData::CAnimData()
{
	for (int ii = 0; ii < AniLength; ii++)
	{
		CMotion* a_Node = new CMotion;
		m_MotionList.push_back(a_Node);
	}
}


CAnimData::~CAnimData()
{
	for (int ii = 0; ii < m_MotionList.size(); ii++)
	{
		if (m_MotionList[ii] != NULL)
		{
			delete m_MotionList[ii];
			m_MotionList[ii] = NULL;
		}
	}
	m_MotionList.clear();
}

void CAnimData::LoadAnimList(Ani_Type a_AniType)
{
	//캐릭터 이미지 로드
	if (a_AniType == Type_ZERO)
	{
		//게임 시작시 떨어질때 이미지
		{
			m_MotionList[(int)Ready_St]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_001.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_002.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_003.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_004.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_005.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_006.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_007.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_008.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_009.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_010.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_011.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_012.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_013.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_014.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_015.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_016.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_017.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_018.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_019.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_020.gif"));
			m_MotionList[(int)Ready_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Ready\\Z01_Ready_frame_021.gif"));
		}
		//평상시
		{
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_001.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_002.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_003.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_004.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_005.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_006.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_007.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_008.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_009.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_010.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_011.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_012.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_013.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_014.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_015.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_016.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_017.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_018.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_019.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_020.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_021.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_022.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_023.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_024.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_025.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_026.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_027.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_028.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_029.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_030.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_031.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_032.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_033.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_034.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_035.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_036.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_037.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_038.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_039.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_040.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_041.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_042.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_043.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_044.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_045.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_046.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_047.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_048.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_049.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_050.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_051.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_052.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_053.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_054.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_055.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_056.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_057.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_058.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_059.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_060.gif"));
			m_MotionList[(int)Idle]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Idle\\Z02_Idle_frame_061.gif"));
		}

		//걷기 시작
		{
			m_MotionList[(int)Walk_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Beg\\Z06_Walk_1beg_frame_001.gif"));
			m_MotionList[(int)Walk_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Beg\\Z06_Walk_1beg_frame_002.gif"));
			m_MotionList[(int)Walk_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Beg\\Z06_Walk_1beg_frame_003.gif"));
			m_MotionList[(int)Walk_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Beg\\Z06_Walk_1beg_frame_004.gif"));
			m_MotionList[(int)Walk_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Beg\\Z06_Walk_1beg_frame_005.gif"));
			m_MotionList[(int)Walk_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Beg\\Z06_Walk_1beg_frame_006.gif"));
			m_MotionList[(int)Walk_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Beg\\Z06_Walk_1beg_frame_007.gif"));
		}
		//걷기 중
		{
			m_MotionList[(int)Walk_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Run\\Z06_Walk_2run_frame_001.gif"));
			m_MotionList[(int)Walk_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Run\\Z06_Walk_2run_frame_002.gif"));
			m_MotionList[(int)Walk_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Run\\Z06_Walk_2run_frame_003.gif"));
			m_MotionList[(int)Walk_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Run\\Z06_Walk_2run_frame_004.gif"));
			m_MotionList[(int)Walk_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Run\\Z06_Walk_2run_frame_005.gif"));
			m_MotionList[(int)Walk_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Run\\Z06_Walk_2run_frame_006.gif"));
			m_MotionList[(int)Walk_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Run\\Z06_Walk_2run_frame_007.gif"));
			m_MotionList[(int)Walk_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Run\\Z06_Walk_2run_frame_008.gif"));
			m_MotionList[(int)Walk_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Run\\Z06_Walk_2run_frame_009.gif"));
			m_MotionList[(int)Walk_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Run\\Z06_Walk_2run_frame_010.gif"));
			m_MotionList[(int)Walk_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Run\\Z06_Walk_2run_frame_011.gif"));
			m_MotionList[(int)Walk_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Run\\Z06_Walk_2run_frame_012.gif"));
			m_MotionList[(int)Walk_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Run\\Z06_Walk_2run_frame_013.gif"));
			m_MotionList[(int)Walk_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Walk\\Zero_Walk_Run\\Z06_Walk_2run_frame_014.gif"));

		}

		//대쉬
		{
			m_MotionList[(int)Dash_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Dash\\Zero_Dash_Run\\Z07_Dash_1beg_frame_001.gif"));
			m_MotionList[(int)Dash_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Dash\\Zero_Dash_Run\\Z07_Dash_1beg_frame_002.gif"));
			m_MotionList[(int)Dash_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Dash\\Zero_Dash_Run\\Z07_Dash_1beg_frame_003.gif"));
			m_MotionList[(int)Dash_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Dash\\Zero_Dash_Run\\Z07_Dash_1beg_frame_004.gif"));
			m_MotionList[(int)Dash_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Dash\\Zero_Dash_Run\\Z07_Dash_2run_frame_001.gif"));
			m_MotionList[(int)Dash_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Dash\\Zero_Dash_Run\\Z07_Dash_2run_frame_002.gif"));
			m_MotionList[(int)Dash_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Dash\\Zero_Dash_Run\\Z07_Dash_2run_frame_003.gif"));
		}
		//대쉬 끝
		{
			m_MotionList[(int)Dash_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Dash\\Zero_Dash_End\\Z07_Dash_3end_frame_001.gif"));
			m_MotionList[(int)Dash_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Dash\\Zero_Dash_End\\Z07_Dash_3end_frame_002.gif"));
			m_MotionList[(int)Dash_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Dash\\Zero_Dash_End\\Z07_Dash_3end_frame_003.gif"));
			m_MotionList[(int)Dash_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Dash\\Zero_Dash_End\\Z07_Dash_3end_frame_004.gif"));
			m_MotionList[(int)Dash_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Dash\\Zero_Dash_End\\Z07_Dash_3end_frame_005.gif"));
			m_MotionList[(int)Dash_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Dash\\Zero_Dash_End\\Z07_Dash_3end_frame_006.gif"));
			m_MotionList[(int)Dash_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Dash\\Zero_Dash_End\\Z07_Dash_3end_frame_007.gif"));
			m_MotionList[(int)Dash_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Dash\\Zero_Dash_End\\Z07_Dash_3end_frame_008.gif"));
		}

		//점프 
		{
			m_MotionList[(int)Jump_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Jump_Beg\\Z03_1Jump_1beg_frame_001.gif"));
			m_MotionList[(int)Jump_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Jump_Beg\\Z03_1Jump_1beg_frame_002.gif"));
			m_MotionList[(int)Jump_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Jump_Run\\Z03_1Jump_2run_frame_001.gif"));
			m_MotionList[(int)Jump_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Jump_Run\\Z03_1Jump_2run_frame_002.gif"));
		}
		//떨어지기 시작,
		{
			m_MotionList[(int)Jump_Fall_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Fall_Beg\\Z03_2Fall_1beg_frame_001.gif"));
			m_MotionList[(int)Jump_Fall_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Fall_Beg\\Z03_2Fall_1beg_frame_002.gif"));
			m_MotionList[(int)Jump_Fall_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Fall_Beg\\Z03_2Fall_1beg_frame_003.gif"));
			m_MotionList[(int)Jump_Fall_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Fall_Beg\\Z03_2Fall_1beg_frame_004.gif"));
			m_MotionList[(int)Jump_Fall_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Fall_Beg\\Z03_2Fall_1beg_frame_005.gif"));
			m_MotionList[(int)Jump_Fall_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Fall_Beg\\Z03_2Fall_1beg_frame_006.gif"));
			m_MotionList[(int)Jump_Fall_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Fall_Beg\\Z03_2Fall_1beg_frame_007.gif"));
		}
		//떨어지는 중,
		{
			m_MotionList[(int)Jump_Fall_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Fall_Run\\Z03_2Fall_2run_frame_001.gif"));
			m_MotionList[(int)Jump_Fall_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Fall_Run\\Z03_2Fall_2run_frame_002.gif"));
			m_MotionList[(int)Jump_Fall_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Fall_Run\\Z03_2Fall_2run_frame_003.gif"));
		}
		//다 떨어지고 나서,
		{
			m_MotionList[(int)Jump_Fall_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Fall_End\\Z03_2Fall_3end_frame_001.gif"));
			m_MotionList[(int)Jump_Fall_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Fall_End\\Z03_2Fall_3end_frame_002.gif"));
			m_MotionList[(int)Jump_Fall_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Fall_End\\Z03_2Fall_3end_frame_003.gif"));
			m_MotionList[(int)Jump_Fall_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Fall_End\\Z03_2Fall_3end_frame_004.gif"));
			m_MotionList[(int)Jump_Fall_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Fall_End\\Z03_2Fall_3end_frame_005.gif"));
			m_MotionList[(int)Jump_Fall_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Fall_End\\Z03_2Fall_3end_frame_006.gif"));
			m_MotionList[(int)Jump_Fall_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Fall_End\\Z03_2Fall_3end_frame_007.gif"));
			m_MotionList[(int)Jump_Fall_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Jump\\Zero_Fall_End\\Z03_2Fall_3end_frame_008.gif"));
		}


		//점프 공격
		{
			m_MotionList[(int)Jump_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_JumpAttack\\Z06_JumpAttack_2run_frame_001.gif"));
			m_MotionList[(int)Jump_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_JumpAttack\\Z06_JumpAttack_2run_frame_002.gif"));
			m_MotionList[(int)Jump_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_JumpAttack\\Z06_JumpAttack_2run_frame_003.gif"));
			m_MotionList[(int)Jump_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_JumpAttack\\Z06_JumpAttack_2run_frame_004.gif"));
			m_MotionList[(int)Jump_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_JumpAttack\\Z06_JumpAttack_2run_frame_005.gif"));
			m_MotionList[(int)Jump_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_JumpAttack\\Z06_JumpAttack_2run_frame_006.gif"));
			m_MotionList[(int)Jump_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_JumpAttack\\Z06_JumpAttack_2run_frame_007.gif"));
			m_MotionList[(int)Jump_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_JumpAttack\\Z06_JumpAttack_2run_frame_008.gif"));
			m_MotionList[(int)Jump_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_JumpAttack\\Z06_JumpAttack_2run_frame_009.gif"));
		}

		//크라우치
		{
			m_MotionList[(int)Crouch]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Crouch\\Z22_Crouch_frame_001.gif"));
			m_MotionList[(int)Crouch]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Crouch\\Z22_Crouch_frame_002.gif"));
			m_MotionList[(int)Crouch_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_CrouchAttack\\Z22_CrouchAttack_frame_002.gif"));
			m_MotionList[(int)Crouch_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_CrouchAttack\\Z22_CrouchAttack_frame_003.gif"));
			m_MotionList[(int)Crouch_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_CrouchAttack\\Z22_CrouchAttack_frame_004.gif"));
			m_MotionList[(int)Crouch_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_CrouchAttack\\Z22_CrouchAttack_frame_005.gif"));
			m_MotionList[(int)Crouch_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_CrouchAttack\\Z22_CrouchAttack_frame_006.gif"));
			m_MotionList[(int)Crouch_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_CrouchAttack\\Z22_CrouchAttack_frame_007.gif"));
			m_MotionList[(int)Crouch_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_CrouchAttack\\Z22_CrouchAttack_frame_008.gif"));
			m_MotionList[(int)Crouch_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_CrouchAttack\\Z22_CrouchAttack_frame_009.gif"));
			m_MotionList[(int)Crouch_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_CrouchAttack\\Z22_CrouchAttack_frame_010.gif"));
			m_MotionList[(int)Crouch_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_CrouchAttack\\Z22_CrouchAttack_frame_011.gif"));
			m_MotionList[(int)Crouch_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_CrouchAttack\\Z22_CrouchAttack_frame_012.gif"));
			m_MotionList[(int)Crouch_Attack]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_CrouchAttack\\Z22_CrouchAttack_frame_013.gif"));
		}


		//첫번째 베기
		{
			m_MotionList[(int)Attack_1]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_1\\Z04_Attack_1_frame_001.gif"));
			m_MotionList[(int)Attack_1]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_1\\Z04_Attack_1_frame_002.gif"));
			m_MotionList[(int)Attack_1]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_1\\Z04_Attack_1_frame_003.gif"));
			m_MotionList[(int)Attack_1]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_1\\Z04_Attack_1_frame_004.gif"));
			m_MotionList[(int)Attack_1]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_1\\Z04_Attack_1_frame_005.gif"));
			m_MotionList[(int)Attack_1]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_1\\Z04_Attack_1_frame_006.gif"));
			m_MotionList[(int)Attack_1]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_1\\Z04_Attack_1_frame_007.gif"));
			m_MotionList[(int)Attack_1]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_1\\Z04_Attack_1_frame_008.gif"));
			m_MotionList[(int)Attack_1]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_1\\Z04_Attack_1_frame_009.gif"));
			m_MotionList[(int)Attack_1]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_1\\Z04_Attack_1_frame_010.gif"));
		}
		//두번째 베기
		{
			m_MotionList[(int)Attack_2]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_2\\Z04_Attack_2_frame_001.gif"));
			m_MotionList[(int)Attack_2]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_2\\Z04_Attack_2_frame_002.gif"));
			m_MotionList[(int)Attack_2]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_2\\Z04_Attack_2_frame_003.gif"));
			m_MotionList[(int)Attack_2]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_2\\Z04_Attack_2_frame_004.gif"));
			m_MotionList[(int)Attack_2]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_2\\Z04_Attack_2_frame_005.gif"));
			m_MotionList[(int)Attack_2]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_2\\Z04_Attack_2_frame_006.gif"));
			m_MotionList[(int)Attack_2]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_2\\Z04_Attack_2_frame_007.gif"));
			m_MotionList[(int)Attack_2]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_2\\Z04_Attack_2_frame_008.gif"));
			m_MotionList[(int)Attack_2]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_2\\Z04_Attack_2_frame_009.gif"));
			m_MotionList[(int)Attack_2]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_2\\Z04_Attack_2_frame_010.gif"));
		}
		//세번째 배기
		{
			m_MotionList[(int)Attack_3]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_3\\Z04_Attack_3_frame_001.gif"));
			m_MotionList[(int)Attack_3]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_3\\Z04_Attack_3_frame_002.gif"));
			m_MotionList[(int)Attack_3]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_3\\Z04_Attack_3_frame_003.gif"));
			m_MotionList[(int)Attack_3]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_3\\Z04_Attack_3_frame_004.gif"));
			m_MotionList[(int)Attack_3]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_3\\Z04_Attack_3_frame_005.gif"));
			m_MotionList[(int)Attack_3]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_3\\Z04_Attack_3_frame_006.gif"));
			m_MotionList[(int)Attack_3]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_3\\Z04_Attack_3_frame_007.gif"));
			m_MotionList[(int)Attack_3]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_3\\Z04_Attack_3_frame_008.gif"));
			m_MotionList[(int)Attack_3]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_3\\Z04_Attack_3_frame_009.gif"));
			m_MotionList[(int)Attack_3]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_3\\Z04_Attack_3_frame_010.gif"));
			m_MotionList[(int)Attack_3]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_3\\Z04_Attack_3_frame_011.gif"));
			m_MotionList[(int)Attack_3]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_3\\Z04_Attack_3_frame_012.gif"));
		}
		//베기 마무리
		{
			m_MotionList[(int)Attack_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_End\\Z04_Attack_end_frame_001.gif"));
			m_MotionList[(int)Attack_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_End\\Z04_Attack_end_frame_002.gif"));
			m_MotionList[(int)Attack_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_End\\Z04_Attack_end_frame_003.gif"));
			m_MotionList[(int)Attack_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_End\\Z04_Attack_end_frame_004.gif"));
			m_MotionList[(int)Attack_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_End\\Z04_Attack_end_frame_005.gif"));
			m_MotionList[(int)Attack_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Attack\\Zero_Attack_End\\Z04_Attack_end_frame_006.gif"));
		}

		//벽 슬라이드
		{
			m_MotionList[(int)Slide_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Slide\\Zero_Slide_Beg\\Z11_Slide_1beg_frame_001.gif"));
			m_MotionList[(int)Slide_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Slide\\Zero_Slide_Beg\\Z11_Slide_1beg_frame_002.gif"));
			m_MotionList[(int)Slide_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Slide\\Zero_Slide_Beg\\Z11_Slide_1beg_frame_003.gif"));
			m_MotionList[(int)Slide_Beg]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Slide\\Zero_Slide_Beg\\Z11_Slide_1beg_frame_004.gif"));

			m_MotionList[(int)Slide_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Slide\\Zero_Slide_Run\\Z11_Slide_2run_frame_001.gif"));
			m_MotionList[(int)Slide_Run]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Slide\\Zero_Slide_Run\\Z11_Slide_2run_frame_002.gif"));

			m_MotionList[(int)Slide_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Slide\\Zero_Slide_End\\Z11_Slide_3end_frame_001.gif"));
			m_MotionList[(int)Slide_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Slide\\Zero_Slide_End\\Z11_Slide_2run_frame_002.gif"));
			m_MotionList[(int)Slide_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Slide\\Zero_Slide_End\\Z11_Slide_2run_frame_003.gif"));
			m_MotionList[(int)Slide_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Slide\\Zero_Slide_End\\Z11_Slide_2run_frame_004.gif"));
			m_MotionList[(int)Slide_End]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Slide\\Zero_Slide_End\\Z11_Slide_2run_frame_005.gif"));
		}

		//벽 차고 점프
		{
			m_MotionList[(int)Wall_Kick]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Wallkick\\frame_000.gif"));
			m_MotionList[(int)Wall_Kick]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Wallkick\\frame_001.gif"));
			m_MotionList[(int)Wall_Kick]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Wallkick\\frame_002.gif"));
			m_MotionList[(int)Wall_Kick]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Wallkick\\frame_003.gif"));
			m_MotionList[(int)Wall_Kick]->LoadTexImg(_T(".\\Resources\\ZeroAni\\Zero_Wallkick\\frame_004.gif"));
		}

	}
}
