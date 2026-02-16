#ifndef LL_H
#define LL_H

#include <stdio.h>

struct Node {
    int id;
    char name[50];
    struct Node *nextPtr;
    struct Node *prevPtr;
};

typedef struct Node LLnode;
typedef LLnode *LLPtr;


void instructions(void);

int isEmpty(LLPtr sPtr);

void insert(LLPtr *sPtr, int id, const char *name);
int deletes(LLPtr *sPtr, int id);

void printList(LLPtr currentPtr);
void clearList(LLPtr *sPtr);

#endif
