// SPluginMirror.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "SPluginMirror.h"
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

void setLogLevel(int nLogLevel)
{
    return;
}

void unMountAll()
{
    return g_oProxyService.UnAllMount();
}