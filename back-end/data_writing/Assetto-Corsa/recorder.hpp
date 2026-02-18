#ifndef PYTEL_RECORDER_H
#define PYTEL_RECORDER_H

#include <iostream> // cout, endl
#include <time.h> // clock
#include <unistd.h> //usleep
#include "../../data_access/Assetto-Corsa/SHME_assetto_corsa.hpp" // SHME_Physics, SHME_Graphics, Connect, Disconnect

/*

AC_P = Assetto Corsa physics (shared memory file)
AC_G = Assetto Corsa graphics (shared memory file)

*/

//Sizes are frequency * (how much seconds we want to stock)
const size_t AC_P_Buf_Size = 333 * 5; // According to developper Stefano Casillo, the physics engine runs at ~333Hz
const size_t AC_G_Buf_Size = (sizeof(SPageFileGraphic)) * 5; // Need to calculate frequency for more accurate data.

struct AC_P_Circular_Buffer {
    // Data stock array
    SPageFilePhysics buffer[AC_P_Buf_Size];
    // Read/Write pointers
    SPageFilePhysics* read; // Read pointer
    SPageFilePhysics* write; // Write pointer
};

#endif