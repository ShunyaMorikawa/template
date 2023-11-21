//========================================
//
//�I�u�W�F�N�g����[object.cp]
//Author�F�X��x��
//
//========================================
#include "object.h"
#include "camera.h"
#include "manager.h"
#include "texture.h"

//========================================
//�ÓI�����o�ϐ��錾
//========================================
int CObject::m_nNumAll = 0;
CObject *CObject::m_Top = nullptr;
CObject *CObject::m_Current = nullptr;

//========================================
//�R���X�g���N�^
//========================================
CObject::CObject(void)
{//�l�N���A
	if (m_Top == nullptr && m_Current == nullptr)
	{//�擪�ƍŌオnullptr�̎�
		m_Top = this;	//���g����
		m_nNumAll++;					//�������J�E���g�A�b�v
		m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//�ʒu
		m_Next = nullptr;	//��
		m_Prev = nullptr;	//�O
		m_Current = this;	//���g����
	}
	else if (m_Top != nullptr && m_Current != nullptr)
	{
		m_Prev = m_Current;
		m_Next = nullptr;
		m_Prev->m_Next = this;
		m_Current = this;
	}
}

//========================================
//�f�X�g���N�^
//========================================
CObject::~CObject(void)
{
}

//========================================
//���ׂẴI�u�W�F�N�g�̔j��
//========================================
void CObject::ReleaseAll(void)
{
	CObject *Now = m_Top;

	CObject *Next;

	while (1)
	{
		if (Now == nullptr)
		{
			break;
		}
		else if (Now != nullptr)
		{
			//���̒l��ۑ�
			Next = Now->m_Next;

			//�擪�̏I��
			//Now->Uninit();

			//��
			Now = Next;

			if (Next != nullptr)
			{
				//�O���nullptr�ɂ���
				Next->m_Prev = nullptr;
			}
		}
	}
}

//========================================
//���ׂẴI�u�W�F�N�g�̍X�V
//========================================
void CObject::UpdateAll(void)
{
	CObject *Now = m_Top;

	while (1)
	{
		if (Now == nullptr)
		{
			break;
		}
		else if (Now != nullptr)
		{
			//�擪�̍X�V
			Now->Update();

			//���̎�
			Now = Now->m_Next;
		}
	}
}

//========================================
//���ׂẴI�u�W�F�N�g�̕`��
//========================================
void CObject::DrawAll(void)
{
	CCamera *pCamera = CManager::GetInstance()->GetCamera();

	//�J�����ݒ�
	pCamera->SetCamera();

	CObject *Now = m_Top;

	while (1)
	{
		if (Now == nullptr)
		{
			break;
		}
		else if (Now != nullptr)
		{
			//�擪�̕`��
			Now->Draw();

			//��
			Now = Now->m_Next;
		}
	}
}

//========================================
//�I�u�W�F�N�g�̔j��
//========================================
void CObject::Release(void)
{
	//CObject *Now = this;

	//int nNum = m_nID;

	//if (Now != nullptr)
	//{
	//	//�I�u�W�F�N�g(�������g�̔j��)
	//	delete Now;
	//	Now = nullptr;

	//	//�������J�E���g�_�E��
	//	m_nNumAll--;
	//}
}

//========================================
//TYPE�̎擾
//========================================
CObject *CObject::GetObject(int nIdx)
{
	CObject *Now = m_Top;

	return Now;
}

//========================================
//�e�N�X�`���̊��蓖��
//========================================
void CObject::BindTexture(int pTexture)
{
	m_nIdxTexture = pTexture;
}