// #endif /*Queue_h*/
#include <stdio.h>
#include "Queue.h"

void BFS(int G[][7], int start, int n) 
{
    int i = start;
    int visited[7] = {0};

    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);

    while(!isEmpty()) {
        i = dequeue();
        for(int j = 1; j < n; j++) {
            if(G[i][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

int main()
{
    int G[7][7] = {{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0}};
    BFS(G, 4, 7);
    return 0;
}