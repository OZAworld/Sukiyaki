/*
*	アプリケーションの初期化を行うクラス
*
*	2015/06/23		Y.Ozawa
*/

#include "Lib.h"
#include <crtdbg.h>
#include <cassert>

LPDIRECT3DDEVICE9		d3d = 0;
LPDIRECTINPUTDEVICE8	dInputDevice = 0;
D3DPRESENT_PARAMETERS	presentParam;

App::App()
{
	DebugLog("アプリケーションを生成しました\n");

	//メモリリークを検出する
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//アプリケーションの初期化
	Initialize(win_title, Rect(0, 0, 640, 480), false, nullptr, 0);
}

App::App(char* win_title, RECT win_rect, bool win_fullscreen, HINSTANCE hInst, int cmdShow)
{
	DebugLog("アプリケーションを生成しました\n");

	//メモリリークを検出する
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//アプリケーションの初期化
	Initialize(win_title, win_rect, win_fullscreen, hInst, cmdShow);
}

App::~App()
{
	DebugLog("アプリケーションを解放しました\n");

	//アプリケーションの終了処理
	Release();
}

//	初期化
void App::Initialize(char* win_title, RECT win_rect, bool win_fullscreen, HINSTANCE hInst, int cmdShow)
{
	//	引数をメンバー変数に保存する
	App::win_title = win_title;
	App::win_rect = win_rect;
	App::win_fullscreen = win_fullscreen;

	//ウィンドウの初期化
	if (!InitWindow(hInst, cmdShow))
		DebugAlert("ウィンドウを\nしょきかできませんでした");

	//Direct3Dの初期化
	if (!InitDirect3d())
		DebugAlert("Direct3Dを\n初期化できませんでした。");

	//プレゼンテーションパラメータの初期化
	if (!InitPresentParam())
		DebugAlert("プレゼンテーションパラメータを\n初期化できませんでした。");

	//Direct3Dデバイスの初期化
	if (!InitD3dDevice())
		DebugAlert("Direct3Dデバイスを\n初期化できませんでした。");

	//DirectInputの初期化
	if (!InitDirectInput(hInst))
		DebugAlert("DirectInputを\n初期化できませんでした。");

	//DirectInputデバイスの初期化
	if (!InitDinputDevice())
		DebugAlert("DirectInputデバイスを\n初期化できませんでした。");

	DebugLog("アプリケーションを初期化しました。\n");
}

//	解放
void App::Release()
{
	//デバッグビルド時にビープ音を鳴らす
#if defined (DEBUG) | defined(_DEBUG)
	MessageBeep(MB_OK);
#endif

	//コンソールを閉じる
	CloseConsole();

	//モデルのテンプレートを破棄する
	SafeRelease(d3d);
	SafeRelease(direct3d);
	SafeRelease(dInput);
}