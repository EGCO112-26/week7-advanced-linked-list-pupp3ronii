#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h"

void instructions(void)
{
    puts("Enter your choice:\n"
         "1 to insert an element into the list.\n"
         "2 to delete an element from the list.\n"
         "3 to end.");
}

int isEmpty(LLPtr sPtr)
{
    return sPtr == NULL;
}

/* insert sorted by id */
void insert(LLPtr *sPtr, int id, const char *name)
{
    LLPtr newPtr = malloc(sizeof(LLnode));
    LLPtr cur = *sPtr;
    LLPtr prev = NULL;

    newPtr->id = id;
    strcpy(newPtr->name, name);
    newPtr->nextPtr = NULL;
    newPtr->prevPtr = NULL;

    while (cur != NULL && id > cur->id) {
        prev = cur;
        cur = cur->nextPtr;
    }

    if (prev == NULL) {                
        newPtr->nextPtr = *sPtr;
        if (*sPtr != NULL)
            (*sPtr)->prevPtr = newPtr;
        *sPtr = newPtr;
    } else {                            
        newPtr->nextPtr = cur;
        newPtr->prevPtr = prev;
        prev->nextPtr = newPtr;
        if (cur != NULL)
            cur->prevPtr = newPtr;
    }
}

int deletes(LLPtr *sPtr, int id)
{
    LLPtr cur = *sPtr;

    while (cur != NULL && cur->id != id)
        cur = cur->nextPtr;

    if (cur == NULL)
        return 0;

    if (cur->prevPtr != NULL)
        cur->prevPtr->nextPtr = cur->nextPtr;
    else
        *sPtr = cur->nextPtr;

    if (cur->nextPtr != NULL)
        cur->nextPtr->prevPtr = cur->prevPtr;

    free(cur);
    return 1;
}

void printList(LLPtr cur)
{
    LLPtr tail = NULL;

    puts("The list is:");

    while (cur != NULL) {
        printf("%d %s --> ", cur->id, cur->name);
        tail = cur;
        cur = cur->nextPtr;
    }
    puts("NULL");

    while (tail != NULL) {
        printf("%d %s --> ", tail->id, tail->name);
        tail = tail->prevPtr;
    }
    puts("NULL");
}

void clearList(LLPtr *sPtr)
{
    LLPtr temp;

    puts("Clear all nodes");
    while (*sPtr != NULL) {
        temp = *sPtr;
        printf("delete %d\n", temp->id);
        *sPtr = (*sPtr)->nextPtr;
        free(temp);
    }
}
