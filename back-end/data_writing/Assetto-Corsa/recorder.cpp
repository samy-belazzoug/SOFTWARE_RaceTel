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
    
    int32_t packet_buffer_start = p.physics->packetId; // Note, on se connecte avant!
    int32_t i = 0;
    int32_t gap;
    clock_t begin = clock();
    while (g.graphics->status != AC_OFF) { // Assetto Corsa is launched
        if (g.graphics->status == AC_LIVE) { // Player is currently driving

            gap = p.physics->packetId - packet_buffer_start;
            
            if (gap >= 1665) { // 5 secondes de données
                break;
            }

            else {    
                std::cout << "Gap : " << gap << " i : " << i << " PacketID current step : " << p.physics->packetId << " RPMS : " << p.physics->rpms << std::endl;
                b.buffer[i] = *p.physics;
                //packet_buffer_start = p.physics->packetId - 1; // Note que le gap est TOUJOURS de 1.
                i = gap; 
            }
        }
    }

    clock_t end = clock();

    unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    std::cout << "Recording made in : " << millis << std::endl;
    std::cout << "rpms : " << b.buffer[1657].rpms << " packetId : " << b.buffer[1657].packetId << std::endl;
    std::cout << "rpms : " << b.buffer[1658].rpms << " packetId : " << b.buffer[1658].packetId << std::endl;
    std::cout << "rpms : " << b.buffer[1659].rpms << " packetId : " << b.buffer[1659].packetId << std::endl;
    std::cout << "rpms : " << b.buffer[1660].rpms << " packetId : " << b.buffer[1660].packetId << std::endl;
    std::cout << "rpms : " << b.buffer[1661].rpms << " packetId : " << b.buffer[1661].packetId << std::endl;
    std::cout << "rpms : " << b.buffer[1662].rpms << " packetId : " << b.buffer[1662].packetId << std::endl;
    std::cout << "rpms : " << b.buffer[1663].rpms << " packetId : " << b.buffer[1663].packetId << std::endl;
    std::cout << "rpms : " << b.buffer[1664].rpms << " packetId : " << b.buffer[1664].packetId << std::endl;
    
    // The user leave Assetto Corsa
    s.Disconnect();
    p.Disconnect();
    g.Disconnect();
    
    return 0;

}