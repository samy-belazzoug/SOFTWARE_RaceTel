// Driver for Assetto Corsa
#include "SHME_assetto_corsa.hpp"
#include "DATA_assetto_corsa.hpp"

void SHME_assetto_corsa::Disconnect() {
    // pBuf
    if (pBuf == NULL) {
        std::cout << "No need to unmap pBuf." << std::endl;
    }
    else {
        UnmapViewOfFile(pBuf);
        std::cout << "View unmapped successfully" << std::endl;
    }
    
    // handle
    if (handle == NULL) {
        std::cout << "No need to close handle." << std::endl;
    }
    else {
        CloseHandle(handle);
        std::cout << "Handle closed successfully." << std::endl;
    }
};

/*int main() {
    SHME_static *a;
    struct SPageFileStatic b = a->Connect();
}
*/