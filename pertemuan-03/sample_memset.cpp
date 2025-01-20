#include <stdio.h>
#include <string.h>

int main() {
    int arr[10];

    // Isi seluruh elemen array dengan nilai 0
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < 10; i++) {
        printf("arr[%d] = %d\n", i, arr[i]); // Semua elemen bernilai 0
    }

    return 0;
}

