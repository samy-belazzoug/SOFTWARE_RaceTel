#ifndef PYTEL_RECORDER_H
#define PYTEL_RECORDER_H

#include <stdio.h> // cout, endl
#include "../data_access/Assetto-Corsa/SHME_assetto_corsa.hpp" // SHME_Physics, SHME_Graphics, Connect, Disconnect
#include <vector> // vector
#include <ctime> // time

template <typename data_source>

struct Circular_Buffer {
    // Data stock array
    vector<data_source> array;

    // Size of the array
    size_t item_size; // Size of one element, it can be a type, a struct etc..
    size_t frequency; // In hz, for Assetto Corsa, it's 150hz
    size_t seconds; // How much seconds you want to stock in the buffer

    // Read/Write pointers
    data_source* read; // Read pointer
    data_source* write; // Write pointer
};

struct Binary_File {
    char signature;
    time_t date;
    float version;
    int data_source; // 1 : Assetto Corsa
};

class Recorder {
    public:
        Recorder();
};

#endif