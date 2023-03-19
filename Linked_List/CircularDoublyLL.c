#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*Head;

void Create(int A[], int n)
{
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head->prev = Head;
    last = Head;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = Head;
        t->prev = last;
        last->next = t;
        last = t;
        Head->prev = last;
    }
}

void Display(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != Head);
    printf("\n\n");
}

void Reverse(struct Node *p)
{
   struct Node *temp;
   
   do
   {
       temp = p->next;
       p->next = p->prev;
       p->prev = temp;
       p = p->prev;
   } while(p != Head );
   Head = p->next;
}

int main()
{
    int A[] = {1,2,3,4,5};
    Create(A, 5);

 Reverse(Head);
    Display(Head);
    
    return 0;
}