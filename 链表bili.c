#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;

typedef struct node{
	Elemtype data;
	struct node*next;
}Node;
//初始化
Node*Initlist(){
	Node*head=(Node*)malloc(sizeof(Node));
	head->data=0;
	head->next=NULL;
	return head;
}
//单链表-头插法（有数据时插入要注意顺序，先用新节点指向头节点指向的数据域，再用头节点指向新节点位置
int Inserthead(Node*L,Elemtype e){
	Node*p=(Node*)malloc(sizeof(Node));//在创建个新节点
	p->data=e;
	p->next=L->next;
	L->next=p;
	return 1;
}
//遍历链表
void listNode(Node*L){
	Node*p=L->next;//将整个链表付给p指针
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
//尾插法(关键：找尾节点地址)
Node*get_tail(Node*L){
	Node*p=L;
	while(p->next!=NULL){
		p=p->next;
	}
	return p;
}//
 Node* Insertend(Node*tail,Elemtype e){//传入的节点是尾节点 
 	 Node *p=(Node *)malloc(sizeof(Node));
 	 p->data=e;
 	 tail->next=p;
 	 p->next=NULL;
 	 return p;//新尾节点,返回类型是Node*
 }
 //在指定位置插入
int insert(Node*L,int pos,Elemtype e){
	//用来保存插入位置的前一个节点
	Node *p=L;
	int i=0;
	//遍历链表找到插入位置的前一个节点
	while(i<pos-1){
		p=p->next;
		i++;
		if(p==NULL){
			return 0;
		}
	}
	//要插入的新节点
	Node*q=(Node*)malloc(sizeof(Node));
	q->data=e;
	q->next=p->next;
	p->next=q;
	return 1;	
}  
//删除指定节点
int deletnode(Node*L,int pos){
	int i=0;
	Node*p=L;
	//遍历链表找到前节点
	while(i<pos-1){
		p=p->next;
		i++;
		if(p==NULL){
			return 0;
		}
	}
	if(p->next==NULL){
		printf("false\n");
		return 0;
	}
	//q指向要删除的节点
	Node*q=p->next;
	//让要删除节点的前驱指向要删除的后继
	p->next=q->next;
	//释放要删除节点的内存空间
	free(q);
	return 1;
}
//单链表获取链表长度
int lengthnode(Node*L){
	Node*p=L;
	int len=0;
	while(p->next!=NULL){
		p=p->next;
		len++;
	}
	return len;
}
//释放链表  指针P指向头节点后的第一个节点->判断指针p是否指向空节点->如果P不为空，用指针p记录指针p后继节点
void freelist(Node*L){
	Node*p=L->next;//L是头节点
	Node* q;
	while(p!=NULL){
		q=p->next;
		free(p);
		p=q; 	
	}
	L->next=NULL;
	
}
int main(){
	Node*list=Initlist();
	Inserthead(list,10);
	Inserthead(list,20);
	listNode(list);
	Node*tail=get_tail(list);
	tail=Insertend(tail,18);
	tail=Insertend(tail,29);
	listNode(list);
	insert(list,3,67);
	listNode(list);
	deletnode(list,3);
	listNode(list);
	printf("%d\n",lengthnode(list));
	freelist(list);
	printf("%d\n",lengthnode(list));
	return 0;
}

 

