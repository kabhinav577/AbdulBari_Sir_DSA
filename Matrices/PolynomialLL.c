#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int coeff;
    int expo;
    struct Node *next;
}*poly = NULL;


void Create()
{
    struct Node *t, *last=NULL;
    int num , i;

    printf("Enter Number of terms: ");
    scanf("%d", &num);
    printf("Enter each term with Coeff and expo: \n");

    for(i = 0; i<num ; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &t->coeff, &t->expo);
        t->next = NULL;
        if(poly == NULL)
         poly=last=t;
        else
        {
            last->next = t;
            last = t;
        } 
    }
}


void Display(struct Node *p)
{
    while(p)
    {
        printf("%dx%d + ", p->coeff, p->expo);
        p = p->next;
    }
    printf("\n\n");
}

long Eval(struct Node *p, int x)
{
    long val = 0;

    while(p)
    {
        val+=p->coeff*pow(x,p->expo);
        p = p->next;
    }
    return val;
}
int main()
{
    Create();
    Display(poly);
    printf("%d", Eval(poly, 4));
    
    return 0;
}