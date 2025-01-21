#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello, World!";
    char dest[20];

    // Menyalin isi src ke dest
    memcpy(dest, src, strlen(src) + 1); // +1 untuk menyertakan null terminator

    printf("Sumber: %s\n", src);
    printf("Tujuan: %s\n", dest);

    return 0;
}

