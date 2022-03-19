/*
 * main.c
 *
 *  Created on: Feb 7, 2022
 *      Author: Samaa Seif
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct LinkedList LinkedList;
struct Node
{
    int Data;
    Node *Prev, *Next;
};
struct LinkedList
{
    Node *Head, *Tail;
};
LinkedList* Reverse (LinkedList list );
Node* GetNodeByData(LinkedList *list, int data);

int main()
{
    char sw,select;
    int d, ad,bd,In; /*The variable for data(d), data after(ad) , data before(bd) & Index of the data*/
    int Flag=1;  /*Flag for while loop to stop it.*/
    LinkedList mylist;
    mylist.Head=mylist.Tail=NULL;
    while(Flag)
    {
        printf("Enter the list of your data.\n");
        while(sw!='c')
        {
            scanf("%d",&d);
            scanf("%c",&sw);
            if(sw!='c')
                Add(&mylist,d);
        }
        Display(mylist);
        while(Flag)
        {
            printf("\nSelect what you want:\n");
            printf("A(Insert After Data)  B(Insert Before Data)  R(Remove a Data)  D(Get Node by Data)\n");
            printf("I(Get Data by Index)  V(Reverse List in new one)  L(Reverse List in same one)  E(Exit)\n");
            scanf("%c",&select);
            switch(select)
            {
            case'A': /*To insert after the data you want*/
                    printf("Enter a data to insert in the list after the data exist in list.\n");
                scanf("%d %d",&ad,&d);
                InsertAfter(&mylist,ad,d);
                printf("\n \nThe new List is:  \n");
                Display(mylist);
                break;
            case'B': /*To insert before the data you want*/
                    printf("Enter a data to insert in the list before the data exist in list.\n");
                scanf("%d %d",&bd,&d);
                InsertAfter(&mylist,bd,d);
                printf("\n \nThe new List is:  \n");
                Display(mylist);
                break;
            case'R': /*To remove a specified data you want*/
                printf("Enter the data to remove it from the list.\n");
                scanf("%d",&d);
                Remove(&mylist,d);
                printf("\n \nThe new List is:  \n");
                Display(mylist);
                break;
            case'D': /*To get a node by its data*/
                    printf("Enter the data to get its node.\n");
                scanf("%d",&d);
                GetNodeByData(&mylist,d);
                break;
            case'I': /*To select a data by its index*/
                printf("Enter the index to get its data.\n");
                scanf("%d",&In);
                int data=GetDataByIndex(&mylist,In);
                printf("\nThe Data of the Index is:  %d\n",data);
                break;
            case'V': /*To reverse the list in new one*/
                printf("The reversed list in new one is:\n");
                Display(*(Reverse(mylist)));
                break;
            case'L': /*To reverse the list in new one*/
                printf("The reversed list in the same one is:\n");
                InPlaceReverse(&mylist);
                Display(mylist);
                break;
            case'E': /*To exit from while loop*/
                    printf("\nThe process is finished :D.\n\n");
                Flag=0;
                break;
            }
        }
    }
    return 0;
}

/*Main Functions used*/
Node* Create_Node(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->Data=data;
    newNode->Next=newNode->Prev=NULL;

    return newNode;
}
void Add(LinkedList *list, int data)
{
    Node *newNode=Create_Node(data);

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
void Display(LinkedList list)
{
    Node *current=list.Head;

    while(current!=NULL)
    {
        printf("%d \t",current->Data);
        current=current->Next;
    }
}
Node* GetNodeByData(LinkedList *list, int data)
{
    Node *current=list->Head;
    while(current!=NULL)
    {
        if(data==current->Data)
            return current;
        current=current->Next;
    }
    return NULL;
}
void Remove (LinkedList *list, int data)
{
    Node *node = GetNodeByData(list,data);
    if (node == NULL)
        return;
    if(node == list->Head)
    {
        if (list->Head == list->Tail)
        {
            list->Head=list->Tail=NULL;
        }
        else
        {
            list->Head = list->Head->Next;
            list->Head->Prev=NULL;
        }
    }
    else if (node == list->Tail)
    {
        list->Tail=list->Tail->Prev;
        list->Tail->Next=NULL;
    }
    else
    {
        node->Prev->Next=node->Next;
        node->Next->Prev=node->Prev;
    }
    free(node);
}
void InsertAfter(LinkedList *list, int data, int afterData)
{
    Node *newNode =Create_Node(data);
    Node *current =list->Head;
    while(current !=NULL)
    {
        if(current->Data ==afterData)
        {
            if(current==list->Tail)
            {
                newNode->Prev=current;
                current->Next=newNode;
                newNode->Next=NULL;
                list->Tail=newNode;
            }
            else
            {
                newNode->Prev=current;
                newNode->Next=current->Next;
                current->Next->Prev=newNode;
                current->Next=newNode;
            }
        }
        current=current->Next;
    }
}
void InsertBefore(LinkedList *list, int data, int beforeData)
{
    Node *newNode = Create_Node(data);
    Node *current = list->Head;
    while(current !=NULL)
    {
        if(current->Data == beforeData)
        {
            if(current==list->Head)
            {
                newNode->Prev=NULL;
                newNode->Next=current;
                current->Prev=newNode;
                list->Head=newNode;
            }
            else
            {
                newNode->Next=current;
                newNode->Prev=current->Prev;
                current->Prev->Next=newNode;
                current->Prev=newNode;
            }
        }
        current=current->Next;
    }
}
int GetDataByIndex(LinkedList *list,int index)
{
    Node *current = list->Head;
    int count=index;
    while (count !=0)
    {
        current=current->Next;
        count--;
    }
    return current->Data;
}

LinkedList* Reverse (LinkedList list )
{
    LinkedList* newList=(LinkedList *)malloc(sizeof(LinkedList));;
    newList->Head = newList->Tail = NULL;
    Node *current = list.Tail;
    if(current==NULL)
    {
        return 0;
    }
    else
    {
        while(current!=NULL)
        {
            Add (newList,current->Data);
            current=current->Prev;
        }
    }
    return newList;
}

void InPlaceReverse (LinkedList *list)
{
    LinkedList List;
    List.Head=list->Head;
    List.Tail=list->Tail;
    Node *temp;
    while(List.Head!=List.Tail)
    {
        temp=List.Head->Data;
        List.Head->Data=List.Tail->Data;
        List.Tail->Data=temp;
        if(List.Head->Next==List.Tail)
            return;
        List.Head=List.Head->Next;
        List.Tail=List.Tail->Prev;
    }
}
