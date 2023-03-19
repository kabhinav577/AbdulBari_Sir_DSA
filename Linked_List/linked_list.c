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

////// Display element using Recursion /////
void RDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

/////// Count all elements in Linked List  with Loop//////
int Count(struct Node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

/////// Count all elements in Linked List  with Recursion //////
int RCount(struct Node *p)
{
    if (p != NULL)
        return RCount(p->next) + 1;
    else
        return 0;
}

/////// Sum of all elements with Loop ////////
int Sum(struct Node *p)
{
    int s = 0;
    while (p != NULL)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

/////// Sum of all elements with Recursion ////////
int RSum(struct Node *p)
{
    if (p != NULL)
        return RSum(p->next) + p->data;
    else
        return 0;
}

/////// Max num in linked list with Loop //////////
int Max(struct Node *p)
{
    int max = -32564;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

/////// Max num in linked list with Recusion //////////
int RMax(struct Node *p)
{
    int max = 0;
    if (p == 0)
        return -32564;
    max = RMax(p->next);
    if (max > p->data)
        return max;
    else
        return p->data;
}

////// Searching Elements in Linked list with Loop ////////
struct Node *LSearch(struct Node *p, int key)
{
    struct Node *q;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

////// Searching Elements in Linked list with Recursion ////////
struct Node *RSearch(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;

    return RSearch(p->next, key);
}

///// This function takes O(1) time at 0 index and O(n) time to any Index because of when put on 0th index p not tracing all indexes. /////
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;

    if (index < 0 || index > Count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

///// This Function always put Element to the LastNode .
void InsertLast(int x)
{
    struct Node *t;
    struct Node *last;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
    {
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

///// Sorted Insert
void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (p == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

///// Delete in Linked List
int Delete(struct Node *p, int index)
{
    struct Node *t, *q = NULL;
    int x = -1, i;

    if (index < 1 || index > Count(p))
        return -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        t = p;
        q->next = p->next;
        x = p->data;
        free(t);
        return x;
    }
}

// IsSorted this linkedList
int isSorted(struct Node *p)
{
    int x = -65536;
    while (p != NULL)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

// Duplicate in Linked List
void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

////// This Reverse function takes more space beacuse of Array two times use
void Reverse1(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;
    A = (int *)malloc(Count(p) * sizeof(int));

    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

//// This Reverse function using Three Pointers r follow q and q follow p and at the end first Point to q //
void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

///// this Reverse function using Recusrion
void Reverse3(struct Node *q, struct Node *p)
{
    if (p)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

//// Concat the LinkedList

void Concat(struct Node *p, struct Node *q)
{
    third = p;
    while (p->next != NULL)
        p = p->next;

    p->next = q;
}

///// Merging Linked list
void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;
    if (q)
        last->next = q;
}

int MiddleNode(struct Node *p)
{
    struct Node *q;
    p=q=first;
    while(q)
    {
        q = q->next;
        if(q) q = q->next;
        if(q) p = p->next;
    }
    return p->data;
}

int main()
{
    struct Node *temp;
    int A[] = {10, 20, 30, 40, 50,60,70,80};
    int B[] = {5, 22, 255, 355, 350};
    Create(A, 8);
    Create2(B, 5);
    // SortedInsert(first, 6);
    // Insert(first, 0 , 10);
    // Insert(first, 3 , 13);

    // temp = LSearch(first, 23);
    // // RDisplay(first);
    // printf("\n%d elements in Linked list.", Count(first));
    // printf("\nSum of all elements %d.", Sum(first));
    // printf("\nMax num is %d.", Max(first));

    // Searching Element
    // if (temp)
    //     printf("\nKey is Found %d.\n", temp->data);
    // else
    //     printf("\nKey Not found\n");
    // printf("\nDeleting Element is %d\n", Delete(first, 1));
    // printf("%d \n", isSorted(first));
    // RemoveDuplicate(first);
    // Reverse1(first);
    // Reverse3(NULL, first);
    // Concat(first, second);
    // Merge(first, second); // Few bugs in code this not merge Perfectly
    printf("Middle Element is %d", MiddleNode(first));
    Display(third);

    return 0;
}