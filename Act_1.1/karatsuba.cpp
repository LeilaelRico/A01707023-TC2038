#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int length(long x, long y)
{
    int temp, count = 0;
    if (x > y)
        temp = x;
    else
        temp = y;
    while ((temp / 10) != 0)
    {
        count += 1;
        temp = temp / 10;
    }
    count += 1;
    return count;
}

int getHigh(long x, int m)
{
    int temp;
    temp = x / pow(10, m);
    return temp;
}

int getLow(long x, int m)
{
    int temp;
    temp = x - getHigh(x, m) * pow(10, m);
    return temp;
}

long Karatsuba(long x, long y)
{
    long x0, x1, y0, y1, result;
    int n;
    long k1, k2, k3;

    long r1, r2, r3;

    if (x <= 10 && y <= 10)
        return x * y;

    n = length(x, y);
    n = n / 2;
    x0 = getHigh(x, n);
    x1 = getLow(x, n);
    y0 = getHigh(y, n);
    y1 = getLow(y, n);

    printf("\n------- Línea divisoria ------- \n \n");
    printf("x0 después de dividir =% ld \n", x0);
    printf("x1 después de dividir =% ld \n", x1);
    printf("y0 después de dividir =% ld \n", y0);
    printf("y1 después de dividir =% ld \n", y1);

    printf("x0+x1 = %ld\n", (x0 + x1));
    printf("y0+y1 = %ld\n", (y0 + y1));

    printf("\n------- ------- ------- ------- \n");

    k1 = Karatsuba(x0, y0);
    printf("k1 en este momento =% ld \n", k1);

    k2 = Karatsuba(x1, y1);
    printf("k2 en este momento =% ld \n", k2);

    k3 = Karatsuba((x0 + x1), (y0 + y1));
    printf("k3 en este momento =% ld \n", k3);
    printf("\n \n------- ------- ------- ------- \n \n");

    r1 = k1 * pow(10, 2 * n);
    r2 = k2;
    r3 = (k3 - k1 - k2) * pow(10, n);
    printf("r1 en este momento =% ld \n", r1);
    printf("r2 en este momento =% ld \n", r2);
    printf("r3 en este momento =% ld \n", r3);
    printf("\n \n------- ------- ------- ------- \n \n");

    result = k1 * pow(10, 2 * n) + k2 + (k3 - k1 - k2) * pow(10, n);

    return result;
}

int main()
{
    long num1 = 146123;
    long num2 = 352120;
    printf("Num1=%ld\nNum2=%ld\n\n", num1, num2);
    long result = Karatsuba(num1, num2);
    printf("Resultado = %ld\n\n", result);
    return 0;
}