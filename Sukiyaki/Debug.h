#pragma once

extern const TCHAR *putf(const TCHAR *format, ...);
extern RECT Rect(int x, int y, int width, int height);


//�f�o�b�O�p�̃A���[�g���o�͂���
extern void DebugAlert(TCHAR *format, ...);
//�f�o�b�O�p�̃��O���o�͂���
extern void DebugLog(TCHAR *format, ...);
