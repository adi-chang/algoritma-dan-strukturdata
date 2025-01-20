#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
} Person;

int main() {
    Person *p;

    // Alokasikan memori untuk satu objek Person
    p = (Person *)malloc(sizeof(Person));

    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Inisialisasi data
    p->id = 1;
    snprintf(p->name, sizeof(p->name), "John Doe");

    // Cetak data
    printf("ID: %d, Name: %s\n", p->id, p->name);

    free(p); // Membebaskan memori
    return 0;
}

