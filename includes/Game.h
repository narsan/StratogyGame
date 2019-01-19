#ifndef GAME_H
#define GAME_H
#include"..//includes//Ruler.h"
#include"..//includes//Problem.h"
#include"..//includes//List.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void PrintStatus(UserSt UserPr)
{
    printf("%d\n%d\n%d\n%d\n",
    UserPr.people,
    UserPr.court,
    UserPr.treasury,
    UserPr.isInGame
    );

    for(int i = 0; i < UserPr.size; i++)
    {
        printf("%d ", UserPr.Arr[i]);
    }
    printf("\n");
}

void GameRun()
{
    
    char Name[20];
    printf("enter your name: ");
    scanf("%s", Name);

    UserSt UserPr;
    if(isUserExist(Name))
    {
        UserPr = LoadUserByName(Name);
        printf("welcome back %s\n", UserPr.name);
    }
    else
    {
        UserPr = newUser(Name);
        printf("new User!\n");
    }

    Node* Choices_list = LoadChoices(UserPr.Arr);
    int choice;
    while(1)
    {
        PrintStatus(UserPr);
        printf("%d\n", 5);
        //printf("%d",Choices_list->Possibility);
        printf("enter your choice: ");
        scanf("%d", &choice);
    }
    
    


    unLoadChoices(Choices_list);
}




#endif  /* !GAME_H */