// Driver for Assetto Corsa
#include "SHME_assetto_corsa.hpp"
#include "DATA_assetto_corsa.hpp"

int main() {
    SHME_assetto_corsa *a;
    a->Disconnect();
    return 0;
}

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
    return;
};

