#include <stdio.h>
#include <stdlib.h>

struct Queues
{
    int size;
    int front;
    int rear;
    int *Q;
};

void Create(struct Queues *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(size * sizeof(int));
}

void enqueue(struct Queues *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queues is Full.");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queues *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("Queues id Empty");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queues q)
{
    int i = q.front + 1;
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);

    printf("\n\n");
}

int main()
{
    struct Queues q;
    printf("\n");
    Create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    // enqueue(&q, 50);

    // printf("%d \n", dequeue(&q));

    Display(q);
    return 0;
}