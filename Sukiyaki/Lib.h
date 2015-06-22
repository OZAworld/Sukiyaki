/*
*	��`
*	�w�b�_�[�t�@�C���̃C���N���[�h
*	���C�u�����̃����N
*	�}�N���̒�`
*
*	2015/06/23		Y.Ozawa
*/

#pragma once

//-------------------------------------------------------------
//	��`
//-------------------------------------------------------------
inline DWORD FtoDW(float f){ return *((DWORD*)&f); }


//-------------------------------------------------------------
//	�C���N���[�h�t�@�C��
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
//	���C�u����
//-------------------------------------------------------------
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")


//-------------------------------------------------------------
//	�}�N���̒�`
//-------------------------------------------------------------

//	�R���\�[�����J��
#define OpenConsole() {\
	AllocConsole();\
	FILE *fp;\
	freopen_s(&fp, "CONOUT$", "w", stdout);\
	freopen_s(&fp, "CONIN$", "r", stdin);\
}
//	�R���\�[�������
#define CloseConsole() {\
	FreeConsole();\
}
//	�|�C���^�������[�X����
#define SafeRelease(p) {\
	if (p)\
				{\
		p->Release();\
		p = nullptr;\
				}\
}

