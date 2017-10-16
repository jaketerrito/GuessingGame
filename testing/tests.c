/*
 * Jacob Territo
 * Unit tests for guess.c and functions.
 * asgn2
 */

#include "guess.h"

void testMN_1(){
   node* root = makeNode(); 
   printf("testMN_1:\n"); 
   root->left = makeNode();
   root->right = makeNode();
   root->left->txt = "YOLO";
   if(strcmp(root->left->txt,"YOLO") == 0 && (root->right->right) == NULL){
      printf("testMN_1 passed.\n");
   }else{
      printf("FAILED testMN_1.\n");
   }
}

void testAG_1(){
   node* root = makeNode();
   printf("testAG_1:\n");
   root->txt = "Cat";
   addGuess(root);
   printf("Original: %s\n",root->txt);
   printf("Left: %s\n",root->left->txt);
   printf("Right: %s\n",root->right->txt);
   printf("Verify this is correct.\n");
}

void testCL_1(){
   node* root = makeNode();
   FILE *f = fopen("testCL_1.txt","r");
   printf("testCL_1:\n");
   createList(root,f);
   f = fopen("testCL_1_new.txt","w");
   writeDB(root,f);
   printf("Verify this with:\ndiff testCL_1.txt testCL_1_new.txt\n");
}

void testWDB_1(){
   node* root = makeNode();
   FILE* t = fopen("testWDB_word.txt","r");
   FILE *f = fopen("testWDB_1.txt","w");
   printf("testWDB_1:\n");
   root->txt = readLine(t);
   addGuess(root);
   writeDB(root, f);
   printf("Verify this is correct in testWDB_1.txt\n");
}

void testWDB_2(){
   node* root = makeNode();
   FILE* t = fopen("testWDB_word.txt","r"); 
   FILE *f = fopen("testWDB_2.txt","w");
   printf("testWDB_2:\n");
   root->txt = readLine(t);
   addGuess(root);
   addGuess(root->left);
   addGuess(root->right);
   writeDB(root, f);
   printf("Verify this is correct in testWDB_2.txt\n");
}

int main(void)
{
   testMN_1();
   testAG_1();
   testWDB_2();
   testCL_1();
   return 1;
}
