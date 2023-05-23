//Generate by DllHijackExportTest.py

#include <Windows.h>

#pragma comment(linker, "/EXPORT:VerQueryValueW=_DLLHijacker_VerQueryValueW,@1")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoW=_DLLHijacker_GetFileVersionInfoW,@2")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeW=_DLLHijacker_GetFileVersionInfoSizeW,@3")

#define EXTERNC extern "C"
#define NAKED __declspec(naked)
#define EXPORT __declspec(dllexport)
#define ALCPP EXPORT NAKED
#define ALSTD EXTERNC EXPORT NAKED void __stdcall
#define ALCFAST EXTERNC EXPORT NAKED void __fastcall
#define ALCDECL EXTERNC NAKED void __cdecl

namespace DLLHijacker
{
    HMODULE m_hModule = NULL;
    DWORD m_dwReturn[17] = { 0 };
    inline BOOL WINAPI Load()
    {
        TCHAR tzPath[MAX_PATH];
        lstrcpy(tzPath, TEXT("version.dll"));
        m_hModule = LoadLibrary(tzPath);
        if (m_hModule == NULL)
            return FALSE;
        return (m_hModule != NULL);
    }
    inline VOID WINAPI Free()
    {
        if (m_hModule)
            FreeLibrary(m_hModule);
    }
    FARPROC WINAPI GetAddress(PCSTR pszProcName)
    {
        FARPROC fpAddress;
        CHAR szProcName[16];
        fpAddress = GetProcAddress(m_hModule, pszProcName);
        if (fpAddress == NULL)
        {
            if (HIWORD(pszProcName) == 0)
            {
                //wsprintf(szProcName, "%d", pszProcName);
                //pszProcName = szProcName;
            }
            ExitProcess(-2);
        }
        return fpAddress;
    }
}
using namespace DLLHijacker;
VOID Hijack()
{
    MessageBoxW(NULL, L"DLL Hijack!", L":)", 0);
}
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, PVOID pvReserved)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);
        if (Load())
            Hijack();
    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
        Free();
    }
    return TRUE;
}
ALCDECL DLLHijacker_VerQueryValueW(void)
{
   

}
ALCDECL DLLHijacker_GetFileVersionInfoW(void)
{
    
}
ALCDECL DLLHijacker_GetFileVersionInfoSizeW(void)
{
   
}
