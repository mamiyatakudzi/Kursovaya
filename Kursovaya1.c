#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double Y(double x);
double V(double x);

int main(void)
{
    setlocale(LC_ALL, ".UTF-8");

    int choice;
    double x_start, x_end, step;

    printf("=== Вариант 27. Селиванов Эрик Микаелевич ===\n\n");

    printf("Выберите функцию (1 - Y(x), 2 - V(x)): ");
    scanf("%d", &choice);

    printf("Введите X_start, X_end и шаг: ");
    scanf("%lf %lf %lf", &x_start, &x_end, &step);

    printf("\n-------------------------\n");
    printf("|    X     |   Результат |\n");
    printf("-------------------------\n");

    for (double x = x_start; x <= x_end + (step * 0.01); x += step)
    {
        double res = (choice == 1) ? Y(x) : V(x);

        int is_err = (choice == 1 && fabs(x) <= 1e-9) || isnan(res);

        switch (is_err)
        {
        case 1:
            printf("| %8.3lf |    Ошибка ОДЗ |\n", x);
            break;
        default:
            printf("| %8.3lf | %11.4lf |\n", x, res);
            break;
        }
    }
    printf("-------------------------\n\n");

    system("pause");
    return 0;
}

double Y(double x)
{
    return (3.0 + exp(x - 1.0)) / (1.0 + x * x * fabs(3.141592653589793 - tan(1.0 / x)));
}

double V(double x)
{
    double cond1 = (x <= -4.0) * ((sin(3.0 * x) + x * x) / pow(1.0 + x * x, 1.0 / 3.0));
    double cond2 = (x > -4.0 && x <= 3.0) * sqrt(x * x + 4.0);
    double cond3 = (x > 3.0) * fabs(x - exp(-4.0));

    return cond1 + cond2 + cond3;
}
