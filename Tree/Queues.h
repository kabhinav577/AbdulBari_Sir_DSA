// #include <stdio.h>
// #include <stdlib.h>

struct Node 
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queues
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void Create(struct Queues *q, int size)
{
    q->size=size;
    q->front=q->rear= 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queues *q, struct Node *x)
{
    if((q->rear + 1) % q->size == q->front)
       printf("Queues is Full.");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }   
}

struct Node * dequeue(struct Queues *q)
{
    struct Node* x = NULL;
    if(q->front == q->rear)
      printf("Queue is Empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }  
    return x;
}


int isEmpty(struct Queues q)
{
    return q.front == q.rear;
}