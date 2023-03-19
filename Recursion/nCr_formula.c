#include <stdio.h>

int fact(int n)
{
    if(n<=1) return n;
    return fact(n-1)*n;
}

int nCr(int n, int r)
{
    int numerator, denominator;
    numerator = fact(n);
    denominator = fact(r) * fact(n-r);
    return numerator/denominator;
}

int NCR(int n, int r)
{
    if(n==r || r==0) return 1;
    return NCR(n-1, r-1) + NCR(n-1, r);

}

int main()
{
    // printf("%d", fact(4));
    printf("%d ", nCr(5, 2));
    printf("%d ", NCR(5, 2));
    return 0;
}