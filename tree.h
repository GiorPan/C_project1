#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct komvos *treeptr;

typedef struct komvos{
unsigned int digest[4];
int done,page,level;
treeptr left,right;
}komvos;


void dhmiourgia(treeptr* riza);
void eisagwgh(treeptr* riza,treeptr* current,unsigned int *stoixeio,int *count);
void check(treeptr *chk);
void last_check(treeptr* t_ptr);
void compare(treeptr* a_ptr,treeptr* b_ptr);
void katastrofh(treeptr* del);
