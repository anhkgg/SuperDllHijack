#pragma once

#include <windows.h>

/*
dllname:		被劫持dll的原始名字
OrigDllPath:	被劫持dll改名后的完整路径
*/
void SuperDllHijack(LPCWSTR dllname, LPWSTR OrigDllPath);
