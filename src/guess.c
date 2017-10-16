/*
 * Jacob Territo
 * Guessing game main
 * asgn2
 */
#include "guess.h"

int main(void){
   node* root;
   FILE *f = fopen("qa.db","r");
   if(f == NULL){
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
   }else{
      root = makeNode();
      if(!createList(root,f)){
         freeNodes(root);
         fclose(f);
         fprintf(stderr, "FILE CORRUPT\n");
         exit(-1);
        /* root = makeNode();
         printf("Unable to read database qa.db. Starting fresh.\n\nWhat is it (with article)? ");
         root->txt = getLine(stdin); */ 
      }else{
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
