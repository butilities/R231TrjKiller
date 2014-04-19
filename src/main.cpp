#include <string.h>
#include <iostream>
#include "Define.h"
#include "FileProc.h"
#include "RegProc.h"
#include "ProcProc.h"
#include <windows.h>
using namespace std;
string windir = getenv("windir");
void RegHand (const char* key, const char* subkey, const char* str[],int len, bool iskey, bool needcat)
{
    RegProc RP;
    int rel;
    for(int i=0;i<len;i++)
    {
        string TmpStr=windir;
        if(needcat)
        TmpStr=TmpStr+str[i];
        else TmpStr=str[i];
        if(iskey)
        rel=RP.RemoveKey(key,subkey,TmpStr.c_str());
        else rel=RP.RemoveItem(key,subkey,TmpStr.c_str());
        if (rel==KeyDeleted)
        cout <<"Registry => " << TmpStr << " Removed!"<< endl;
    }
}

int main()
{
    int input;
    system("Title R231 Trojan Removal");
    cout << "Welcome to using R231 Trojan Removal" << endl;
    cout << "Enter the 231 to start:" << endl;
    cin >> input;
    while(input!=231){
        cout << "Wrong input, please input again." << endl;
        cin >> input;
    }


    const char* ProcStr[]={
        "explorer.exe",
        "iexplore.exe",
        "ctfmon.exe",
        "k9cuos2q.exe",
        "aqoeerw.exe",
        "rttrwq.exe",
        "0eboyg.exe",
        "0o.com",
        "n89f1d1w.exe"
    };
    const char* RegRun[]={
        "coolsos",
        "ertyuop"
    };
    const char* FileStr[]={
        ":\\autorun.inf",
        ":\\k9cuos2q.exe",
        ":\\0eboyg.exe",
        ":\\0o.com"
    };
    const char* FileStrWin[]={
        "\\system32\\aqoeerw.exe",
        "\\system32\\rttrwq.exe",
        "\\system32\\bnmkue0.dll",
        "\\system32\\bnmkue1.dll",
        "\\system32\\bnmkue2.dll",
        "\\system32\\bnmkue3.dll",
        "\\system32\\bnmkue4.dll",
        "\\system32\\bnmkue5.dll",
        "\\system32\\bnmkue6.dll",
        "\\system32\\bnmkue7.dll",
        "\\system32\\bnmkue8.dll",
        "\\system32\\bnmkue9.dll",
        "\\system32\\softqq0.dll",
        "\\system32\\softqq1.dll",
        "\\system32\\softqq2.dll",
        "\\system32\\softqq3.dll",
        "\\system32\\softqq4.dll",
        "\\system32\\softqq5.dll",
        "\\system32\\softqq6.dll",
        "\\system32\\softqq7.dll",
        "\\system32\\softqq8.dll",
        "\\system32\\softqq9.dll"
    };
    ProcProc PP;
    FileProc FP;

    for(int i=0;i<(int)length(ProcStr);i++){
        int rel = PP.RemoveProc(ProcStr[i]);
        if (rel==ProcessDeleted)
        cout << "Process => " << ProcStr[i] << " Killed!" << endl;
    }

    DWORD dwRtn = GetLogicalDrives();
    char c = 'A';
    while ( dwRtn )
    {
        if ( dwRtn & 1  )
        {
            //if (GetDriveType(drive)==DRIVE_FIXED)
            for(int i=0;i<(int)length(FileStr);i++){
                string TmpStr;
                TmpStr=TmpStr+c;
                TmpStr=TmpStr+FileStr[i];
                int rel = FP.RemoveFile(TmpStr.c_str());
                if (rel==FileDeleted)
                cout << "File => " << TmpStr << " Removed!" << endl;
                else if(rel==DeleteOnReboot)
                cout << "File => " << TmpStr << " Remove on reboot!" << endl;
            }
        }
        c++;
        dwRtn >>= 1;
    }

    for(int i=0;i<(int)length(FileStrWin);i++)
    {
        string TmpStr=windir;
        TmpStr=TmpStr+FileStrWin[i];
        int rel = FP.RemoveFile(TmpStr.c_str());
        if (rel==FileDeleted)
        cout << "File => " << TmpStr << " Removed!" << endl;
        else if(rel==DeleteOnReboot)
        cout << "File => " << TmpStr << " Remove on reboot!" << endl;
    }

    RegHand("HKCU","software\\microsoft\\Windows\\CurrentVersion\\Run",RegRun,(int)length(RegRun),false,false);

    cout << endl << "Finished! And reboot your computer."<<endl;
    system("pause");
    return 0;
}
