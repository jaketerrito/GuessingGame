/*
 * Jacob Territo
 * helper functions
 * asgn2
 */

#include "helper.h"

char* readLine(FILE* file)
{
   static int SIZE = 32;
   char* string,*guard;
   char temp;
   int count = 0;
   temp = (char)fgetc(file);
   if(temp == EOF){
       string = NULL;
       return string;
   }
   guard = malloc(sizeof(char));
   if(guard == NULL){
      fprintf(stderr,"readLine: OUT OF MEMORY");
      exit(-1);
   }
   string = guard;
   string[0] = '\0';
   while(temp != '\n' && temp != EOF){ 
      if(count%SIZE == 0){
         guard = realloc(string,sizeof(char)*(SIZE+1+count));
         if(guard == NULL){
            fprintf(stderr,"readLine: OUT OF MEMORY");
            exit(-1);
         }
         string = guard;
      }
      string[count++] = temp;
      temp = (char)fgetc(file);   
   }
   string[count] = '\0';
   return string;
}

int yesNo()
{
   char* string = readLine(stdin);
   if(string == NULL){
      exit(-1);
   }
   if(string[0] == '\0'){
      free(string);
      return 2;
   }
   if(string[0] == 'y' || string[0] == 'Y'){
      free(string);
      return 1;
   }
   free(string);
   return 0;
}

