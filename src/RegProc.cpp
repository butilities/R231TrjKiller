#include "Define.h"
#include "RegProc.h"

    HINSTANCE hInst;
    typedef long (*sh)(long,const char*);
    sh SHDeleteKey;

    RegProc::RegProc()
    {
        hInst = LoadLibraryA("shlwapi.dll");
        SHDeleteKey=(sh)GetProcAddress(hInst, "SHDeleteKeyA");
    }

    int RegProc::RemoveItem(const char* key,const char* subkey,const char* item)
    {
        HKEY KeyH;
        long rel=0;
        if (strcmp(key,"HKLM")==0)
        rel=RegOpenKeyExA(HKEY_LOCAL_MACHINE,subkey,0,KEY_ALL_ACCESS,&KeyH);
        if (strcmp(key,"HKCU")==0)
        rel=RegOpenKeyExA(HKEY_CURRENT_USER,subkey,0,KEY_ALL_ACCESS,&KeyH);
        if (strcmp(key,"HKU")==0)
        rel=RegOpenKeyExA(HKEY_USERS,subkey,0,KEY_ALL_ACCESS,&KeyH);
        if(rel==0){
            if(RegDeleteValueA(KeyH,item)==ERROR_SUCCESS){
                RegCloseKey(KeyH);
                return KeyDeleted;
            }else{ RegCloseKey(KeyH); return KeyNotExist;}
        }else return KeyNotOpen;
    }

    int RegProc::RemoveKey(const char* key,const char* subkey,const char* item)
    {
        HKEY KeyH;
        long rel=0;
        if (strcmp(key,"HKLM")==0)
        rel=RegOpenKeyExA(HKEY_LOCAL_MACHINE,subkey,0,KEY_ALL_ACCESS,&KeyH);
        if (strcmp(key,"HKCU")==0)
        rel=RegOpenKeyExA(HKEY_CURRENT_USER,subkey,0,KEY_ALL_ACCESS,&KeyH);
        if (strcmp(key,"HKU")==0)
        rel=RegOpenKeyExA(HKEY_USERS,subkey,0,KEY_ALL_ACCESS,&KeyH);
        if(rel==0){
            if(SHDeleteKey((long)KeyH,item)==0){
                RegCloseKey(KeyH);
                return KeyDeleted;
            }else{ RegCloseKey(KeyH); return KeyNotExist;}
        }else return KeyNotOpen;
    }

