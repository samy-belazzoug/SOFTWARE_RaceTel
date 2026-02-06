#include "recorder.hpp"

int main() {
    FILE* file;
    file = fopen("../shared/data.txt","w");
    char str[] = "Hello, file!\n";
    
    for (int i = 0; i < 2; i++) {
        fprintf(file, str);
    }
    
    fclose(file);

    return 0;
}
