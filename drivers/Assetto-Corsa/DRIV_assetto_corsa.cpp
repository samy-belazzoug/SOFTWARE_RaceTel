// Driver for Assetto Corsa
#include "SHME_assetto_corsa.hpp"
#include "DATA_assetto_corsa.hpp"

int main() {
    //SHME_assetto_corsa *a;
    //a->Disconnect();
    
    SHME_static b;
    
    b.Connect();
    std::wcout << b.statics->acVersion << std::endl;
    std::wcout << b.statics->track << std::endl;
    std::wcout << b.statics->carModel << std::endl;
    std::cout << b.statics->maxRPM << std::endl;
    std::cout << b.statics->maxFuel << std::endl;
    b.Disconnect();
    
    //SHME_physics *c;
    //c->Disconnect();

    //SHME_graphics *d;
    //d->Disconnect();

    return 0;
}

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

   //MessageBox(NULL, pBuf, TEXT("Process2"), MB_OK);
   statics = (struct SPageFileStatic*)pBuf;
   //printf("%d\n", mon_pointeur->x);
   //wprintf(L"%s\n", mon_pointeur->y);

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

   //MessageBox(NULL, pBuf, TEXT("Process2"), MB_OK);
   physics = (struct SPageFilePhysics*)pBuf;
   //printf("%d\n", mon_pointeur->x);
   //wprintf(L"%s\n", mon_pointeur->y);

   isConnected = true;
   return 0;
}


//------------------------------------------------------------------------------------------------------------
//------------------------------------------------ GRAPHICS ------------------------------------------------
//------------------------------------------------------------------------------------------------------------


