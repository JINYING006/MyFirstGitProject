#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node*link;
}Node;

int FindNodeFS(Node*list,int k){
	//检查链表为空或者不合法情况
	if(list==NULL||k<=0){
		return 0;
	}
	Node*fast=list->link;
	Node*slow=list->link;
	//让快指针先走K步
	for(int i=0;i<k;i++){
		//链表长度不足K
		if(fast==NULL){
			return 0;
		}
		fast=fast->link;
	}//快慢指针同时移动，直到快指针走到NULL
	while(fast!=NULL){
		fast=fast->link;
		slow=slow->link;
	}	
	printf("倒数第%d个节点值为%d\n",k,slow->data);
	return 1;
}

//测试
int main(){
    Node*list=(Node*)malloc(sizeof(Node));
    list->link=NULL;
    Node*p=list;
    for(int i=1;i<=5;i++){
		Node*newNode=(Node*)malloc(sizeof(Node));
		newNode->data=i;
		newNode->link=NULL;
		p->link=newNode;
		p=newNode;//P移动到新的尾部节点
	}
	FindNodeFS(list,2);
	return 0;
}
