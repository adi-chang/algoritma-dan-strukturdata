#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n = 5;

    // Alokasikan memori untuk array dengan 5 elemen
    arr = (int *)calloc(n, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Semua elemen diinisialisasi ke 0
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]); // Output: arr[0] = 0, arr[1] = 0, ...
    }

    free(arr); // Membebaskan memori
    return 0;
}

