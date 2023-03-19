#include <stdio.h>

void LowerCase(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
       s[i] += 32;
    }
    printf("%s \n", s);
}

void UpperCase ( char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] -= 32;
    }
   printf("%s \n", s); 
}

void ToggleCase ( char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if( s[i] >= 65 && s[i] <= 90)
        {
           s[i] += 32;
        }
        else if (s[i] >= 97 && s[i] <= 122)
        {
            s[i] -= 32;
        }
    }
    printf("%s \n", s);
    
}

int main()
{
    char name[] = "aBhiNav";
    // LowerCase(name);
    // UpperCase(name);
    // ToggleCase(name);
    return 0;
}