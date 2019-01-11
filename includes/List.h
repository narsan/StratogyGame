#ifndef LIST_H
#define LIST_H
#include "Problem.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void AddToEnd(Node* head, Problem data)
{
    if(head == NULL)
        head = newNode(data, NULL);
    
    Node* Tmp = head;
    while(Tmp->Next != NULL)
        Tmp = Tmp->Next;
    
    Tmp->Next = newNode(data, NULL);
}


Node * LoadChoices()
{
    //Node* Head = NULL;

    FILE * Choices_File = fopen("files//CHOICES.txt", "r+");
    if(Choices_File == NULL)
        printf("error opening CHOICES file...\n");

    char T[20];

    while(feof(Choices_File) == 0)
    {
        fscanf(Choices_File, "%s\n", T);
        printf("%s\n",T);


        Problem TmpProblem;
        FILE * Fchoice = fopen(T, "r+");
        if(Fchoice == NULL)
            printf("error opening file...\n");
        
        fclose(Fchoice);
    }
    
    
    fclose(Choices_File);
}


#endif /* !LIST_H */