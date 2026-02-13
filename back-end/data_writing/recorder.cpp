#include "recorder.hpp"

int main() {
    
    SHME_physics p; 
    SHME_graphics g;
    p.Connect(); 
    g.Connect();

    while (g.graphics->status != AC_OFF) { // Assetto Corsa is launched
        if (g.graphics->status == AC_LIVE) { // Player is currently driving
            std::cout << "fuel : " << p.physics->fuel  << " status : " << g.graphics->status << " rpms : " << p.physics->rpms << std::endl ;
        }
    }
    
    // The user leave Assetto Corsa
    p.Disconnect();
    g.Disconnect();
    
    return 0;
}