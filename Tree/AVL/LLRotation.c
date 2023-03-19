#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
} *root = NULL;

// Calculating Node Height of left and right subTree
int NodeHeight(struct Node *p)
{
    int heightLeft, heightRight;
    heightLeft = p && p->lchild ? p->lchild->height : 0;
    heightRight = p && p->rchild ? p->rchild->height : 0;

    return heightLeft > heightRight ? heightLeft + 1 : heightRight + 1;
}

// Checking Balance Factor
int BalanceFactor(struct Node *p)
{
    int heightLeft, heightRight;
    heightLeft = p && p->lchild ? p->lchild->height : 0;
    heightRight = p && p->rchild ? p->rchild->height : 0;

    return heightLeft - heightRight;
}

// LL Rotation
struct Node * LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height =  NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(p == root)
     root = pl;

    return pl; 
}

// LR Rotation
struct Node * LRRotation(struct Node *p)
{
    return NULL;
}

// RR Rotation
struct Node * RRRotation(struct Node *p)
{
    return NULL;
}

// RL Rotation
struct Node * RLRotation(struct Node *p)
{
    return NULL;
}


// Recursive Insert
struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t = NULL;

    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
        return RLRotation(p);

    return p;
}

int main()
{
    root = RInsert(root, 10);
    RInsert(root, 5);
    RInsert(root, 2);

    return 0;
}