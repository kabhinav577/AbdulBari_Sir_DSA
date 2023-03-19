#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL;


/// Create Doubly Linkedlist
void Create(int A[], int n)
{
   struct Node *t, *last;
   first = (struct Node *)malloc(sizeof(struct Node));
   first->data = A[0];
   first->prev = first->next = NULL;
   last = first;

   for (int i = 1; i < n; i++)
   {
     t = (struct Node *)malloc(sizeof(struct Node));
     t->data = A[i];
     t->next = last->next;
     t->prev = last;
     last->next = t;
     last = t;
   } 
}

// Display Doubly Linkedlist
void Display(struct Node *p)
{
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/// Length of Doubly LinkedList
int Length(struct Node *p)
{
    int len = 0;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

// Insert Elements 
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;

    if(index < 0 || index > Length(p))
      return;
    if(index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
          p = p->next;

        t= (struct Node *)malloc(sizeof(struct Node));
        t->data = x;

        t->prev = p;
        t->next = p->next;  
        if(p->next)
         p->next->prev = t;

        p->next = t; 
    }  
}

// Deleting Elements 
int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x = -1;

    if (index < 1 || index > Length(p))
        return x;
    if(index == 1)
    {
        first = first->next;
        if(first) first->prev =NULL;
        x =p->data;
        free(p);
    }
    else
    {
        for (int i = 0; i < index -1; i++)
            p = p->next;
        p->prev->next = p->next;
        if(p->next)
         p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    return x;
}

/// Reverse the doubly Linkedlist  
void Reverse(struct Node *p)
{
   struct Node *temp;

   while(p != NULL)
   {
       temp = p->next;
       p->next = p->prev;
       p->prev = temp;
       p = p->prev;
       if(p != NULL && p->next == NULL)
         first = p;
   }
}


/// Reverse Doubly linked list with Recursion

struct Node * RReverse(struct Node *p)
{
    if(!p)
     return NULL;
    
    struct Node *temp;
     temp = p->next;
     p->next = p->prev;
     p->prev = temp;

    if(!p->prev)
     return p ;

    return RReverse(p->prev); 
}

int main()
{
    
    int A[] = {10,20,30,40,50};
    Create(A,5);
    // Insert(first, 3, 5);

    printf("\n");
    // printf("\nLength is %d.\n", Length(first));
    // printf("\nDeleted element is %d\n", Delete(first,3));

    // first = RReverse(first);
    Display(first);

    printf("\n");
    return 0;
}