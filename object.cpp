//========================================
//
//オブジェクト処理[object.cp]
//Author：森川駿弥
//
//========================================
#include "object.h"
#include "camera.h"
#include "manager.h"
#include "texture.h"

//========================================
//静的メンバ変数宣言
//========================================
int CObject::m_nNumAll = 0;
CObject *CObject::m_Top = nullptr;
CObject *CObject::m_Current = nullptr;

//========================================
//コンストラクタ
//========================================
CObject::CObject(void)
{//値クリア
	if (m_Top == nullptr && m_Current == nullptr)
	{//先頭と最後がnullptrの時
		m_Top = this;	//自身を代入
		m_nNumAll++;					//総数をカウントアップ
		m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//位置
		m_Next = nullptr;	//次
		m_Prev = nullptr;	//前
		m_Current = this;	//自身を代入
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
//デストラクタ
//========================================
CObject::~CObject(void)
{
}

//========================================
//すべてのオブジェクトの破棄
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
			//次の値を保存
			Next = Now->m_Next;

			//先頭の終了
			//Now->Uninit();

			//次
			Now = Next;

			if (Next != nullptr)
			{
				//前回をnullptrにする
				Next->m_Prev = nullptr;
			}
		}
	}
}

//========================================
//すべてのオブジェクトの更新
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
			//先頭の更新
			Now->Update();

			//今の次
			Now = Now->m_Next;
		}
	}
}

//========================================
//すべてのオブジェクトの描画
//========================================
void CObject::DrawAll(void)
{
	CCamera *pCamera = CManager::GetInstance()->GetCamera();

	//カメラ設定
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
			//先頭の描画
			Now->Draw();

			//次
			Now = Now->m_Next;
		}
	}
}

//========================================
//オブジェクトの破棄
//========================================
void CObject::Release(void)
{
	//CObject *Now = this;

	//int nNum = m_nID;

	//if (Now != nullptr)
	//{
	//	//オブジェクト(自分自身の破棄)
	//	delete Now;
	//	Now = nullptr;

	//	//総数をカウントダウン
	//	m_nNumAll--;
	//}
}

//========================================
//TYPEの取得
//========================================
CObject *CObject::GetObject(int nIdx)
{
	CObject *Now = m_Top;

	return Now;
}

//========================================
//テクスチャの割り当て
//========================================
void CObject::BindTexture(int pTexture)
{
	m_nIdxTexture = pTexture;
}