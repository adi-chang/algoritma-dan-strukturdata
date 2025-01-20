#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n = 5;

    // Alokasikan memori untuk array dengan 5 elemen
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Inisialisasi array
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // Tampilkan elemen array
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perbesar ukuran array menjadi 10 elemen
    n = 10;
    arr = (int *)realloc(arr, n * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    // Inisialisasi elemen baru
    for (int i = 5; i < n; i++) {
        arr[i] = i + 1;
    }

    // Tampilkan array yang diperbesar
    printf("Resized array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // Membebaskan memori
    return 0;
}

