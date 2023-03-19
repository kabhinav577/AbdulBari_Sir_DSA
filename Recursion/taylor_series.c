#include <stdio.h>

double e(int x, int n)
{
    static double p = 1, f = 1;
    double r;

    if (n == 0)
    {
        return 1;
    }
    else
    {
        r = e(x, n - 1);
        p = p * x;
        f = f * n;
        return r + p / f;
    }
}

// Taylor series with Hornor's rule -->

double e2(int x, int n)
{
    static double s;
    if (n == 0)
    {
        return s;
    }
    else
    {
        s = 1 + x * s / n;
        return e2(x, n - 1);
    }
}

// Using loop

double e1(int x, int n)
{
    double s = 1, num = 1, den = 1;

    for (int i = 1; i <= n; i++)
    {
        num *= x;
        den *= i;
        s += num / den;
    }
    return s;
}

int main()
{
    printf("%lf \n", e(5, 15));
    printf("%lf \n", e1(5, 15));
    printf("%lf \n", e2(5, 15));
    return 0;
}