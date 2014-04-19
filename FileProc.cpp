#include <windows.h>
#include "Define.h"
#include "FileProc.h"

    FileProc::FileProc(){}
    int FileProc::RemoveFile(const char* Filename)
    {
        if(GetFileAttributesA(Filename)!=INVALID_FILE_ATTRIBUTES)
        {
            SetFileAttributesA(Filename,FILE_ATTRIBUTE_NORMAL);
            if (DeleteFileA(Filename)!=0)
            return FileDeleted;
            else
            {
                MoveFileEx(Filename,NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
                return DeleteOnReboot;
            }
        }else return FileNotExist;
    }

