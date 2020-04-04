# SuperDllHijack

一种通用Dll劫持技术，不再需要手工导出Dll的函数接口了，so easy！

使用方法：

编写一个和劫持目标Dll同名的dll（如target.dll），原始dll改名为其他名字（如target.dll.1)，在DllMain种调用SuperDllHijack接口完成劫持。

## 更新：

2020年4月4日
1. 修正x64获取peb的bug。感谢[@yves-yl](https://github.com/yves-yl)、[@kiwings](https://github.com/kiwings)、[@6769](https://github.com/6769)。

**更多使用请看`example`代码。**

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

技术细节请看博客：[https://anhkgg.com/dllhijack/](https://anhkgg.com/dllhijack/)

[https://mp.weixin.qq.com/s/Nx4C2mx94V9vhvU8Eqfobg](https://mp.weixin.qq.com/s/Nx4C2mx94V9vhvU8Eqfobg)<br/>
[https://bbs.pediy.com/thread-248050.htm](https://bbs.pediy.com/thread-248050.htm)<br/>

# 支持作者

![img](pay.png)
