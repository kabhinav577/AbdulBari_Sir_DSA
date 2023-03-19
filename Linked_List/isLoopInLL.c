#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void Create(int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void Create2(int A[], int n)
{
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

////// Display element using Loop /////
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}


int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p=q=f;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p!= q);
    
    if(p == q)
     return 1;
    else 
     return 0; 
}

int main()
{
    struct Node *t1 , *t2;
    int A[] = {10, 20, 30, 40, 50};
    Create(A, 5);

    // This is for loop create in linkedList
    // t1 = first->next->next;
    // t2 = first->next->next->next->next;
    // t2->next = t1;   

    printf("%d \n", isLoop(first));


    return 0;
}