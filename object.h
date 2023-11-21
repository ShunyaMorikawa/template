//========================================
//
//オブジェクト処理[object.h]
//Author：森川駿弥
//
//========================================
#ifndef _OBJECT_H_
#define _OBJECT_H_

//========================================
//マクロ定義
//========================================
#define MAX_DATA (100)	//最大数

//========================================
//オブジェクトクラス
//========================================
class CObject
{
public: 
	enum TYPE
	{//種類
		TYPE_NONE = 0,	//種類無し
		TYPE_PLAYER,	//プレイヤー
		TYPE_ENEMY,		//敵
		TYPE_BULLET,	//弾
		TYPE_EXPLOSION,	//爆発
		TYPE_EFFECT,	//エフェクト
		TYPE_ITEM,		//アイテム
		TYPE_MAX
	};

	CObject();				//コンストラクタ
	virtual ~CObject();		//デストラクタ

	//純粋仮想関数
	virtual HRESULT Init(void) = 0;
	virtual void Uninit(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;
	virtual void SetVertex(void) = 0;
	virtual void SetSize(float fWidht, float fHeight) = 0;
	virtual void SetPosition(D3DXVECTOR3 pos) = 0;
	virtual D3DXVECTOR3 GetPosition(void) = 0;

	//メンバ関数
	static void ReleaseAll(void);
	static void UpdateAll(void);
	static void DrawAll(void);
	static CObject *GetObject(int nIdx);
	void BindTexture(int pTexture);				//テクスチャ割り当て

	D3DXVECTOR3 Getpos(void) { return m_pos; }
protected:
	void Release(void);

private:
	static int m_nNumAll;	//オブジェクト総数
	int m_nID;				//自分自身のID
	D3DXVECTOR3 m_pos;		//位置
	int m_nIdxTexture;		//テクスチャの番号

	CObject *m_Next;	//次
	CObject *m_Prev;	//前回
	static CObject *m_Top;		//一番上
	static CObject *m_Current;	//一番後ろ
};

#endif
