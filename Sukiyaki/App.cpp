/*
*	�A�v���P�[�V�����̏��������s���N���X
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
	DebugLog("�A�v���P�[�V�����𐶐����܂���\n");

	//���������[�N�����o����
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//�A�v���P�[�V�����̏�����
	Initialize(win_title, Rect(0, 0, 640, 480), false, nullptr, 0);
}

App::App(char* win_title, RECT win_rect, bool win_fullscreen, HINSTANCE hInst, int cmdShow)
{
	DebugLog("�A�v���P�[�V�����𐶐����܂���\n");

	//���������[�N�����o����
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//�A�v���P�[�V�����̏�����
	Initialize(win_title, win_rect, win_fullscreen, hInst, cmdShow);
}

App::~App()
{
	DebugLog("�A�v���P�[�V������������܂���\n");

	//�A�v���P�[�V�����̏I������
	Release();
}

//	������
void App::Initialize(char* win_title, RECT win_rect, bool win_fullscreen, HINSTANCE hInst, int cmdShow)
{
	//	�����������o�[�ϐ��ɕۑ�����
	App::win_title = win_title;
	App::win_rect = win_rect;
	App::win_fullscreen = win_fullscreen;

	//�E�B���h�E�̏�����
	if (!InitWindow(hInst, cmdShow))
		DebugAlert("�E�B���h�E��\n���傫���ł��܂���ł���");

	//Direct3D�̏�����
	if (!InitDirect3d())
		DebugAlert("Direct3D��\n�������ł��܂���ł����B");

	//�v���[���e�[�V�����p�����[�^�̏�����
	if (!InitPresentParam())
		DebugAlert("�v���[���e�[�V�����p�����[�^��\n�������ł��܂���ł����B");

	//Direct3D�f�o�C�X�̏�����
	if (!InitD3dDevice())
		DebugAlert("Direct3D�f�o�C�X��\n�������ł��܂���ł����B");

	//DirectInput�̏�����
	if (!InitDirectInput(hInst))
		DebugAlert("DirectInput��\n�������ł��܂���ł����B");

	//DirectInput�f�o�C�X�̏�����
	if (!InitDinputDevice())
		DebugAlert("DirectInput�f�o�C�X��\n�������ł��܂���ł����B");

	DebugLog("�A�v���P�[�V���������������܂����B\n");
}

//	���
void App::Release()
{
	//�f�o�b�O�r���h���Ƀr�[�v����炷
#if defined (DEBUG) | defined(_DEBUG)
	MessageBeep(MB_OK);
#endif

	//�R���\�[�������
	CloseConsole();

	//���f���̃e���v���[�g��j������
	SafeRelease(d3d);
	SafeRelease(direct3d);
	SafeRelease(dInput);
}