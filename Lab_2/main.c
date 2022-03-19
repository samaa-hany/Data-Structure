/*
 * main.c
 *
 *  Created on: Feb 8, 2022
 *      Author: Samaa Seif
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode StackNode;
typedef struct StackList StackList;

struct StackNode
{
    //int *arr;
    int Data;
    //int size, top;
    StackNode *Next, *Prev;
};
struct StackList
{
    StackNode *Top;
};

StackNode* CreateStackNode(int data)
{
    StackNode *newStack = (StackNode *)malloc(sizeof(StackNode));
    newStack->Data=data;
    newStack->Next=newStack->Prev=NULL;

    return newStack;
}

StackList* CreateStackList()
{
    StackList *newStackList=(StackList *)malloc(sizeof(StackList));
    newStackList->Top=NULL;

    return newStackList;
}

void Push(StackList *stk, int data)
{
    StackNode *oldStack =CreateStackNode(data);
    if(IsEmptyList(stk))
    {

    }
    else
        stk->Top->Next=oldStack;
    oldStack->Data = data;
    oldStack->Prev=stk->Top;
    stk->Top=oldStack;
}

int PoP(StackList *stk,int *data)
{
    StackNode *current;
    if(IsEmptyList(stk))
        return 0;
    else
    {
        *data=stk->Top->Data;
        current = stk->Top;
        stk->Top=stk->Top->Prev;
        free(current);
    }
    return 1;
}

int IsEmptyList(StackList *stk)
{
    return stk->Top==NULL;
}

int main()
{
    StackList* mystklist= CreateStackList();
    Push(mystklist,3);
    Push(mystklist,5);
    Push(mystklist,7);
    Push(mystklist,9);
    Push(mystklist,11);

    int num;
    if(PoP(mystklist,&num))
        printf("%d \n",num);
    else
        printf("Stack is empty");
    return 0;
}



/*int PoP(Stack *stk, int *data)
{
    if(IsEmpty(stk))
        return 0;

    *data = stk->arr[stk->top];
    stk->top--;
    return 1;
}

void Push(Stack *stk, int data)
{
    if(IsFull(stk))
        return;
    stk->top++;
    stk->arr[stk->top]=data;
}
int IsFull(Stack *stk)
{
    return stk->top==stk->size-1;
}

int IsEmpty(Stack *stk)
{
    return stk->top==-1;
}
StackList *mystqlist=CreateStack();
    Stack *stk=CreateStack(5);
    Push(stk,3);
    Push(stk,5);
    Push(stk,7);
    Push(stk,9);
    Push(stk,11);

    Stack s;
    s.arr=(int *)alloc(5*sizeof(int));*/
