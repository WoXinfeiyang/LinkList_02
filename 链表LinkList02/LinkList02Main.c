#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef int ElemType;
typedef int Boolean; 

/*����ڵ�����*/
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;

/*����ָ��ڵ������*/
typedef struct Node* LinkList; 


/*
��ʼ��һ����ͷ�������� 
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
�������ƣ� InserLinktList(LinkList *L,int position,ElemType e)
����������L------------ָ�������ָ��,
		  position-----������λ��1<=position<=LinkListLength,���뵽��positionλ��֮ǰʹ�����ȼ�1 
		  e------------����������Ԫ�� 

*/ 
Boolean InsertLinkList(LinkList *L,int position,ElemType e){
	int i=1;
	LinkList p=*L;
	/*p�ƶ���position-1��λ��*/
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
�������ƣ�DeleteLinkList(LinkList *L,int position,ElemType *e)
����������L-------------------ָ���ɾ����������ָ��,1<=position<=LinkListLength,
		  position------------��ɾ��λ��,ElemType *e) 
*/ 
Boolean DeleteLinkList(LinkList *L,int position,ElemType *e)
{
	int i=1;
	LinkList p=*L;
	/*p�ƶ���position-1��λ��*/
	while(p&&i<position){
		p=p->next;
		++i;
	}
	
	if(!p||i>position){
		return 0;
	}
	/*��ɾ�����*/
	LinkList q=p->next;
	e=q->data;	
	p->next=q->next; 
	free(q);
	return 1;
}


/*������ͷ��������*/
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
	printf("��������:\n");
	for(i=0;i<5;i++){
		InsertLinkList(&L,i+1,i);
	}
	printf("��������:\n");
	TraverseList(L);
	printf("��ȡ�������ݳ��ȣ�%d\n",LinkListLength(L));
	
	i=2; 
	printf("��ȡ��%d��Ԫ��:%d\n",i,GetElem(L,i));
	i=3;
	printf("��ȡԪ��%d�������е�λ��:%d\n",i,LoadElem(L,i));
	
	printf("ɾ������:\n");
	DeleteLinkList(&L,1,&e);
	

		 
	printf("��������:\n");
	TraverseList(L);
	printf("��ȡ�������ݳ��ȣ�%d\n",LinkListLength(L));	
	
	i=3;
	printf("��ȡԪ��%d�������е�λ��:%d\n",i,LoadElem(L,i));
	return 0;
}
