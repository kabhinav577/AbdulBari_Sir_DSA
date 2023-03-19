#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * Head;

void Create(int A[], int n)
{
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

// Display the Elements in Linked List with Loop
void Display(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != Head);
    printf("\n\n");
}

///// Displaying The ELements in Linked List with Recursion
void RDisplay(struct Node *h)
{
    static int flag = 0;
    if (h != Head || flag == 0)
    {
        flag = 1;
        printf("%d ", h->data);
        RDisplay(h->next);
    }
    flag = 0;
    printf("\n\n");
}

//// Length of circular Linked List

int Length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != Head);
    return len;
}

//// Inserting Elements
void Insert(struct Node *h, int index, int x)
{
    struct Node *t;

    if (index < 0 || index > Length(h))
        return;
    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if (Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            while (h->next != Head)
                h = h->next;
            h->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            h = h->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = h->next;
        h->next = t;
    }
}

//// Deleting The Elements in cricular Linked List
int Delete(struct Node *p, int index)
{
    struct Node *q;
    int i, x;

    if (index < 0 || index > Length(p))
        return -1;
    if (index == 1)
    {
        while (p->next != Head)
            p = p->next;
        x = Head->data;
        if (Head == p)
        {
            free(Head);
            Head = NULL;
        }
        else
        {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main()
{
    int A[] = {5, 6, 3, 4, 9};
    Create(A, 5);

    // Insert(Head, 5, 10);
    printf("\nDeleting Element is %d.\n", Delete(Head, 5));
    Display(Head);
    return 0;
}