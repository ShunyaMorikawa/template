//========================================
//
//入力処理[input.h]
//Author：森川駿弥
//
//========================================
#ifndef _INPUT_H_
#define _INPUT_H_

#define  DIRECTINPUT_VERSION (0x0800)   //ビルド時の警告対処用マクロ
#include "dinput.h"   //入力処理に必要
#include "Xinput.h"

//========================================
//ライブラリのリンク
//========================================
#pragma comment(lib,"dinput8.lib")  //入力処理に必要
#pragma comment (lib,"xinput.lib")

//========================================
//マクロ定義
//========================================
#define NUM_MAX_KEY		(256)	//キーの最大数
#define NUM_MAX_PAD		(4)		//パッドの最大数
//#define NUM_PAD_MAX  (13)    //パッドのボタンの最大数

//========================================
//インプットクラス
//========================================
class CInput
{
public:
	CInput();			//コンストラクタ
	virtual ~CInput();	//デストラクタ

	//メンバ関数
	virtual HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	virtual void Uninit(void);
	virtual void Update(void) = 0;

protected:
	static LPDIRECTINPUT8 m_pInput;		//DirectInputオブジェクトへのポインタ
	LPDIRECTINPUTDEVICE8 m_pDevice;		//入力デバイス(キーボード)へのポインタ
};

//========================================
//キーボードクラス
//========================================
class CInputKeyboard : public CInput
{
public:
	CInputKeyboard();	//コンストラクタ
	~CInputKeyboard();	//デストラクタ

	//メンバ関数
	HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	void Uninit(void);
	void Update(void);
	bool GetPress(int nKey);
	bool GetTrigger(int nKey);

private:
	//メンバ変数
	BYTE m_aKeyState[NUM_MAX_KEY];			//キーボードのプレス情報
	BYTE m_aKeyStateTrigger[NUM_MAX_KEY];	//キーボードのトリガー情報
};

//========================================
//コントローラークラス
//========================================
class CInputPad : public CInput
{
public:
	enum JOYKEY
	{
		BUTTON_UP,		//十字↑
		BUTTON_DOWN,	//十字↓
		BUTTON_LEFT,	//十字←
		BUTTON_RIGHT,	//十字→
		BUTTON_START,	//START
		BUTTON_BACK,	//BACK
		BUTTON_PUSHING_L,     //左スティック押し込み
		BUTTON_PUSHING_R,     //右スティック押し込み
		BUTTON_LB,		//LB
		BUTTON_RB,		//RB
		BUTTON_10,		//不明(トリガー)
		BUTTON_11,		//不明(トリガー)
		BUTTON_A,		//Aボタン
		BUTTON_B,		//Bボタン
		BUTTON_X,		//Xボタン
		BUTTON_Y,		//Yボタン
		BUTTON_XSTICK,	//Xスティック
		BUTTON_17,		//不明
		BUTTON_18,		//不明
		BUTTON_19,		//不明
		BUTTON_20,
		BUTTONSTATE_MAX
	};

	CInputPad();	//コンストラクタ
	~CInputPad();	//デストラクタ

	//メンバ関数
	HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	void Uninit(void);
	void Update(void);
	bool GetPress(int nKey, int nPlayer) {return (m_aPadState[nPlayer].Gamepad.wButtons & (0x01 << nKey)) ? true : false;}	//プレス情報取得
	bool GetTrigger(int nKey, int nPlayer) { return (m_aPadStateTrigger[nPlayer].Gamepad.wButtons & (0x01 << nKey)) ? true : false; }	//トリガー情報取得
	SHORT GetLStickXPress(JOYKEY Key, int nPlayer) { return m_aPadState[nPlayer].Gamepad.sThumbLX; }	//LスティックのX軸プレス情報取得
	SHORT GetLStickYPress(JOYKEY Key, int nPlayer) { return m_aPadState[nPlayer].Gamepad.sThumbLY; }	//LスティックのY軸プレス情報取得
	SHORT GetLStickXTrigger(JOYKEY Key, int nPlayer) { return m_aPadStateTrigger[nPlayer].Gamepad.sThumbLX; }	//LスティックのX軸トリガー情報取得
	SHORT GetLStickYTrigger(JOYKEY Key, int nPlayer) { return m_aPadStateTrigger[nPlayer].Gamepad.sThumbLY; }	//LスティックのY軸トリガー情報取得

	SHORT GetRStickXPress(JOYKEY Key, int nPlayer) { return m_aPadState[nPlayer].Gamepad.sThumbLX; }	//RスティックのX軸プレス情報取得
	SHORT GetRStickYPress(JOYKEY Key, int nPlayer) { return m_aPadState[nPlayer].Gamepad.sThumbLY; }	//RスティックのY軸プレス情報取得

private:
	//メンバ変数
	XINPUT_STATE m_aPadState[NUM_MAX_PAD];            //パッドの情報
	XINPUT_STATE m_aPadStateTrigger[NUM_MAX_PAD];     //パッドのトリガー情報
};

#endif