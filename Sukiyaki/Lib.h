/*
*	定義
*	ヘッダーファイルのインクルード
*	ライブラリのリンク
*	マクロの定義
*
*	2015/06/23		Y.Ozawa
*/

#pragma once


//-------------------------------------------------------------
//	インクルードファイル
//-------------------------------------------------------------
#include <Windows.h>

//	DirectX
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>

//	App
#include "App.h"

//	Graphic

//	Shader

//	Object

//	Debug
#include "Debug.h"

//-------------------------------------------------------------
//	ライブラリ
//-------------------------------------------------------------
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")


//-------------------------------------------------------------
//	マクロの定義
//-------------------------------------------------------------

//	コンソールを開く
#define OpenConsole() {\
	AllocConsole();\
	FILE *fp;\
	freopen_s(&fp, "CONOUT$", "w", stdout);\
	freopen_s(&fp, "CONIN$", "r", stdin);\
}
//	コンソールを閉じる
#define CloseConsole() {\
	FreeConsole();\
}
//	ポインタをリリースする
#define SafeRelease(p) {\
	if (p)\
				{\
		p->Release();\
		p = nullptr;\
				}\
}

//-------------------------------------------------------------
//	定義
//-------------------------------------------------------------
inline DWORD FtoDW(float f) { return *((DWORD*)&f); }
