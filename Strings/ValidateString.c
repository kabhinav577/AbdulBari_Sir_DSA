#include <stdio.h>

int Validate(char A[])
{
   for (int i = 0;A[i] != '\0'; i++)
   {
      if( !(A[i] >= 65 && A[i] <= 90) && !(A[i] >= 97 && A[i] <= 122) && !(A[i] >= 48 && A[i] <= 57))
      {
        return 0;
      }
   }
   return 1;
}

int main()
{
    char A[] = "Abhinav123";
    if (Validate(A))
       printf("Valid string");
    else
       printf("Not Valid String");   
    
    return 0;
}