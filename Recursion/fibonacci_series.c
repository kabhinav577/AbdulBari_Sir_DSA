#include <stdio.h>

// Global variables

int f[10];


int fib(int n)
{
    int t0 = 0, t1 = 1, s = 0;
    if (n <= 1)
    {
        return n;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            s = t0 + t1;
            t0 = t1;
            t1 = s;
        }
        return s;
    }
}

// fibonacci using recursion,  timeComp is O(2^n)   

int rFib(int n)
{
    if(n<=1) return n;
    return rFib(n-2) + rFib(n-1);
}

// fibonacci using recusion with memoization beacuse of timeComp is O(n) 

int memoFib(int n)
{
    if(n<=1)
    {
        f[n] = n;
        return n;
    } else 
    {
        if(f[n-2] == -1) f[n-2] = memoFib(n-2);
        if(f[n-1] == -1) f[n-1] = memoFib(n-1);
        f[n] = f[n-2] + f[n-1];
        return f[n-2] + f[n-1];
    }
}

int main()
{
    printf("%d \n", fib(5));
    printf("%d \n", rFib(5));
    for (int i = 0; i <= 10; i++)
    {
        f[i] = -1;
    }
    printf("%d \n", memoFib(5));
    
    return 0;
}