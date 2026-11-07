#include <stdio.h>
#include <math.h>

int main() {
    double x, z1, z2;
    double numerator, denominator;

    printf("Enter x: ");
    scanf("%lf", &x);

    // Перевірка області допустимих значень
    if (x <= -3 || x > 3) {
        if (x == 3) {
            printf("Error: x cannot be equal to 3.\n");
            return 1;
        }
    } else {
        printf("Error: x must be <= -3 or > 3.\n");
        return 1;
    }

    // Обчислення z1
    numerator = x * x + 2 * x - 3 + (x + 1) * sqrt(x * x - 9);
    denominator = x * x - 2 * x - 3 + (x - 1) * sqrt(x * x - 9);

    if (fabs(denominator) < 1e-12) {
        printf("Error: division by zero.\n");
        return 1;
    }

    z1 = numerator / denominator;

    // Обчислення z2
    z2 = sqrt((x + 3) / (x - 3));

    // Виведення результатів
    printf("z1 = %.6lf\n", z1);
    printf("z2 = %.6lf\n", z2);

    return 0;
}