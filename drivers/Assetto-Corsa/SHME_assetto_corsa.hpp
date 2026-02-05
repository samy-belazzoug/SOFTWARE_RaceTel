// Access / Link to Assetto Corsa's shared memory

#ifndef SHME_assetto_corsa_H
#define SHME_assetto_corsa_H

//------------------------------------------------------------------------------------------------------------
//------------------------------------------------ INCLUDES   ------------------------------------------------
//------------------------------------------------------------------------------------------------------------

#include "DATA_assetto_corsa.hpp"
#include <windows.h> // OpenFileMapping()
#include <iostream> // cout

//------------------------------------------------------------------------------------------------------------
//------------------------------------------------ CLASSES   ------------------------------------------------
//------------------------------------------------------------------------------------------------------------

class SHME_assetto_corsa {
    protected:
        HANDLE handle;
        LPCTSTR pBuf;
        bool isConnected;
        /* data */
    public:
        SHME_assetto_corsa();
        void Disconnect();
};

class SHME_static : SHME_assetto_corsa {
    public:
        struct SPageFileStatic Connect();
};

class SHME_physics : SHME_assetto_corsa {
    public:
        struct SPageFilePhysics Connect();
};

class SHME_graphics : SHME_assetto_corsa {
    public:
        struct SPageFileGraphics Connect();
};


#endif