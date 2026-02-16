#ifndef PYTEL_RECORDER_H
#define PYTEL_RECORDER_H

#include <stdio.h>
#include "../data_access/Assetto-Corsa/SHME_assetto_corsa.hpp"

struct Circular_Buffer {
    size_t item_size; // Size of one element, it can be a type, a struct etc..
    size_t frequency; // In hz, for Assetto Corsa, it's 150hz
    size_t seconds; // How much seconds you want to stock in the buffer
    size_t read;
    size_t write;
};

#endif