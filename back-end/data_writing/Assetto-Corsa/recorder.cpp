#include "recorder.hpp"

int main() {

    SHME_static s;
    SHME_physics p; 
    SHME_graphics g;
    s.Connect();
    p.Connect(); 
    g.Connect(); 
    
    std::cout << *s.statics->acVersion << std::endl;
    std::cout << sizeof(SPageFilePhysics) * 150 * 5 << std::endl;


    AC_P_Circular_Buffer b;
    std::cout << sizeof(b.buffer) << std::endl;

    usleep(1000000);
    
    std::cout << "Starting recording" << std::endl;

    size_t i = 0;
    clock_t begin = clock();
    while (g.graphics->status != AC_OFF) { // Assetto Corsa is launched
        if (g.graphics->status == AC_LIVE) { // Player is currently driving
            
            if (i >= 1664) {
                break;
            }
            
            else {    
                b.buffer[i] = *p.physics;
                usleep(3003);
                i++;
            }
        }
    }

    clock_t end = clock();

    unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    std::cout << "Recording made in : " << millis << std::endl;

    std::cout << b.buffer[0].rpms << std::endl;
    std::cout << b.buffer[333].rpms << std::endl;
    std::cout << b.buffer[667].rpms << std::endl;
    std::cout << b.buffer[1331].rpms << std::endl;
    std::cout << b.buffer[1663].rpms << std::endl;

    
    // The user leave Assetto Corsa
    s.Disconnect();
    p.Disconnect();
    g.Disconnect();
    
    return 0;

}