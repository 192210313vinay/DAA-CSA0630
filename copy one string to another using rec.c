#include <stdio.h>


void copyStringRecursively(char *source, char *destination);

int main() {
    char source[] = "Hello, World!";
    char destination[20]; 

    copyStringRecursively(source, destination);

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}


void copyStringRecursively(char *source, char *destination) {
    *destination = *source;
    if (*source == '\0') {
        return;
    } else {
        copyStringRecursively(source + 1, destination + 1);
    }
}

