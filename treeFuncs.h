/*
 * Jacob Territo
 * Header for tree functions
 * asgn2
 */

#ifndef TREEFUNCS_H
#define TREEFUNCS_H
#include "helper.h"
typedef struct data node;
struct data{
   node *right;
   node *left;
   char* txt;
};
node* makeNode();
void addGuess(node* original);
int createList(node* root,FILE* f);
void writeDB(node* root, FILE* f);
void guess(node* root);
void freeNodes(node* root);
void dbCheck(FILE* f,node* root);
#endif
