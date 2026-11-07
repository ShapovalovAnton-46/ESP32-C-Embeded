#include <stdio.h>

int main() {
    char str[500];
    int i, j = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Видалення символів на непарних позиціях
    for (i = 0; str[i] != '\0'; i++) {
        if (i % 2 != 0) {
            str[j] = str[i];
            j++;
        }
    }

    str[j] = '\0';

    printf("Result: %s\n", str);

    return 0;
}