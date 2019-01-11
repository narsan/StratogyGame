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

} Option;


// a typedef struct for every
// problem in country
typedef struct
{
    char    question[100];
    Option  options[2];

} Problem;


#endif