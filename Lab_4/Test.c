/*#include <stdio.h>
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
            //tree->Root->Right=newNode;
            else
                current=current->Left;
            //tree->Root->Left=newNode;
        }
        if(data>parent->Data)
            parent->Right=newNode;
        else
            parent->Left=newNode;
    }
}
Node *GetNodeByData(Tree *tree,int data)
{
    Node *current=tree->Root;
    while(current!=NULL)
    {
        if(data==current->Data)
            return current;
        if(data > current->Data)
            current=current->Right;
        else(data < current->Data)
            current=current->Left;
    }
    return NULL;
}
Node *GetParent(Tree*tree,Node *node)
{
    Node *parent=tree->Root;
    while(parent!=NULL)
    {
        if(parent->Left==node || parent->Right==node)
            return parent;
        if(node->Data > parent->Data)
            parent=parent->Right;
        else
            parent=parent->Left;
    }
    return NULL;
}
Node *GetMaxRight(Node *node)
{
    Node *current=node;
    while(current->Right!=NULL)
        current=current->Right;

    return current;
}
void Remove(Tree *tree,int data)
{
    Node *node=GetNodeByData(&tree,data);

    if(node==NULL)
        return;
    if(node==tree->Root)
    {
        if(tree->Root->Left==NULL&&tree->Root->Right==NULL)
        {
            tree->Root=NULL;
        }
        else if(tree->Root->Left==NULL)
        {
            tree->Root=tree->Root->Right;
        }
        else if(tree->Root->Right==NULL)
        {
            tree->Root=tree->Root->Left;
        }
        else
        {
            Node *newRoot=tree->Root->Left;
            Node *maxRight= GetMaxRight(newRoot);
            maxRight->Right=tree->Root->Right;
            tree->Root=newRoot;
        }
    }
    else
    {
        Node *parent=GetParent(tree,node);
        Node *newChild;
        if(tree->Root->Left==NULL&&tree->Root->Right)
        {
            newChild=NULL;
        }
        else if(tree->Root->Left=NULL)
        {
            newChild=node->Right;
        }
        else if(tree->Root->Right=NULL)
        {
            newChild=node->Left;
        }
        else
        {
            Node *newParent=node->Left;
            Node *maxRight= GetMaxRight(newParent);
            maxRight->Right=node->Right;
            newChild=newParent;
        }
        if(parent->Left==node)
            parent->Left=newChild;
        else
            parent->Right=newChild;
    }
    free(node);
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

}
int main()
{
    Tree *tree=CreatTree();
    Add(tree,50);
    Add(tree,40);
    Add(tree,45);
    Add(tree,60);
    Add(tree,30);
    Display(&tree);

    return 0;
}*/
