#include "Lib.h"
#include <cstdio>

const TCHAR *putf(const TCHAR *format, ...)
{
	va_list	args;
	static TCHAR str[256];
	va_start(args, format);
	vsprintf_s(str, format, args);
	va_end(args);

	return str;
}

RECT Rect(int x, int y, int width, int height)
{
	RECT r = { x, y, width, height };
	return r;
}

//	デバッグ用のアラートを出力する
void DebugAlert(TCHAR *format, ...)
{
	va_list args;
	TCHAR str[256];
	va_start(args, format);
	vsprintf_s(str, format, args);
	va_end(args);

	OutputDebugString(str);
	MessageBox(nullptr, str, "Error", MB_ICONSTOP);
}

//	デバッグ用のログを出力する
void DebugLog(TCHAR *format, ...)
{
	va_list args;
	TCHAR str[256];
	va_start(args, format);
	vsprintf_s(str, format, args);
	va_end(args);

	OutputDebugString(str);
	printf(str);
}