#include <time.h>
#include <iostream>
#include <unistd.h>

int main() {
    size_t i = 0;
    clock_t begin = clock();
    
    while (i < 1665) {
        usleep(3003);
        i++;
    }
    
    usleep(3003);
    clock_t end = clock();
    unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    std::cout << "Recording made in : " << millis << std::endl;

    return 0;

}