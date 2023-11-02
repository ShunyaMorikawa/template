//========================================
//
//プリコンパイル[precompile.h]
//Author：森川駿弥
//
//========================================
#ifndef PRECOMPILE_H__
#define PRECOMPILE_H__
#include "d3dx9.h"		//描画処理に必要
#include "xaudio2.h"	//サウンド処理に必要
#include <stdio.h>
#include <string.h>
#include <windows.h>

//========================================
//ライブラリのリンク
//========================================
#pragma comment(lib,"d3d9.lib")     //描画処理に必要
#pragma comment(lib,"d3dx9.lib")    //[d3d9.lib]の拡張ライブラリ
#pragma comment(lib,"dxguid.lib")   //DirectXコンポーネント(部品)使用に必要
#pragma comment(lib,"winmm.lib")    //システム時刻取得に必要

#endif // _PRECOMPILE_H_
