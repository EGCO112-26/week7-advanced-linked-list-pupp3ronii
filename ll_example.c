#include <stdio.h>
#include "ll.h"

int main(void)
{
    LLPtr startPtr = NULL;
    unsigned int choice;
    int id;
    char name[50];

    instructions();
    printf("? ");
    scanf("%u", &choice);

    while (choice != 3) {

        switch (choice) {

        case 1:
            printf("Enter id and name: ");
            scanf("%d %49s", &id, name);
            insert(&startPtr, id, name);
            printList(startPtr);
            break;

        case 2:
            printf("Enter number to be deleted: ");
            scanf("%d", &id);

            if (deletes(&startPtr, id)) {
                printf("%d deleted.\n", id);
                printList(startPtr);
            }
            break;
        }

        printf("? ");
        scanf("%u", &choice);
    }

    if (!isEmpty(startPtr))
        clearList(&startPtr);

    puts("End of run.");
    return 0;
}
