#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float salary;
} Employee;

int main() {
    Employee *emp;

    // Alokasikan memori untuk 1 objek Employee
    emp = (Employee *)calloc(1, sizeof(Employee));

    if (emp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Semua nilai dalam struktur diinisialisasi ke nol
    printf("ID: %d, Salary: %.2f\n", emp->id, emp->salary); // Output: ID: 0, Salary: 0.00

    free(emp); // Membebaskan memori
    return 0;
}

