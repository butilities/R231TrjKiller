#include "Define.h"
#include "ProcProc.h"

    int ProcProc::RemoveProc(const char* name){
        HANDLE hProcess = GetProcessHandle((char*)name);
        if (hProcess==NULL){
            return ProcessNotExist;
        }else{
            if(TerminateProcess(hProcess,0)==0){
                return ProcessNotDelete;
            }else{
                return ProcessDeleted;
            }
        }

    }

    HANDLE ProcProc::GetProcessHandle(LPSTR szExeName)
    {
        PROCESSENTRY32 Pc = { sizeof(PROCESSENTRY32) };
        HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
        if(Process32First(hSnapshot, &Pc)){
            do{
                if(!strcmp(Pc.szExeFile, szExeName)) {
                    return OpenProcess(PROCESS_ALL_ACCESS, TRUE, Pc.th32ProcessID);
                }
            }while(Process32Next(hSnapshot, &Pc));
        }
        return NULL;
     }

