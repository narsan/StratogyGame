#ifndef LIST_H
#define LIST_H
#include "Problem.h"
#include <stdlib.h>

typedef struct Node
{
    Problem Data;
    struct Node* Next;

}Node;

Node* newNode(Problem data, Node* next)
{
    Node* Tmp = (Node *) malloc(sizeof(Node));
    Tmp->Data = data;
    Tmp->Next = next;
}

Node * LoadChoices()
{
    Node* Head = NULL;

}


#endif /* !LIST_H */