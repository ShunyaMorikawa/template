//========================================
//
//�Q�[��������[game.cpp]
//Author�F�X��x��
//
//========================================
#include "game.h"
#include "object2D.h"
#include "objectx.h"
#include "time.h"
#include "manager.h"
#include "camera.h"
#include "input.h"
#include "light.h"
#include "player.h"
#include "polygon.h"

//========================================
//�}�N����`
//========================================
#define SCENE_COUNTER	(3600)	//���U���g�܂ł̑J�ڎ���

//========================================
//�ÓI�����o�ϐ�
//========================================
CObject *CGame::m_pObject[] = {};			//�I�u�W�F�N�g�̃|�C���^
CObjectX *CGame::m_pObjectX = nullptr;		//�I�u�W�F�N�gX�̃|�C���^
CObject3D *CGame::m_pObject3D = nullptr;	//�I�u�W�F�N�g3D�̃|�C���^
CGame *CGame::m_pGame = nullptr;			//�Q�[���̃|�C���^
CLight *CGame::m_pLight = nullptr;			//���C�g�̃|�C���^
CPlayer *CGame::m_pPlayer = nullptr;		//�v���C���[�̃|�C���^
CPolygon *CGame::m_pPolygon = nullptr;		//�|���S���̃|�C���^
CMap *CGame::m_pMapObject = nullptr;		//�Q�[�����I�u�W�F�N�g
CBg *CGame::m_pBg = nullptr;				//�w�i�̃|�C���^
CTime *CGame::m_pTime = nullptr;			//�^�C���̃|�C���^
CItem *CGame::m_pItem = nullptr;
CScore *CGame::m_pScore = nullptr;

//========================================
//�R���X�g���N�^
//========================================
CGame::CGame() : 
	m_bPause(false)
{
}

//========================================
//�f�X�g���N�^
//========================================
CGame::~CGame()
{
}

//========================================
//����
//========================================
CGame *CGame::Create(void)
{
	//CGame�̃|�C���^
	CGame *pGame = nullptr;

	if (pGame == nullptr)
	{
		//�C���X�^���X����
		pGame = new CGame;

		//������
		pGame->Init();
	}

	//�|�C���^��Ԃ�
	return pGame;
}

//========================================
//������
//========================================
HRESULT CGame::Init()
{
	//���C�g����
	if (m_pLight == nullptr)
	{//m_pLight��nullptr�̎�
		m_pLight = new CLight;
	}

	//���C�g�̏���������
	if (FAILED(m_pLight->Init()))
	{//���������������s�����ꍇ
		return -1;
	}
	
	if (m_pPlayer == nullptr)
	{//�v���C���[�̐���
		m_pPlayer = CPlayer::Create();
	}

	//�v���C���[�̏���������
	if (FAILED(m_pPlayer->Init()))
	{//���������������s�����ꍇ
		return -1;
	}
		
	//�|�[�Y�̏��
	m_bPause = false;

	return S_OK;
}

//========================================
//�I��
//========================================
void CGame::Uninit(void)
{
	if (m_pPlayer != nullptr)
	{//�v���C���[�j��
		m_pPlayer->Uninit();
		m_pPlayer = nullptr;
	}
	
	//pSound->Stop();
}

//========================================
//�X�V
//========================================
void CGame::Update(void)
{
	//CInputKeyboard�^�̃|�C���^
	CInputKeyboard *pInputKeyboard = nullptr;
	pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();	//�L�[�{�[�h�̏��擾

}

//========================================
//�`��
//========================================
void CGame::Draw(void)
{
}
