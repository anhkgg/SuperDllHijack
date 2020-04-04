# SuperDllHijack

[中文版](./README-zh_CN.md)

A general DLL hijack technology, don't need to manually export the same function interface of the DLL, so easy!


Usage：

Create a DLL with the same name of the hijacked DLL(such as，target.dll), and rename the hijacked DLL to other name(such as, target.dll.1), then call `SuperDllHijack` function to do the hajick work. 


## Update:

2020-4-4
1. fixed the bug of getting peb in x64。Thanks for [@yves-yl](https://github.com/yves-yl)、[@kiwings](https://github.com/kiwings)、[@6769](https://github.com/6769)。

**You can see more details in the `example` code.**

```
VOID DllHijack1(HMODULE hMod)
{
	TCHAR tszDllPath[MAX_PATH] = { 0 };

	GetModuleFileName(hMod, tszDllPath, MAX_PATH);
	PathRemoveFileSpec(tszDllPath);
	PathAppend(tszDllPath, TEXT("target.dll.1"));

	SuperDllHijack(L"target.dll", tszDllPath);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		DllHijack(hModule); break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
```

There are the related articles about the technology：

1. [https://anhkgg.com/dllhijack/](https://anhkgg.com/dllhijack/)
2. [https://mp.weixin.qq.com/s/Nx4C2mx94V9vhvU8Eqfobg](https://mp.weixin.qq.com/s/Nx4C2mx94V9vhvU8Eqfobg)<br/>
3. [https://bbs.pediy.com/thread-248050.htm](https://bbs.pediy.com/thread-248050.htm)<br/>

# Support me

![img](pay.png)
