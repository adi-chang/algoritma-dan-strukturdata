#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;

    // Alokasikan memori untuk satu integer
    ptr = (int *)malloc(sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    *ptr = 42; // Menyimpan nilai pada memori yang dialokasikan
    printf("Value: %d\n", *ptr);

    free(ptr); // Membebaskan memori
    return 0;
}

