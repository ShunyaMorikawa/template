//========================================
//
//�V���[�e�B���O�A�N�V����[object2D.h]
//Author�F�X��x��
//
//========================================
#ifndef _OBJECT2D_H_
#define _OBJECT2D_H_
#include "object.h"

//========================================
//�}�N����`
//========================================
#define MAX_OBJ	(64)		//�w�i�̍ő吔
#define FVF_VERTEX_2D	(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)    

//========================================
//�I�u�W�F�N�g2D�N���X
//========================================
class CObject2D : public CObject
{
public:

	//========================================
	//���_���[2D]�̍\���̂��`
	//========================================
	typedef struct
	{
		D3DXVECTOR3 pos;	//���_���W
		float rhw;			//���W�ϊ��p�W��(1.0f�ŌŒ�)
		D3DCOLOR col;		//���_�J���[
		D3DXVECTOR2 tex;	//�e�N�X�`�����W
	}VERTEX_2D;

	CObject2D();	//�R���X�g���N�^
	~CObject2D();	//�f�X�g���N�^

	//�����o�֐�
	HRESULT Init(void);		//������
	void Uninit(void);		//�I��
	void Update(void);		//�X�V
	void Draw(void);		//�`��
	static CObject2D *Create();		//�I�u�W�F�N�g�̐���
	void SetVertex(void);			//���_���
	void SetSize(float fWidht, float fHeight);	//�傫��
	void SetPosition(D3DXVECTOR3 pos);			//�ʒu�ݒ�
	D3DXVECTOR3 GetPosition(void);				//�ʒu�擾
	void BindTexture(int pTexture);				//�e�N�X�`�����蓖��
	void SetVertexAnim(int Num, int Cnt);		//�e�N�X�`���A�j���[�V����
	void SetPosVertex(void);		//���_���
	void SetVertexBg(void);			//�w�i�̒��_���
	void SetVertexEffect(float m_fRadius, D3DXCOLOR m_col);		//�G�t�F�N�g�̒��_���W
	void SetVertexMoveBg(void);
	void SetScoreVertex(void);		//�X�R�A�̒��_���
	void SetScore(int nNum[8]);

private:
	//�����o�ϐ�
	int m_nIdxTexture;		//�e�N�X�`���̔ԍ�
	LPDIRECT3DVERTEXBUFFER9	m_pVtxBuff;		//���_�����i�[
	D3DXVECTOR3 m_pos;		//�ʒu
	D3DXVECTOR3 m_move;		//�ړ���
	D3DXVECTOR3 m_rot;		//����
	D3DXCOLOR m_col;        //�F
	float m_fLength;		//�Ίp���̒���
	float m_fAngle;			//�Ίp���̊p�x
	int m_nCounterAnim;     //�A�j���[�V�����J�E���^�[
	int m_nPatternAnim;     //�A�j���[�V�����p�^�[��No,
	float m_aTexV;			//�e�N�X�`�����W�̊J�n�ʒu
};

#endif