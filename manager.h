//========================================
//
//�V���[�e�B���O�A�N�V����[manager.h]
//Author�F�X��x��
//
//========================================
#ifndef _MANAGER_H_
#define _MANAGER_H_
#include "object.h"

//========================================
//�O���錾
//========================================
class CObject;
class CInputKeyboard;
class CRenderer;
class CScene;
class CDebugProc;
class CTexture;
class CCamera;
class CGame;
class CInputPad;
class CCamera;

//========================================
//�V�[���N���X
//========================================
class CScene
{
public:
	enum MODE
	{//���[�h�̗񋓌^
		MODE_GAME,		//�Q�[��
		MODE_MAX
	};

	CScene();	//�R���X�g���N
	~CScene();	//�f�X�g���N�^

	//�����o�֐�
	static CScene *Create(int nMode);

	virtual HRESULT Init() = 0;
	virtual void Uninit(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;
	MODE GetScene(void) { return m_mode; }	//���[�h�擾

private:
	//�����o�ϐ�
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;	//���_�����i�[
	int m_nIdxTexture;		//�e�N�X�`���ԍ�
	MODE m_mode;			//���݂̃��[�h
};

//========================================
//�}�l�[�W���N���X
//========================================
class CManager
{
private:	//���̏ꏊ�ŃA�N�Z�X�����Ȃ�
	CManager();		//�R���X�g���N�^
public:
	virtual ~CManager();	//�f�X�g���N�^
	static CManager *GetInstance();
public:
	//�����o�֐�
	HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	CRenderer *GetRenderer(void) { return m_pRenderer; }
	CInputKeyboard *GetInputKeyboard(void) { return m_pInputKeyboard; }
	CInputPad *GetInputPad(void) { return m_pInputPad; }
	CTexture *GetTexture(void) { return m_pTexture; }
	CDebugProc *GetDebugProc(void) { return m_pDebugProc; }
	void SetMode(CScene::MODE mode);
	CScene::MODE GetMode(CScene::MODE nowMode);	//���[�h�擾
	CCamera *GetCamera(void) { return m_pCamera; }

private:
	static CManager *m_pManager;

	//�����o�ϐ�
	int m_nCnt;		//�����J�ڃJ�E���^�[
	int m_state;	//��ԕύX
	int m_NowScene;	//���݂̃V�[��
	CRenderer *m_pRenderer;				//�����_���[�̃|�C���^
	CInputKeyboard *m_pInputKeyboard;	//�L�[�{�[�h�̃|�C���^
	CInputPad *m_pInputPad;		//�R���g���[���[�̃|�C���^
	CScene *m_pScene;			//�V�[���̃|�C���^
	CDebugProc *m_pDebugProc;	//�f�o�b�O�\���̃|�C���^
	CTexture *m_pTexture;		//�e�N�X�`���ւ̃|�C���^
	CGame *m_pGame;				//�Q�[���}�l�[�W���[�̃|�C���^
	CCamera *m_pCamera;			//�J�����̃|�C���^
};

#endif
