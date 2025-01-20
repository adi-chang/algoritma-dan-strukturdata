#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n = 10;

    // Alokasikan memori untuk array dengan 10 elemen
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Inisialisasi array
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // Tampilkan array sebelum mengecilkan
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Kecilkan ukuran array menjadi 5 elemen
    n = 5;
    arr = (int *)realloc(arr, n * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    // Tampilkan array yang diperkecil
    printf("Resized array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // Membebaskan memori
    return 0;
}

