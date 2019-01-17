
#ifndef RULER_H
#define RULER_H
#include<stdbool.h>
#include<stdio.h>
// typedef struct for a ruller
// and his country
typedef struct
{
    char name[20];
    bool isInGame;

    // value is beetwen 0 , 100
    int people;
    int court;
    int treasury;

} UserSt;

bool isUserExist(char* Name)
{
    char Address[40];
    sprintf(Address, "users//%s.txt", Name);

    FILE * UserFile = fopen(Address, "r+");
    if(UserFile == NULL)
        return false;
    else
    {
        fclose(UserFile);
        return true;
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

    FILE * UserFile = fopen(Address, "w+");
    fprintf(UserFile, "%s\n%d\n%d\n%d\n%d",
    UserPr.name,
    UserPr.people,
    UserPr.court,
    UserPr.treasury,
    UserPr.isInGame
    );
    return UserPr;
}


#endif  /* !RULER_H */