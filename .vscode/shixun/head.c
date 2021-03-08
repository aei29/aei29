#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define LENGTH 30
#define ERROR 0
 
 typedef struct User_login
 {
     char name[LENGTH];
     int totalcount;
 }SDataType;

 typedef struct SListNode
 {
     SDataType data;
     struct SListNode* PNext;
 }Node,*PNode;
 void CreateList(PNode &L,char *filename)
 {
FILE *fp;
if((fp=fopen(filename,"r"))==NULL)
{
printf("文件没找到!\n");return;
}
L=(PNode)malloc(sizeof(Node));//创建头结点
PNode p=L;
while(!feof(fp))
{
PNode q=(PNode)malloc(sizeof(Node));
SDataType e;
fscanf(fp,"%d",&e);
q->data=e;p->PNext=q;p=q;
}
p->PNext=NULL;
fclose(fp);
}
int main()
{
PNode L;
CreateList(L,"user_login.txt");
PNode p=L->PNext;
while(p)
{
printf("%d\t",p->data);p=p->PNext;
}
printf("\n");
return 0;
}