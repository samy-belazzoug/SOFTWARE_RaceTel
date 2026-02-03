//DRiver for Assetto Corsa
#include "SHassetto_corsa.hpp"

Mapping_AC::Mapping_AC() {
    // Map and view to Assetto Corsa shared memory  
    HANDLE sh_acpmf_static_mapping;
    LPVOID sh_acpmf_static_view;
    // We open assetto corsa's shared memory with read permissions
    sh_acpmf_static_mapping = OpenFileMappingW(
        FILE_READ_ONLY,
        FALSE,
        sh_static
    ); 

    if (sh_acpmf_static_mapping == NULL) {
        std::cout << "Error while opening shared memory : " << GetLastError() << std::endl;
    }
    else {
        // We view the file sh_acpmf_static_mapping
        sh_acpmf_static_view = MapViewOfFile(
            sh_acpmf_static_mapping,
            FILE_READ_ONLY,
            0,
            0,
            0
        );
        if (sh_acpmf_static_view == NULL) {
            std::cout << "Error while viewing shared memory : " << GetLastError() << std::endl;
        }
        else {
           struct SPageFileStatic *static_data = (struct SPageFileStatic *)sh_acpmf_static_view;
            std::cout << "Track : " << static_data->track << std::endl;
            std::cout << "Track Configuration : " << static_data->trackConfiguration << std::endl;
            std::cout << "Car : " << static_data->carModel << std::endl;
            std::cout << "Cars on session : " << static_data->numCars << std::endl;
        }
    }
};

Mapping_AC::~Mapping_AC() {
    // Close handle and mapping 
    UnmapViewOfFile(sh_acpmf_static_view);
    CloseHandle(sh_acpmf_static_mapping);
     std::cout << "Map file connexion closed successfully" << std::endl;
}