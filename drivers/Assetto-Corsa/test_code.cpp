#include "SHME_assetto_corsa.hpp"

int main() {
    
    SHME_static a;
    
    a.Connect(); // You must use this function to connect to Assetto Corsa's shared memory, you cant access data if not.
    std::wcout << a.statics->acVersion << std::endl;
    std::wcout << a.statics->track << std::endl;
    std::wcout << a.statics->carModel << std::endl;
    std::cout << a.statics->maxRPM << std::endl;
    std::cout << a.statics->maxFuel << std::endl; 

    SHME_physics b;

    b.Connect();
    std::cout << b.physics->brakeBias << std::endl;
    std::cout << b.physics->fuel << std::endl;


    SHME_graphics c;
    
    c.Connect();
    std::wcout << c.graphics->bestTime << std::endl;
    
    a.Disconnect();
    b.Disconnect();
    c.Disconnect();
    
    return 0;
}