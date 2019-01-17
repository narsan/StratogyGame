#ifndef PROBLEM_H
#define PROBLEM_H
#include<string.h>

// a typedef struct for every
// option
typedef struct
{
    char what[200];
    int  people;
    int  court;
    int  treasury;

} Choice;


// a typedef struct for every
// problem in country
typedef struct
{
    char    question[200];
    Choice  choices[2];

} Problem;


Problem newProblem(char* ques, 
    char* op0, int r0p, int r0c, int r0t,
    char* op1, int r1p, int r1c, int r1t)
{
    Problem pr;
    strcpy(pr.question, ques);
    strcpy(pr.choices[0].what, op0);
    pr.choices[0].people     = r0p;
    pr.choices[0].court      = r0c;
    pr.choices[0].treasury   = r0t;
    strcpy(pr.choices[1].what, op1);
    pr.choices[1].people     = r1p;
    pr.choices[1].court      = r1c;
    pr.choices[1].treasury   = r1t;
    return pr;
}

#endif  /* !PROBLEM_H */