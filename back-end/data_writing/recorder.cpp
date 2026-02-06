#include "recorder.hpp"

int main() {
    SHME_physics p;
    SHME_graphics g;
    p.Connect();
    g.Connect();
    while (g.graphics->status != AC_OFF) { //W
        if (g.graphics->status == AC_LIVE) {
            std::cout << p.physics->fuel << "  " << g.graphics->status << std::endl;
        }
    }
    // The user leave Assetto Corsa
    
    p.Disconnect();
    g.Disconnect();
    
    
    return 0;
}