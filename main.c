#include "tree.h"
#include "MD5.h"

int main(int argc, char *argv[]){
FILE *fp1,*fp2;
size_t read;
int page_size,counter =0,rep,tree_fan_out;
page_size=atoi(argv[3]);
char buffer[page_size];
size_t buffsize = sizeof(buffer);
unsigned int mess_dig[4],mess2_dig[4];
MD5_CTX context;
treeptr riz1,cur1,riz2,cur2,elegxos,del1,del2;

tree_fan_out=atoi(argv[4]); /*den katafera na to ulopoihsw me >2*/

fp1 = fopen(argv[1],"rb");
if(fp1 == NULL){
	perror("to prwto arxeio den anoixe");
	return 1;
}
dhmiourgia(&riz1);
cur1 = riz1;
do{
	read = fread(buffer,1,sizeof(buffer),fp1);
	if(read<buffsize)
		memset(buffer+read,0,buffsize -read);
	MD5Init(&context);
	MD5Update(&context,buffer,strlen(buffer));
	MD5Final(mess_dig,&context);
	eisagwgh(&riz1,&cur1,mess_dig,&counter);
	for(rep=0;rep< (riz1->level);rep++){
		elegxos = riz1;
		check(&elegxos);
	}
	counter++;
}while(read == buffsize);
if(ferror(fp1))
	perror("parousiasthke sfalma sthn anagnwsh tou prwtou arxeiou");
fclose(fp1);
for(rep=0;rep< (riz1->level);rep++){
	elegxos = riz1;
	last_check(&elegxos);
	elegxos = riz1;
	check(&elegxos);
}
fp2 = fopen(argv[2],"rb");
if(fp2 == NULL){
	perror("to deutero arxeio den anoixe");
	return 1;
}
dhmiourgia(&riz2);
cur2 = riz2;
counter = 0;
do{
	read = fread(buffer,1,sizeof(buffer),fp2);
	if(read<buffsize)
		memset(buffer+read,0,buffsize-read);
	MD5Init(&context);
	MD5Update(&context,buffer,strlen(buffer));
	MD5Final(mess2_dig,&context);
	eisagwgh(&riz2,&cur2,mess2_dig,&counter);
	for(rep=0;rep < (riz2->level);rep++){
		elegxos = riz2;
		check(&elegxos);
	}
	counter++;
}while(read == buffsize);
if(ferror(fp2))
	perror("parousiasthke sfalma sthn anagnwsh tou deuterou arxeiou");
fclose(fp2);
for(rep=0;rep< (riz2->level);rep++){
	elegxos = riz2;
	last_check(&elegxos);
	elegxos = riz2;
	check(&elegxos);
}
if(memcmp(riz1->digest,riz2->digest,4*sizeof(unsigned int))==0)
printf("ta arxeia einai idia\n");
del1 =riz1;
del2=riz2;
compare(&riz1,&riz2);
katastrofh(&del1);
katastrofh(&del2);
return 0;
}
