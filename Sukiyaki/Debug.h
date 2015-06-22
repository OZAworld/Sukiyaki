#pragma once

extern const TCHAR *putf(const TCHAR *format, ...);
extern RECT Rect(int x, int y, int width, int height);


//デバッグ用のアラートを出力する
extern void DebugAlert(TCHAR *format, ...);
//デバッグ用のログを出力する
extern void DebugLog(TCHAR *format, ...);
