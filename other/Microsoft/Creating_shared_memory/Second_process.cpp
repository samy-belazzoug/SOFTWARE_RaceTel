#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <stdint.h> // int32_t
#include <float.h> // float

#pragma comment(lib, "user32.lib")

#define BUF_SIZE 256
TCHAR szName[]=TEXT("Global\\MyFileMappingObject");

struct s_example {
   int32_t x;
   wchar_t y[33];
};


int _tmain()
{
   HANDLE hMapFile;
   LPCTSTR pBuf;

   hMapFile = OpenFileMapping(
                   FILE_MAP_ALL_ACCESS,   // read/write access
                   FALSE,                 // do not inherit the name
                   szName);               // name of mapping object

   if (hMapFile == NULL)
   {
      _tprintf(TEXT("Could not open file mapping object (%d).\n"),
             GetLastError());
      return 1;
   }

   pBuf = (LPTSTR) MapViewOfFile(hMapFile, // handle to map object
               FILE_MAP_ALL_ACCESS,  // read/write permission
               0,
               0,
               BUF_SIZE);

  if (pBuf == NULL)
   {
      _tprintf(TEXT("Could not map view of file (%d).\n"),
             GetLastError());

      CloseHandle(hMapFile);

      return 1;
   }

   //MessageBox(NULL, pBuf, TEXT("Process2"), MB_OK);
   struct s_example* mon_pointeur = (struct s_example*)pBuf;
   printf("%d\n", mon_pointeur->x);
   wprintf(L"%s\n", mon_pointeur->y);

   UnmapViewOfFile(pBuf);

   CloseHandle(hMapFile);

   return 0;
}