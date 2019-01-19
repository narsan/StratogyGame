
#ifndef RULER_H
#define RULER_H
#include<stdio.h>
#include<string.h>
#include"..//includes//List.h"

// typedef struct for a ruller
// and his country
typedef struct
{
    char name[20];
    int isInGame;

    // value is beetwen 0 , 100
    int people;
    int court;
    int treasury;

    int Arr[20];
    int size;
} UserSt;

int isUserExist(char* Name)
{
    char Address[40];
    sprintf(Address, "users//%s.txt", Name);

    FILE * UserFile = fopen(Address, "rb+");
    if(UserFile == NULL)
        return 0;
    else
    {
        fclose(UserFile);
        return 1;
    }
}

UserSt newUser(char* Name)
{
    char Address[40];
    sprintf(Address, "users//%s.txt", Name);
    UserSt UserPr;
    strcpy(UserPr.name, Name);
    UserPr.people   = 50;
    UserPr.court    = 50;
    UserPr.treasury = 50;
    UserPr.isInGame = 0;


    UserPr.size = getLastNumber_OfChoices();
    for(int i=0; i<UserPr.size; i++)
    {
        UserPr.Arr[i] = 3;
    }


    FILE * UserFile = fopen(Address, "wb+");
    fwrite(&UserPr, sizeof(UserPr), 1, UserFile);
    fclose(UserFile);

    return UserPr;
}

UserSt LoadUserByName(char* Name)
{
    char Address[40];
    sprintf(Address, "users//%s.txt", Name);

    UserSt UserPr;
     
    FILE * UserFile = fopen(Address, "rb+");
    fread(&UserPr, sizeof(UserPr), 1, UserFile);
    fclose(UserFile);

    return UserPr;
}

void saveThis(UserSt UserPr)
{
    char Address[40];
    sprintf(Address, "users//%s.txt", UserPr.name);
    
    FILE * UserFile = fopen(Address, "wb");
    fread(&UserPr, sizeof(UserPr), 1, UserFile);
    fclose(UserFile);
}


#endif  /* !RULER_H */