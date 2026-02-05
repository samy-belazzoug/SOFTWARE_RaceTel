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

class SHME_static : public SHME_assetto_corsa {
    public:
        struct SPageFileStatic* statics = (struct SPageFileStatic*)pBuf;
        int Connect();
};

class SHME_physics : public SHME_assetto_corsa {
    public:
        struct SPageFilePhysics* physics = (struct SPageFilePhysics*)pBuf;
        int Connect();
};

class SHME_graphics : public SHME_assetto_corsa {
    public: 
        struct SPageFileGraphic* graphics = (struct SPageFileGraphic*)pBuf;
        int Connect();
};


#endif