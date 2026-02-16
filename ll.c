// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h"

int main( void )
{ 
   LLPtr startPtr = NULL; // initially there are no nodes
   unsigned int choice; // user's choice ไม่มีค่าติดลบ
   int item; // char entered by user
   char name[50];

   instructions(); // display the menu
   printf( "%s", "? " );
   scanf( "%u", &choice );

   // loop while user does not choose 3
   while ( choice != 3 ) { 

      switch ( choice ) { 
         case 1:
            printf( "%s", "Enter id and name: " );
            scanf("%d %s", &item, name);
            insert( &startPtr, item , name); // insert item in list
            printList( startPtr );
            printListR( startPtr );
            break;
         case 2: // delete an element
            // if list is not empty
            if ( !isEmpty( startPtr ) ) { 
               printf( "%s", "Enter number to be deleted: " );
               scanf( "%d", &item );

              
               if ( deletes( &startPtr, item ) ) { 
                  printf( "%d deleted.\n", item );
                  printList( startPtr );
                  printListR( startPtr );
               } 
               else {
                  printf( "%d not found.\n\n", item );
               } 
            } 
            else {
               puts( "List is empty.\n" );
            } 

            break;
         default:
            puts( "Invalid choice.\n" );
            instructions();
            break;
      } 

      printf( "%s", "? " );
      scanf( "%u", &choice );
   } 

   puts("Clear all nodes");

   LLPtr tempPtr;
   while ( startPtr != NULL ) { 
      printf("delete %d\n",startPtr->data);
      deletes( &startPtr, startPtr->data );
   }
   
   puts("End of run.");
} 