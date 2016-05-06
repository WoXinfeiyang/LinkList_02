#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef int ElemType;
typedef int Boolean; 

/*定义节点类型*/
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;

/*定义指向节点的类型*/
typedef struct Node* LinkList; 


/*
初始化一个带头结点的链表 
*/
Boolean InitLinkList(LinkList *L){
	*L=(LinkList)malloc(sizeof(Node));
	if(!*L){
		return 0;
	}
	(*L)->next=NULL;
	return 1;
}

int LinkListLength(LinkList L){
	int i=0;
	LinkList p=L->next;
	while(p){
		++i;
		p=p->next;
	}
	return i;
}

ElemType GetElem(LinkList L,int position)
{
	LinkList p=L->next;
	int i=1;
	
	while(p&&i<position)
	{
		++i;
		p=p->next;
	}
	
	if(!p||i>position){
		return 0;
	}
	
	return p->data;
	
}

int  LoadElem(LinkList L,ElemType e)
{
	int i=0;
	LinkList p=L->next;
	while(p){
		++i;
		if(p->data==e){
			break;
		}
		p=p->next;
	}
	return i;
}

/*
函数名称： InserLinktList(LinkList *L,int position,ElemType e)
函数参数：L------------指向链表的指针,
		  position-----待插入位置1<=position<=LinkListLength,插入到第position位置之前使链表长度加1 
		  e------------待插入数据元素 

*/ 
Boolean InsertLinkList(LinkList *L,int position,ElemType e){
	int i=1;
	LinkList p=*L;
	/*p移动到position-1的位置*/
	while(p&&i<position){
		p=p->next;
		++i;
	} 
	
	if(!p||i>position){
		return 0;
	}
	
	LinkList s=(LinkList)malloc(sizeof(Node));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return 1;
} 

/*
函数名称：DeleteLinkList(LinkList *L,int position,ElemType *e)
函数参数：L-------------------指向待删除结点链表的指针,1<=position<=LinkListLength,
		  position------------待删除位置,ElemType *e) 
*/ 
Boolean DeleteLinkList(LinkList *L,int position,ElemType *e)
{
	int i=1;
	LinkList p=*L;
	/*p移动到position-1的位置*/
	while(p&&i<position){
		p=p->next;
		++i;
	}
	
	if(!p||i>position){
		return 0;
	}
	/*待删除结点*/
	LinkList q=p->next;
	e=q->data;	
	p->next=q->next; 
	free(q);
	return 1;
}


/*遍历带头结点的链表*/
void TraverseList(LinkList L){
	LinkList p=L->next;
	while(p){
		printf("%d ",p->data); 
		p=p->next;
	}
	printf("\n");
} 


int main(int argc, char *argv[]) {
	int i=0;
	ElemType e;
	LinkList L;
	InitLinkList(&L);
	printf("插入数据:\n");
	for(i=0;i<5;i++){
		InsertLinkList(&L,i+1,i);
	}
	printf("遍历数据:\n");
	TraverseList(L);
	printf("获取链表数据长度：%d\n",LinkListLength(L));
	
	i=2; 
	printf("获取第%d个元素:%d\n",i,GetElem(L,i));
	i=3;
	printf("获取元素%d在链表中的位置:%d\n",i,LoadElem(L,i));
	
	printf("删除数据:\n");
	DeleteLinkList(&L,1,&e);
	

		 
	printf("遍历数据:\n");
	TraverseList(L);
	printf("获取链表数据长度：%d\n",LinkListLength(L));	
	
	i=3;
	printf("获取元素%d在链表中的位置:%d\n",i,LoadElem(L,i));
	return 0;
}
