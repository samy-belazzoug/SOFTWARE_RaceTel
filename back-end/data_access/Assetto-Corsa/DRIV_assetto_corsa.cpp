// Driver for Assetto Corsa
#include "SHME_assetto_corsa.hpp"
#include "DATA_assetto_corsa.hpp"


//------------------------------------------------------------------------------------------------------------
//------------------------------------------------ GENERAL ------------------------------------------------
//------------------------------------------------------------------------------------------------------------


SHME_assetto_corsa::SHME_assetto_corsa() {
    pBuf = NULL;
    handle = NULL;
    isConnected = false;
}

void SHME_assetto_corsa::Disconnect() {
    // pBuf
    if (isConnected == false) {
        std::cout << "You should connect to map via Connect()." << std::endl;
        return;
    }
    if (pBuf == NULL) {
        std::cout << "No need to unmap pBuf." << std::endl;
        return;
    }
    else {
        UnmapViewOfFile(pBuf);
        std::cout << "View unmapped successfully" << std::endl;
        return;
    }
    
    // handle
    if (handle == NULL) {
        std::cout << "No need to close handle." << std::endl;
    }
    else {
        CloseHandle(handle);
        std::cout << "Handle closed successfully." << std::endl;
    }
    isConnected = false;
    return;
};


//------------------------------------------------------------------------------------------------------------
//------------------------------------------------ STATIC ------------------------------------------------
//------------------------------------------------------------------------------------------------------------


int SHME_static::Connect() {
    TCHAR shmefi_static[] = TEXT("Local\\acpmf_static"); // SHared MEmory FIle STATIC
    handle = OpenFileMapping(
                   FILE_MAP_ALL_ACCESS,   // read/write access
                   FALSE,                 // do not inherit the name
                   shmefi_static);               // name of mapping object

   if (handle== NULL) {
        std::cout << "Couldn't open file mapping : " << GetLastError() << std::endl;

        return 1;
   }


   pBuf = (LPTSTR) MapViewOfFile(handle, // handle to map object
               FILE_MAP_ALL_ACCESS,  // read/write permission
               0,
               0,
               0);

  if (pBuf == NULL) {
        std::cout << "Couldn't map view static file : " << GetLastError() << std::endl;
        CloseHandle(handle);
        return 1;
   }

   statics = (struct SPageFileStatic*)pBuf;

   isConnected = true;
   return 0;
}


//------------------------------------------------------------------------------------------------------------
//------------------------------------------------ PHYSICS ------------------------------------------------
//------------------------------------------------------------------------------------------------------------


int SHME_physics::Connect() {
    TCHAR shmefi_physics[] = TEXT("Local\\acpmf_physics"); // SHared MEmory FIle STATIC
    handle = OpenFileMapping(
                   FILE_MAP_ALL_ACCESS,   // read/write access
                   FALSE,                 // do not inherit the name
                   shmefi_physics);               // name of mapping object

   if (handle== NULL) {
        std::cout << "Couldn't open file mapping : " << GetLastError() << std::endl;

        return 1;
   }

   pBuf = (LPTSTR) MapViewOfFile(handle, // handle to map object
               FILE_MAP_ALL_ACCESS,  // read/write permission
               0,
               0,
               0);

  if (pBuf == NULL) {
        std::cout << "Couldn't map view static file : " << GetLastError() << std::endl;
        CloseHandle(handle);
        return 1;
   }

   physics = (struct SPageFilePhysics*)pBuf;

   isConnected = true;
   return 0;
}


//------------------------------------------------------------------------------------------------------------
//------------------------------------------------ GRAPHICS ------------------------------------------------
//------------------------------------------------------------------------------------------------------------


int SHME_graphics::Connect() {
    TCHAR shmefi_graphics[] = TEXT("Local\\acpmf_graphics"); // SHared MEmory FIle STATIC
    handle = OpenFileMapping(
                   FILE_MAP_ALL_ACCESS,   // read/write access
                   FALSE,                 // do not inherit the name
                   shmefi_graphics);               // name of mapping object

   if (handle== NULL) {
        std::cout << "Couldn't open file mapping : " << GetLastError() << std::endl;

        return 1;
   }

   pBuf = (LPTSTR) MapViewOfFile(handle, // handle to map object
               FILE_MAP_ALL_ACCESS,  // read/write permission
               0,
               0,
               0);

  if (pBuf == NULL) {
        std::cout << "Couldn't map view static file : " << GetLastError() << std::endl;
        CloseHandle(handle);
        return 1;
   }

   graphics = (struct SPageFileGraphic*)pBuf;

   isConnected = true;
   return 0;
}