/*
 * Queue.h
 *
 *  Created on: Feb 8, 2022
 *      Author: Samaa Seif
 */
#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode QueueNode;
typedef struct QueueList QueueList;

struct QueueNode
{
    //int *arr;
    int Data;
    //int size, front, rear;
    QueueNode *Next, *Prev;
};
struct QueueList
{
    QueueNode *Front, *Rear;
};

QueueNode* CreateQueueNode(int data)
{
    QueueNode *newQueue = (QueueNode *)malloc(sizeof(QueueNode));
    newQueue->Data=data;
    newQueue->Next=newQueue->Prev=NULL;

    return newStack;
}

QueueList* CreateQueueList()
{
    QueueList *newQueueList=(QueueList *)malloc(sizeof(QueueList));
    newQueueList->Front=newQueueList->Rear=NULL;

    return newStackList;
}
void EnQueue(QueueList* que,int data)
{
    QueueNode* newQueueNode=CreateQueueNode(data);
    if(IsEmpty(que))
        que->Front=newQueueNode;
    else
        que->Rear->Next=newQueueNode;
    newQueueNode->Prev=que->Rear;
    que->Rear=newQueueNode;
}

int DeQueue(QueueList *que,int *data)
{
    if(IsEmpty(que))
        return 0;
    *data=que->Front->Data;
    Node *newQueueNode=que->Front;
    que->Front=que->Front->Next;
    free(newQueueNode);
    return 1;
}

/*int DeQueue(QueueList* que,int* data)
{
    if(IsEmpty(que))
        return 0;

    *data=que->Front->Data;
    QueueNode* oldQueueNode=que->Front;
    free(oldQueueNode);
    while(que->Rear!=que->Rear->Prev)
    {
        que->Front->Prev=que->Front;
    }
    que->Front=que->Front->Next;
    QueueNode* newQueueNode=que->Rear;
    que->Rear=que->Rear->Prev;

    return 1;
}*/

int IsEmpty(QueueList* que)
{
    return que->Front==NULL;
}
