#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    int row;
    int col;
    struct Node *next;
};

void Create(struct Node **first, int k, int m, int n)
{
    struct Node *temp, *r;
    temp = *first;

    if (temp == NULL)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->val = k;
        temp->row = m;
        temp->col = n;
        temp->next = NULL;
        *first = temp;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        r = (struct Node *)malloc(sizeof(struct Node));
        r->val = k;
        r->row = m;
        r->col = n;
        r->next = NULL;
        temp->next = r;
    }
}

void Display(struct Node *first)
{
    struct Node *temp, *r, *s;
    temp = r = s = first;

    printf("Row: ");
    while (temp != NULL)
    {
        printf("%d ", temp->row);
        temp = temp->next;
    }
    printf("\n");

    printf("Col: ");
    while (r != NULL)
    {
        printf("%d ", r->col);
        r = r->next;
    }
    printf("\n");

    printf("Val: ");
    while (s != NULL)
    {
        printf("%d ", s->val);
        s = s->next;
    }
    printf("\n");
}

int main()
{
    int sparseMatrix[5][5] = {{0, 0, 0, 8, 0}, {0, 0, 6, 0, 4}, {0, 4, 0, 0, 0}, {0, 0, 0, 0, 9}, {3, 0, 0, 0, 0}};
    struct Node *first = NULL;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMatrix[i][j] != 0)
                Create(&first, sparseMatrix[i][j], i, j);

    Display(first);
    return 0;
}