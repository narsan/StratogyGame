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
    Node* Head = NULL;

    FILE * Choices_File = fopen("files//CHOICES.txt", "r+");
    if(Choices_File == NULL)
        printf("error opening CHOICES file...\n");

    char Addresses[20];

    while(feof(Choices_File) == 0)
    {
        Problem Tmp;

        fscanf(Choices_File, "%s\n", Addresses);
        FILE * Fchoice = fopen(Addresses, "r+");
        if(Fchoice == NULL)
            printf("error opening file...\n");
        
        fscanf(Fchoice ,"%[^\n]\n%[^\n]\n%d\n%d\n%d\n%[^\n]\n%d\n%d\n%d",
        Tmp.question,
        Tmp.choices[0].what,
        &Tmp.choices[0].people,
        &Tmp.choices[0].court,
        &Tmp.choices[0].treasury,
        Tmp.choices[1].what,
        &Tmp.choices[1].people,
        &Tmp.choices[1].court,
        &Tmp.choices[1].treasury
        );


        // printf("%s\n%s\n%d\n%d\n%d\n%s\n%d\n%d\n%d\n",
        // Tmp.question,
        // Tmp.choices[0].what,
        // Tmp.choices[0].people,
        // Tmp.choices[0].court,
        // Tmp.choices[0].treasury,
        // Tmp.choices[1].what,
        // Tmp.choices[1].people,
        // Tmp.choices[1].court,
        // Tmp.choices[1].treasury
        // );
        AddToEnd(Head, Tmp);
        fclose(Fchoice);
    }
    fclose(Choices_File);
    return Head;
}

void unLoadChoices(Node* Head)
{
    Node* Tmp = Head;
    while(Head)
    {
        Tmp = Head->Next;
        free(Head);
        Head = Tmp;
    }
}

int getLastNumber_OfChoices()
{
    FILE * Choices_File = fopen("files//CHOICES.txt", "r+");
    if(Choices_File == NULL)
        printf("error opening CHOICES file...\n");

    int Num;
    while(feof(Choices_File) == 0)
    {
        char Tmp[20];
        fscanf(Choices_File, "%s\n", Tmp);
        
        Num = 0;
        for(int i=0; Tmp[i]!='\0'; i++)
            if(Tmp[i] >= '0' && Tmp[i] <= '9')
            {
                Num = (Tmp[i] - '0') + Num * 10;
            }
    }
    fclose(Choices_File);
    return Num;
}

void addNewProblem_toGame(Node* Head, Problem Pr)
{
    int Num = getLastNumber_OfChoices() + 1;
    FILE * Choices_File = fopen("files//CHOICES.txt", "a");
    fprintf(Choices_File, "\nfiles//c%d.txt", Num);

    char Tmp[20];
    sprintf(Tmp, "files//c%d.txt", Num);
    FILE * newFile = fopen(Tmp, "w+");
    
    fprintf(newFile, "%s\n%s\n%d\n%d\n%d\n%s\n%d\n%d\n%d",
        Pr.question,
        Pr.choices[0].what,
        Pr.choices[0].people,
        Pr.choices[0].court,
        Pr.choices[0].treasury,
        Pr.choices[1].what,
        Pr.choices[1].people,
        Pr.choices[1].court,
        Pr.choices[1].treasury
        );

    fclose(newFile);
    fclose(Choices_File);
    AddToEnd(Head, Pr);
}

#endif /* !LIST_H */