#include <stdio.h>
#include <stdlib.h>

#define NormalQueue 0
#define QueueShifting 1
#define QueueCircular 2

#define Queue_Method QueueCircular
typedef struct QueueNode QueueNode;
struct QueueNode
{
    int *arr;
    int Data;
    int size, front, rear;
};
QueueNode* CreateQueue(int size)
{
    QueueNode*p=(QueueNode *)malloc(sizeof(QueueNode));
    p->size=size;
    p->arr=(int*)malloc(size*sizeof(int));
    p->front=p->rear=-1;
    return p;
}
void EnQueue(QueueNode* que,int data)
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
int DeQueue(QueueNode* que,int* data)
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
int DeQueueShifting(QueueNode* que,int* data)
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
void EnQueueCircluar(QueueNode *que, int data)
{
    if(IsFull(que))
        return;
    if(IsEmpty(que))
        que->front++;
    if(que->rear == que->size-1 && que->front!=0)
        que->rear=0;
    else
        que->rear++;
    que->arr[que->rear]=data;
}

int DeQueueCircluar(QueueNode *que, int *data)
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
    int d,s,num,flag=0;
    char sw,select;
    printf("Enter the size of your queue.\n");
    scanf("%d",&s);
    Queue* myque= CreateQueue(s);
    printf("\nSelect what you want:\n");
    printf("C(QueueCircular)  N(NormalQueue)  \n");
    printf("c(DeQueueCircular)  s(DeQueueShifting)  n(NormalDeQueue)\n");
    scanf("%c",&select);
    switch(select)
    {
    case'C':
            while(sw!='c')
            {
                scanf("%d",&d);
                scanf("%c",&sw);
                if(sw!='c')
                    EnQueueCircluar(myque,d);
            }
        break;
    case'N':
        while(sw!='c')
        {
            scanf("%d",&d);
            scanf("%c",&sw);
            if(sw!='c')
                EnQueue(myque,d);
        }
        break;
    case'c':
            while(flag==0)
            {
                if(DeQueueCircluar(myque,& num))
                    printf("%d\n",num);
                else
                    flag=1;
            }
        break;
    case's':
        while(flag==0)
        {
            if(DeQueueShifting(myque,& num))
                printf("%d\n",num);
            else
                flag=1;
        }
        break;
    }
case'n':
    while(flag==0)
    {
        if(DeQueue(myque,& num))
            printf("%d\n",num);
        else
            flag=1;
    }
    break;
}
return 0;
}
