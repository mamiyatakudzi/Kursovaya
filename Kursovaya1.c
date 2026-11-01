#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double fa(double x);
double fb(double x);

int main(void)
{
    setlocale(LC_ALL, ".UTF-8");

    printf("--- Задание 1 ---\n\n");

    double x_val;
    int menu1;

    printf("Введите значение x: ");
    scanf("%lf", &x_val);

    printf("Выберите действие:\n");
    printf("1 - Расчет Y(x)\n");
    printf("2 - Расчет V(x)\n");
    printf("3 - Произведение, разность квадратов и удвоенная сумма функций\n");
    printf("Ваш выбор: ");
    scanf("%d", &menu1);

    double res_a, res_b;

    switch (menu1)
    {
    case 1:
        printf("Y(x) = %lf\n", fa(x_val));
        break;

    case 2:
        printf("V(x) = %lf\n", fb(x_val));
        break;

    case 3:
        res_a = fa(x_val);
        res_b = fb(x_val);
        printf("Y(x) = %lf, V(x) = %lf\n", res_a, res_b);
        printf("Произведение: %lf\n", res_a * res_b);
        printf("Разность квадратов: %lf\n", (res_a * res_a) - (res_b * res_b));
        printf("Удвоенная сумма: %lf\n", 2.0 * (res_a + res_b));
        break;

    default:
        printf("Неверный выбор пункта меню.\n");
        break;
    }
    printf("\n");

    system("pause");
    return 0;
}

double fa(double x)
{
    double y;
    y = (3.0 + exp(x - 1.0)) / (1.0 + x * x * fabs(3.1415926535 - tan(1.0 / x)));
    return y;
}

double fb(double x)
{
    double v1 = (sin(3.0 * x) + x * x) / cbrt(1.0 + x * x);
    double v2 = sqrt(x * x + 4.0);
    double v3 = fabs(x - exp(-4.0));

    int c1 = (x <= -4.0);
    int c2 = (x > -4.0 && x <= 3.0);
    int c3 = (x > 3.0);

    return (v1 * c1) + (v2 * c2) + (v3 * c3);
}