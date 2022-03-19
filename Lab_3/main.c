/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: Samaa Seif
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct Node
{
    int Key;
    Node *Next, *Prev;
};

struct LinkedList
{
    Node *Mid, *Head, *Tail;
};

Node* CreateNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->Key=data;
    newNode->Next=newNode->Prev=NULL;

    return newNode;
}

/*LinkedList* CreateList()
{
    LinkedList *newList=(LinkedList *)malloc(sizeof(LinkedList));
    newList->Mid=newList->Head=newList->Tail=NULL;

    return newList;
}*/

void Add(LinkedList *list, int data)
{
    Node *newNode=CreateNode(data);

    if(list->Head==NULL)
    {
        list->Head=list->Tail=newNode;
    }
    else
    {
        list->Tail->Next=newNode;
        newNode->Prev=list->Tail;
        list->Tail=newNode;
    }
}

void Swap(Node *First, Node *Second)
{
    int temp = First->Key;
    First->Key = Second->Key;
    Second->Key = temp;
}

void BubbleSort(LinkedList *list)
{
    int sorted=1;
    Node *index, *flag = NULL;

    if (list->Head == NULL)
        return;

    while (sorted)
    {
        sorted = 0;
        index = list->Head;

        while (index->Next != flag)
        {
            if (index->Key > index->Next->Key)
            {
                Swap(index, index->Next);
                sorted = 1;
            }
            index = index->Next;
        }
        flag = index;
    }
}
Node* Middle(Node *Min,Node *Max)
{
    Node *Left,*Right;
    if (Min == NULL)
        return NULL;
    Left = Min;
    Right = Min->Next;
    while (Max != Right)
    {
        Right=Right->Next;
        if (Max != Right)
        {
            Left=Left->Next;
            Right=Right->Next;
        }
    }
    return Left;
}
Node* BinarySearch(int data,LinkedList *List)
{
    Node *Min=List->Head;
    Node *Max=NULL;
    while (Max == NULL || Max != Min)
    {
        Node* Mid = Middle(Min, Max);
        if (Mid == NULL)
            return NULL;
        if(Mid->Key==data)
            return Mid;
        else if(Mid->Key < data)
            Min=Mid->Next;
        else
            Max=Mid;
    }
    return NULL;
}
void DisplayList(LinkedList list)
{
    Node *current=list.Head;

    while(current!=NULL)
    {
        printf("%d \t",current->Key);
        current=current->Next;
    }
}


int main()
{
    int d;
    char sw;
    LinkedList mylist;
    mylist.Head=mylist.Tail=NULL;
    printf("Enter the list of your data.\n");
    while(sw!='c')
    {
        scanf("%d",&d);
        scanf("%c",&sw);
        if(sw!='c')
            Add(&mylist,d);
    }
    printf("Your list before sorting.\n");
    DisplayList(mylist);
    printf("\n \nYour list after sorting.\n");
    BubbleSort(&mylist);
    DisplayList(mylist);
    printf("\n \nThe address of data you searched about, is:\n");
    Node *index=BinarySearch(5,&mylist);
    printf("%d \n",index);


    return 0;
}
