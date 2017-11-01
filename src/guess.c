/*
 * Jacob Territo
 * Guessing game main
 * asgn2
 */
#include "guess.h"

int main(void){
   node* root;
   FILE *f = fopen("qa.db","r"); /* The database that the game runs from */

   if(f == NULL){ /* If the given database doesn't exist or is empty it starts from scratch with a single item */
      root = makeNode();
      printf("qa.db: No such file or directory\nUnable to read database qa.db. Starting fresh.\n\nWhat is it (with article)? ");
      root->txt = readLine(stdin);
      if(root->txt == NULL){
         exit(-1);
      }
      while(root->txt[0] == '\0'){
         free(root->txt);
         printf("An empty response is not acceptable.  Please answer again.");
         printf("\nWhat is it (with article)? ");
         root-> txt = readLine(stdin);
         if(root->txt == NULL){
            exit(-1);
         }
      } 
   }else{ /* If the database exists, it starts the game from that file. */
      root = makeNode();
      if(!createList(root,f)){ /* if database is corrupts it exits, allowing user to attempt to fix database */
         freeNodes(root);
         fclose(f);
         fprintf(stderr, "FILE CORRUPT\n");
         exit(-1);
      }else{  /* if everything is valid, creates tree, traverses, updates if neccesary, saves tree to data base. */
         rewind(f);
         dbCheck(f,root);
         guess(root);
         fclose(f);
      }
   }
   f = fopen("qa.db","w");
   writeDB(root,f);
   fclose(f);
   return 0;
}
