#ifndef PROBLEM_H
#define PROBLEM_H

// a typedef struct for every
// option
typedef struct
{
    char what[100];
    int  people;
    int  court;
    int  treasury;

} Choices;


// a typedef struct for every
// problem in country
typedef struct
{
    char    question[100];
    Choices choices[2];

} Problem;


#endif  /* !PROBLEM_H */