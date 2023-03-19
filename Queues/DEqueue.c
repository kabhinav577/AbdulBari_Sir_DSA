// Deque Data Structures
#include <stdio.h>

#define MAX 10

int Count(int *arr)
{
    int c = 0, i;
    for (i = 0; i <MAX; i++)
    {
        if(arr[i] != 0)
          c++;
    }
    return c;
}

void addFront(int *arr, int item, int *pFront, int *pRear)
{
    int i, k, c;

    if (*pFront == 0 && *pRear == MAX - 1)
    {
        printf("\nDeque is Full.\n");
        return;
    }

    if (*pFront == -1)
    {
        *pFront = *pRear = 0;
        arr[*pFront] = item;
        return;
    }

    if (*pRear != MAX - 1)
    {
        c = Count(arr);
        k = *pRear + 1;
        for (i = 1; i <= c; i++)
        {
            arr[k] = arr[k - 1];
            k--;
        }
        arr[k] = item;
        *pFront = k;
        (*pRear)++;
    }
    else
    {
        (*pFront)--;
        arr[*pFront] = item;
    }
}

void addRear(int *arr, int item, int *pFront, int *pRear)
{
    int i, k;

    if (*pFront == 0 && *pRear == MAX - 1)
    {
        printf("\nDeque is Full.\n");
        return;
    }
    if (*pFront == -1)
    {
        *pRear = *pFront = 0;
        arr[*pRear] = item;
        return;
    }
    if (*pRear == MAX - 1)
    {
        k = *pFront - 1;
        for (i = *pFront - 1; i < *pRear; i++)
        {
            k = i;
            if (k == MAX - 1)
                arr[k] = 0;
            else
                arr[k] = arr[i + 1];
        }
        (*pRear)--;
        (*pFront)--;
    }
    (*pRear)++;
    arr[*pRear] = item;
}

int delFront(int *arr, int *pFront, int *pRear)
{
    int item;

    if (*pFront == -1)
    {
        printf("\nDeque is Empty.\n");
        return 0;
    }

    item = arr[*pFront];
    arr[*pFront] = 0;

    if (*pFront == *pRear)
        *pFront = *pRear = -1;
    else
        (*pFront)++;

    return item;
}


int delRear(int *arr, int *pFront, int *pRear)
{
    int item;

    if (*pFront == -1)
    {
        printf("\nDeque is Empty.\n");
        return 0;
    }

    item = arr[*pRear];
    arr[*pFront] = 0;
    (*pRear)--;

    if (*pRear == -1)
        *pFront = -1;
    return item;
}


void Display(int *arr)
{
    int i;

    printf("\nFront : ");
    for(i = 0; i < MAX ; i++)
       printf(" %d", arr[i]);
    printf(" :Rear");   
}


//////// Few Bug in delRear Function ////////
int main()
{
    int arr[MAX];
    int front, rear, i, n;

    front = rear = -1;
    for (i = 0; i < MAX; i++)
        arr[i] = 0;

    addRear(arr, 6, &front , &rear);    
    addFront(arr, 12, &front , &rear);    
    addRear(arr, 18, &front , &rear);    
    addFront(arr, 20, &front , &rear);    
    addRear(arr, 36, &front , &rear);    
    addFront(arr, 43, &front , &rear); 

    printf("\nElements in a Deque: ");
    Display(arr);
    
    // Removing elements using front Fuction
    printf("\nRemoved item: %d", delFront(arr, &front, &rear)); 

    // Displaying After Deltion front 
    printf("\nElements in a Deque after Deletion: ");
    Display(arr);  

    addRear(arr, 45, &front , &rear); 
    addRear(arr, 5, &front , &rear); 

    /// Displaying after Adding Rear
    printf("\nElements in a Deque after Addition: ");
    Display(arr);

    // Removed element using Rear function
    printf("\nReamoved item: %d", delRear(arr, &front, &rear));

    // Displaying after Deleting Rear
    printf("\nElements in a Deque after Deletion: ");
    Display(arr); 

    // Counting Deque Elements
    printf("\nTotal number of elements in Deque: %d", Count(arr));

    return 0;
}