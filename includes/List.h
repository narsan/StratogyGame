#ifndef LIST_H
#define LIST_H
#include "Problem.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// a typedef struct for
// a node of list
typedef struct Node
{
    Problem      Data;
    int          Possibility;
    struct Node* Next;
}Node;

// create new node and
// allocate 
Node* newNode(Problem data, Node* next, int Poss)
{
    Node* Tmp = (Node *) malloc(sizeof(Node));
    Tmp->Data           = data;
    Tmp->Next           = next;
    Tmp->Possibility    = Poss;
}

// a fuctrion to add
// to first of list
Node* AddTo_FirstOf_List(Node* head, Problem data, int Poss)
{
    return newNode(data, head, Poss);
}

// load all choices in game
// from files
Node * LoadChoices(int* Arr)
{
    Node* Head = NULL;

    FILE * Choices_File = fopen("files//CHOICES.txt", "r+");
    if(Choices_File == NULL)
        printf("error opening CHOICES file...\n");

    char Addresses[20];
    int count = 0;
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
        printf("%d-",count);
        Head = AddTo_FirstOf_List(Head, Tmp, Arr[count++]);
        fclose(Fchoice);
    }
    fclose(Choices_File);
    printf("%s",Head->Data.question);
    return Head;
}

// free the allocated memory
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

// if the node Possibility
// is 0 (or under 0)
// delete the node
void TestForDelete(Node* Head, Node* Goal)
{
    if (Goal != NULL)
        if(Goal->Possibility <= 0)
        {
            Node* BeforeGoal = Head;
            for(; BeforeGoal->Next != Goal; BeforeGoal= BeforeGoal->Next){}
            BeforeGoal ->Next = Goal->Next;
            free(Goal);
        }
}

// get the counting of
// choices that we have
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

// add new problem to game and
// to the link list
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
    Head = AddTo_FirstOf_List(Head, Pr, 3);
}

#endif /* !LIST_H */