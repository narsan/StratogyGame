#include"..//includes//Ruler.h"
#include"..//includes//Problem.h"
#include"..//includes//List.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main()
{
    Node* Ch = LoadChoices();
    Problem tmp = newProblem(
        "mamad am che konam",
        "besik", 5, 0, -5,
        "bemun", -5, 5, 5
    );
    addNewProblem_toGame(Ch, tmp);
    
    return 0;
}


