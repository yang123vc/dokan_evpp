// CPluginMirror.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "CPluginMirror.h"
#include "..\common\plugin.h"
#include "proxy.h"

#include "log.h"

extern HMODULE g_hModule;
lpp::CProxyService g_oProxyService;     // 全局代理对象

void ReadFormChannel(UINT uSize, void * pData)
{
    g_oProxyService.ReadFormChannel(uSize, pData);
}

void *Register(void* pWriteToChannel)
{
    return (g_oProxyService.Register(pWriteToChannel, ReadFormChannel, g_hModule));
}

BOOL InitModule(int logLevel)
{
    return g_oProxyService.InitModule(logLevel, g_oProxyService.GetLogName());
}

BOOL UnInitModule()
{
    return g_oProxyService.UninitModule();
}

unsigned long map(BOOL bReadonly, BOOL bNetwork, const TCHAR * pstrRootDirectory, unsigned long *pMountId)
{
    return g_oProxyService.Map(bReadonly, bReadonly, pstrRootDirectory, pMountId);
}

unsigned long unmap(unsigned long nMountId)
{
    return g_oProxyService.UnMap(nMountId);
}

void setLogLevel(int nLogLevel)
{
    return;
}

unsigned long GetMaps(unsigned int nSize, void * pBuffer)
{
    return g_oProxyService.GetMaps(nSize, pBuffer);
}