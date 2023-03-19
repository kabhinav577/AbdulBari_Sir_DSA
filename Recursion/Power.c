#include <stdio.h>

int power(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return power(m, n - 1) * m;
}

// This function is more Efficient because less space created
int power1(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return power1(m * m, n / 2);
    }
    return m * power1(m * m, (n - 1) / 2);
}

int main()
{
    int a = power(5, 3);
    int b = power1(2, 4);
    printf("%d\n", a);
    printf("%d", b);
    return 0;
}