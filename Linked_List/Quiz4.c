#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first;

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

void Rearrange(struct Node *list)
{
    struct Node *p, *q;
    int temp;
    if(!list || !list->next)
      return;
    p = list;
    q = list->next;

    while(q)
    {
        temp = p->data;
        p->data = q->data;
        q->data = temp;
        p = q->next;
        q = q ? p->next : 0;
    }  
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main()
{
    int A[] ={1,2,3,4,5,6,7};
    Create(A,7);
    Rearrange(first);
    Display(first);
    return 0;
}