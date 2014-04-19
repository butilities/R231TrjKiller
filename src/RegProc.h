#ifndef REGPROC_H_INCLUDED
#define REGPROC_H_INCLUDED
#include <windows.h>

class RegProc
{
    private:
    HINSTANCE hInst;
    typedef long (*sh)(long,const char*);
    sh SHDeleteKey;
    public:
    RegProc::RegProc();
    int RegProc::RemoveItem(const char* key,const char* subkey,const char* item);
    int RegProc::RemoveKey(const char* key,const char* subkey,const char* item);
};
#endif // REGPROC_H_INCLUDED
