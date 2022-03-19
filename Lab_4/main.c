/*
 * main.c
 *
 *  Created on: Feb 10, 2022
 *      Author: Samaa Seif
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
typedef struct Tree Tree;
struct Node
{
    int Data;
    Node *Left, *Right;
};
struct Tree
{
    Node *Root;
};
Tree* CreatTree()
{
    Tree *tree=(Tree *)malloc(sizeof(Tree));
    tree->Root=NULL;
    return tree;
}
Node* CreatNode(int data)
{
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->Data=data;
    newNode->Left=newNode->Right=NULL;
    return newNode;
}
void Add(Tree *tree,int data)
{
    Node *newNode =CreatNode(data);
    if(tree->Root==NULL)
        tree->Root=newNode;
    else
    {
        Node *current=tree->Root;
        Node *parent;
        while(current!=NULL)
        {
            parent=current;
            if(data > current->Data)
                current=current->Right;
            else
                current=current->Left;
        }
        if(data>parent->Data)
            parent->Right=newNode;
        else
            parent->Left=newNode;
    }
}
int GetMaxRight(Node *node)
{
    int MaxRight=0;
    Node *current=node;
    while(current->Right!=NULL)
    {
        current=current->Right;
        MaxRight++;
    }
    return MaxRight;
}
int GetMaxLeft(Node *node)
{
    int MaxLeft=0;
    Node *current=node;
    while(current->Left!=NULL)
    {
        current=current->Left;
        MaxLeft++;
    }
    return MaxLeft;
}
void Display(Node *node)
{
    if(node==NULL)
        return;
    Display(node->Left);
    printf("%d \t",node->Data);
    Display(node->Right);
}
int GetMaxDepth(Tree *tree)
{
    int LD,RD;
    if (tree->Root == NULL)
        return;
    else
    {
        LD = GetMaxLeft(tree->Root);
        RD = GetMaxRight(tree->Root);
        if (LD > RD)
            return (LD + 1);
        else
            return (RD + 1);
    }
}
int main()
{
    Tree *tree=CreatTree();
    Add(tree,50);
    Add(tree,60);
    Add(tree,40);
    Add(tree,45);
    Add(tree,70);
    Add(tree,30);
    Add(tree,20);
    Add(tree,25);
    Add(tree,10);
    printf("The nodes of the tree is:\n");
    Display(tree->Root);
    printf("\n\nMax No of left nodes in the tree is\n %d \n", GetMaxLeft(tree->Root));
    printf("\nMax No of right nodes in the tree is\n %d \n", GetMaxRight(tree->Root));
    printf("\nMax Depth of the tree is\n %d \n", GetMaxDepth(tree));

    return 0;
}

