/*
 * Jacob Territo
 * BSTree functions
 * asgn2
 */

#include "treeFuncs.h"

node* makeNode()
{
   node* guard;
   guard = malloc(sizeof(node));
   if(guard == NULL){
      fprintf(stderr,"makeNode: OUT OF MEMORY\n");
      exit(-1);
   }
   guard->txt = NULL;
   guard->right = NULL;
   guard->left = NULL;
   return guard;
}

void guess(node* root)
{
   int temp;
   if(root->left == NULL){
      printf("Is it %s? ",root->txt);
      temp = yesNo();
      while(temp == 2){
         printf("An empty response is not acceptable.  Please answer again.");
         printf("\nIs it %s? ",root->txt);
         temp = yesNo();
      }
      if(temp == 1){
         printf("\nMy, am I clever. :)\nThanks for playing.\n\n");
         return;
      }
      addGuess(root);
      return;
   }else{
      printf("%s ",root->txt);
      temp = yesNo();
      while(temp == 2){
         printf("An empty response is not acceptable.  Please answer again.");
         printf("\n%s ",root->txt);
         temp = yesNo();
      }
      if(temp == 1){
         guess(root->left);
         return;
      }else{
         guess(root->right);
      }
   }
}

void addGuess(node* original)
{
   int temp;
   node* new,* old;
   new = makeNode();
   old = makeNode();
   old->txt = original->txt;
   printf("\nHow disappointing.\nWhat is it (with article)? ");
   new->txt = readLine(stdin);
   if(new->txt == NULL){
      exit(-1);
   }
   while(new->txt[0] == '\0'){
      free(new->txt);
      printf("An empty response is not acceptable.  Please answer again.");
      printf("\nHow disappointing.\nWhat is it (with article)? ");
      new->txt = readLine(stdin);
      if(new->txt == NULL){
         exit(-1);
      }
   }

   printf("What is a yes/no question that will distinguish %s from %s?\n? ",new->txt,old->txt);
   original->txt = readLine(stdin);
   if(original->txt == NULL){
      exit(-1);
   }
   while(original->txt[0] == '\0'){
      free(original->txt);
      printf("An empty response is not acceptable.  Please answer again.");
      printf("\nWhat is a yes/no question that will distinguish %s from %s?\n? ",new->txt,old->txt);
      original->txt = readLine(stdin);
      if(original->txt == NULL){
         exit(-1);
      }
   }  

   printf("\nWhat is the answer to the question for %s? ", new->txt);
   temp = yesNo();
   while(temp == 2){
      printf("An empty response is not acceptable.  Please answer again.");
      printf("\nWhat is the answer to the question for %s? ", new->txt);
      temp = yesNo();
   }
   if(temp == 1){
      original->left = new;
      original->right = old;
   }else{
      original-> right = new;
      original-> left = old;
   }
   printf("\nI'll get it next time, I'm sure.\nThanks for playing.\n\n");
}

void dbCheck(FILE *f,node* root)
{
   int count = 0;
   char* test = readLine(f);
   while(test != NULL){
      free(test);
      count++;
      test = readLine(f);
   }
   free(test);
   if(count%2 == 0){
      freeNodes(root);
      fclose(f);
      fprintf(stderr,"FILE CORRUPT\n");
      exit(-1);
   }
   rewind(f);
}

int createList(node* root,FILE *f)
{
   int ret = 1;
   char* line;
   char status = fgetc(f);
   if(status != '0' && status != '1'){
      return 0;
   }
   line = readLine(f);
   if(line == NULL){
      return ret;
   }
   root->txt = line;
   if(status == '0'){
      root->left = makeNode();
      root->right = makeNode();
      if(!createList(root->left,f)){
         ret = 0;
      }
      if(!createList(root->right,f)){
         ret = 0;
      }
   }
   return ret;
}

void writeDB(node* root, FILE *f)
{ 
   if(root->left == NULL){
      fprintf(f,"1%s\n",root->txt);
      free(root->txt);
      free(root);
   }else{
      fprintf(f,"0%s\n",root->txt);
      writeDB(root->left,f);
      writeDB(root->right,f);
      free(root->txt);
      free(root);
   }
}

void freeNodes(node* root)
{
   if(root->txt == NULL){
      free(root);
      return;
   }
   if(root->left == NULL){
      free(root->txt);
      free(root);
   }else{
      freeNodes(root->left);
      freeNodes(root->right);
      free(root->txt);
      free(root);
   }
}
