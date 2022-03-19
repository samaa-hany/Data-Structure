#include <stdio.h>
#include <stdlib.h>

#define NormalQueue 0
#define QueueShifting 1
#define QueueCircular 2

#define Queue_Method QueueCircular
typedef struct Queue Queue;

struct Queue
{
    int* arr;
    int size,front,rear;
};
Queue* CreateQueue(int size)
{
    Queue*p=(Queue*)malloc(sizeof(Queue));
    p->size=size;
    p->arr=(int*)malloc(size*sizeof(int));
    p->front=p->rear=-1;
    return p;
}
void EnQueue(Queue* que,int data)
{
    if(IsFull(que))
    {
        return;
    }
    if(IsEmpty(que))
        que->front++;
    que->rear++;
    que->arr[que->rear]=data;
}
int DeQueue(Queue* que,int* data)
{
    if(IsEmpty(que))
        return 0;
    *data=que->arr[que->front];
    if(que->front==que->rear)
        que->front=-1;
    else
        que->front++;
    return 1;
}
int IsEmpty(Queue* que)
{
    return que->front==-1  ;
}
int DeQueueShifting(Queue* que,int* data)
{
    int counter=0;
    if(IsEmpty(que))
        return 0;
    *data=que->arr[que->front];
    while(counter!=que->rear)
    {
        que->arr[counter]=que->arr[counter+1];
        counter++;
    }
    que->rear--;
    if(que->rear==-1)
        que->front=-1;
    return 1;
}
void EnQueueCircluar(Queue *que, int data)
{
    if(IsFull(que))
        return;

    if(IsEmpty(que))
        que->front++;

    if(que->rear == que->size-1 && que->front!=0)
    {
        que->rear=0;
    }
    else
    {
        que->rear++;
    }
    que->arr[que->rear]=data;
}

int DeQueueCircluar(Queue *que, int *data)
{
    if(IsEmpty(que))
        return 0;

    *data = que->arr[que->front];
    if(que->front == que->rear)
        que->front = que->rear =-1;
    else
    {
        que->front++;
        if(que->front == que->size)
            que->front =0;
    }
    return 1;
}

int IsFull(Queue *que)
{
    if (que->front==0 )
        return (que->rear == que->size-1) ;
    else
        return (que->front - que->rear == 1);
}

int main()
{
    int num,flag=0;
    Queue* myque= CreateQueue(5);
#if Queue_Method == QueueCircular
    EnQueueCircluar(myque,5);
    EnQueueCircluar(myque,8);
    EnQueueCircluar(myque,9);
    EnQueueCircluar(myque,1);
    EnQueueCircluar(myque,12);
    DeQueueCircluar(myque,& num);

    EnQueueCircluar(myque,13);
    EnQueueCircluar(myque,15);
    while(flag==0)
    {
        if(DeQueueCircluar(myque,& num))
        {
            printf("%d\n",num);
        }
        else
        {
            flag=1;
        }
    }
#elif Queue_Method == QueueShifting
    EnQueue(myque,5);
    EnQueue(myque,8);
    EnQueue(myque,9);
    EnQueue(myque,1);
    EnQueue(myque,12);
    DeQueueShifting(myque,& num);
    EnQueueCircluar(myque,13);
    EnQueueCircluar(myque,15);
    while(flag==0)
    {
        if(DeQueueShifting(myque,& num))
        {
            printf("%d\n",num);
        }
        else
        {
            flag=1;
        }
    }
#endif



    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>

void Swap(int *f, int *s)
{
    int temp=*f;
    *f=*s;
    *s=temp;
}
void BubbleSort(int *arr, int size)
{
    int sorted=0;
    for(int count=0; count<size-1 && sorted==0 ; count++)
    {
        sorted=1;
        for(int index=0; index<size-count-1 ; index++)
        {
            if(arr[index]>arr[index+1])
            {
                Swap(&arr[index],&arr[index+1]);
                sorted=0;
            }
        }
    }
}
void Selectionort(int *arr, int size)
{
    for(int count=0; count<size-1 ; count++)
    {
        int mini=0;
        for(int i=0; i<size; i++)
        {
            if(arr[i]<arr[mini])
                mini=i;
        }
        Swap(&arr[0],&arr[mini]);
    }
}
void InsertionSort(int *arr, int size)
{
    int count,index,key;
    for(count=1; count<size; count++)
    {
        key=arr[count];
        index=count-1;

        while(index>=0&&arr[index]>key)
        {
            arr[index+1]=arr[index];
            index--;
        }
        arr[index+1]=key;
    }
}
int BinarySearch(int data,int *arr, int size)
{
    int minIndex=0, maxIndex=size-1, midIndex;
    while(minIndex<maxIndex)
    {
        midIndex=(minIndex+maxIndex)/2;
        if(data==arr[midIndex])
            return midIndex;

        else if(data>arr[midIndex])
            minIndex=midIndex+1;

        else
            maxIndex=midIndex-1;
    }
}
void Display(int *arr, int size)
{
    for(int index=0; index<size; index++)
    {
        printf("%d \t",arr[index]);
    }
}


int main()
{
    int arr_test[]= {7,8,4,1,5,9};

    //Selectionort(arr_test,6);
    BubbleSort(arr_test,6);
    //InsertionSort(arr_test,6);
    Display(arr_test,6);

    int i=BinarySearch(4,arr_test,6);
    printf("\n%d \n",i);

    return 0;
}
*/
