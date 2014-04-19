#ifndef ProcPROC_H_INCLUDED
#define ProcPROC_H_INCLUDED
#include <windows.h>
#include <tlhelp32.h>

class ProcProc
{
    public:
    int ProcProc::RemoveProc(const char* name);
    HANDLE ProcProc::GetProcessHandle(LPSTR szExeName);
};

#endif // SERPROC_H_INCLUDED
