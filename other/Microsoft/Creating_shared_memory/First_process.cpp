#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <stdint.h> // int32_t
#include <float.h> // float
#include <iostream>

#define BUF_SIZE 256
TCHAR szName[]=TEXT("Global\\MyFileMappingObject");
TCHAR szMsg[]=TEXT("Message from first process.");

struct s_example {
   int32_t x;
   wchar_t y[33];
};

int _tmain()
{
   HANDLE hMapFile;
   LPCTSTR pBuf;

   hMapFile = CreateFileMapping(
                 INVALID_HANDLE_VALUE,    // use paging file
                 NULL,                    // default security
                 PAGE_READWRITE,          // read/write access
                 0,                       // maximum object size (high-order DWORD)
                 BUF_SIZE,                // maximum object size (low-order DWORD)
                 szName);                 // name of mapping object

   if (hMapFile == NULL)
   {
      _tprintf(TEXT("Could not create file mapping object (%d).\n"),
             GetLastError());
      return 1;
   }
   pBuf = (LPTSTR) MapViewOfFile(hMapFile,   // handle to map object
                        FILE_MAP_ALL_ACCESS, // read/write permission
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

   struct s_example* my_point = (struct s_example*)pBuf;
   my_point->x = 150;
   wcscpy_s(my_point->y, 33, L"Hello, memory");
   
   int i;
   while (1) {
      std::cin >> i;
      if (i == 1) {
         break;
      }
   };
   
   UnmapViewOfFile(pBuf);

   CloseHandle(hMapFile);
   printf("Closed successfully");
   return 0;
}