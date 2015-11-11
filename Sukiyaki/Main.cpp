/*
*	�A�v���P�[�V�����̃G���g���[�|�C���g�ƃ��C�����[�v
*
*	2015/11/11		Y.Ozawa
*/


#include <memory>
#include "Lib.h"

using namespace std;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int cmdShow)
{
#if defined (DEBUG) | defined(_DEBUG)
	OpenConsole();
#endif

	//	�A�v���P�[�V�����̎��s�����\�z
	unique_ptr<App> app(new App("��������ĕ������E�E�E", Rect(0, 0, 800, 600), false, hInst, cmdShow));

	RECT recDisplay;
	HWND hDeskWnd;
	hDeskWnd = GetDesktopWindow();

	GetWindowRect(hDeskWnd, &recDisplay);

	while (app->Loop())
	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			break;
		}
	}

	return 0;
}