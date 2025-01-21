#include <stdio.h>
#include <string.h>

int main() {
    char data[] = "ABCDEFG";

    // Menyalin dengan overlap (dari index 0 ke index 3)
    memmove(data + 3, data, 4); // Menyalin 4 byte termasuk null terminator

    printf("Hasil: %s\n", data);

    return 0;
}

