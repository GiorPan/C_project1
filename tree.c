#include "MD5.h"
#include "tree.h"

void dhmiourgia(treeptr *riza){
	*riza=NULL;
	*riza=malloc(sizeof(struct komvos));
	(*riza)->done=0;
	(*riza)->left=NULL;
	(*riza)->right=NULL;
	(*riza)->level=1;
}

void eisagwgh(treeptr* riza,treeptr* current,unsigned int *stoixeio,int* count){
	MD5_CTX context;
	unsigned int concatenation_digest[4];
	if((*current)->level == 1 &&(*current)->done == 0){
		treeptr newnode;
		newnode = malloc(sizeof(struct komvos));
		newnode->left = NULL;
		newnode->right = NULL;
		newnode->page =(*count+1);
		newnode->level = 0;
		newnode->done = 1;
		memcpy(newnode->digest,stoixeio,4*sizeof(unsigned int));
		if((*current)->left ==NULL){
			(*current)->left = newnode;
			return;
		}
		if((*current)->right==NULL){
			(*current)->right = newnode;
			(*current)->done = 1;
			MD5Init(&context);
			MD5Update(&context,(char*)(*current)->left->digest, 4* sizeof(int));
			MD5Update(&context,(char*)(*current)->right->digest, 4*sizeof(int));
			MD5Final(concatenation_digest,&context);
			memcpy((*current)->digest,concatenation_digest,4*sizeof(unsigned int));
			return;
		}
	}
	if((*riza)->done == 0){
		if((*riza)->left->done==1)
			if((*riza)->right->done ==1){
				MD5Init(&context);
				MD5Update(&context,(char*)(*riza)->left->digest,4*sizeof(int));
				MD5Update(&context,(char*)(*riza)->right->digest,4*sizeof(int));
				MD5Final(concatenation_digest,&context);
				memcpy((*riza)->digest,concatenation_digest,4*sizeof(unsigned int));
				(*riza)->done = 1;
			}
	}
	if((*riza)->done==1){
		treeptr priza,nriza;
		priza=*riza; 
		nriza = malloc(sizeof(struct komvos));
		nriza->done = 0;
		nriza->left = priza;
		nriza->right = NULL;
		int i = priza->level;
		i++;
		nriza->level = i;
		*riza = nriza;
	}
	*current = *riza;
	int lvl = (*riza)->left->level;
	while(lvl>=1){
		treeptr tmpright;
		if((*current)->left == NULL){
			tmpright=malloc(sizeof(struct komvos));
			tmpright->page = 0;
			tmpright->left =NULL;
			tmpright->right = NULL;
			tmpright->done = 0;
			tmpright->level = lvl;
			(*current)->left =tmpright; 
		}else{
			if((*current)->left->done ==0){
				tmpright=(*current)->left;
			}else if((*current)->right==NULL){
				tmpright=malloc(sizeof(struct komvos));
				tmpright->left=NULL;
				tmpright->right =NULL;
				tmpright->page = 0;
				tmpright->done = 0;
				tmpright->level = lvl;
				(*current)->right = tmpright;
			}else{
				tmpright = (*current)->right;
			}
		}
		*current = tmpright; 
		lvl--;
	}
	eisagwgh(&(*riza),&(*current),stoixeio,count); 
	return;
}

void check(treeptr* chk){
MD5_CTX context;
unsigned int con_dig[4];
	if((*chk)->level ==0 || (*chk)->level==1)
	return;
	if((*chk)->done == 0){
		if((*chk)->left->done==1){
			if((*chk)->right == NULL)
				return;
			if((*chk)->right->done == 1){
				MD5Init(&context);
				MD5Update(&context,(char*)(*chk)->left->digest,4*sizeof(int));
				MD5Update(&context,(char*)(*chk)->right->digest,4*sizeof(int));
				MD5Final(con_dig,&context);
				memcpy((*chk)->digest,con_dig,4*sizeof(unsigned int));
				(*chk)->done =1;
				return;
			}
			if((*chk)->right->done==0){
				*chk=(*chk)->right;
				check(&(*chk));
			}
		}else if((*chk)->left->done==0){
			*chk = (*chk)->left;
			check(&(*chk));
		}
	return;
	}
	return;
}

void last_check(treeptr* t_ptr){
MD5_CTX context;
unsigned int ms_dig[4];
	if((*t_ptr)->done == 1)
	return;
	else{
		if((*t_ptr)->left->done ==  0){
			*t_ptr = (*t_ptr)->left;
			last_check(&(*t_ptr));
			return;
		}
		if((*t_ptr)->left->done == 1){
			if((*t_ptr)->right == NULL){
				MD5Init(&context);
				MD5Update(&context,(char*)(*t_ptr)->left->digest,4*sizeof(int));
				MD5Final(ms_dig,&context);
				memcpy((*t_ptr)->digest,ms_dig,4*sizeof(unsigned int));
				(*t_ptr)->done = 1;
				return;
			}
			if((*t_ptr)->right->done == 0){
			*t_ptr = (*t_ptr)->right;
			last_check(&(*t_ptr));
			return;
			}
		}
	}
}

void compare(treeptr* a_ptr,treeptr* b_ptr){
	treeptr a_kid;
	treeptr b_kid;
	if(memcmp((*a_ptr)->digest,(*b_ptr)->digest,4*sizeof(unsigned int))!=0 && (*a_ptr)->level==0){
		printf("uparxei diafora sth selida %d\n",(*a_ptr)->page);
		return;
	}
	if(memcmp((*a_ptr)->digest,(*b_ptr)->digest,4*sizeof(unsigned int))!=0){
		if((*a_ptr)->left!=NULL)
		if(memcmp((*a_ptr)->left->digest,(*b_ptr)->left->digest,4*sizeof(unsigned int))!=0){
			a_kid = (*a_ptr)->left;
			b_kid = (*b_ptr)->left;
			compare(&a_kid,&b_kid);
		}
		if((*a_ptr)->right!=NULL)
		if(memcmp((*a_ptr)->right->digest,(*b_ptr)->right->digest,4*sizeof(unsigned int))!=0){
			a_kid = (*a_ptr)->right;
			b_kid = (*b_ptr)->right;
			compare(&a_kid,&b_kid); 
		}
	}
}

void katastrofh(treeptr* del){
	if(*del!=NULL){
		katastrofh(&(*del)->left);
		katastrofh(&(*del)->right);
/*printf("%d\n",(*del)->page);*/
		free(*del);
		*del = NULL;
	}
}
