#include<stdio.h>
#define Maxsize 100
typedef struct{
	int Data[Maxsize];
	int length;
}Sqelist;
void Initelem(Sqelist*L){//参数列表：类型+变量名   Sqelist*L是把原来的顺序表地址传给函数
	L->length=0;
}
 /* void Findelme(Sqelist L//传的是结构体，用指针效率会更高){
	if(L.length==0){
	}
	for(int i=0;i<L.length-1;i++){
		printf("%d  ",L.Data[i]);
	}*/
	
void Findeleme(Sqelist*L){
	if(L->length==0){
		printf("无法查找\n");
	}
	for(int i=0;i<L->length;i++){
		printf("%d  ",L->Data[i]);
	}
}
//在表尾增加元素
int Addendeleme(Sqelist*L,int e){
	if(L->length>=Maxsize){
		printf("顺序表已满\n");
		return 0;
	}
	//在下一个空闲位置插入即length，而length-1表示最后一个有效元素
	L->Data[L->length]=e;//结构体成员必须写成L->length，而不是length
	L->length++;
	return 1;
}
//在指定位置插入元素
int Insertelme(Sqelist*L,int pos,int e){
	if(L->length>=Maxsize){//空表时也可以插入
		printf("无法插入\n");
		return 0;
	}
	if(pos>L->length+1||pos<1){//合法插入位置是1（最前面）<=pos<=L->length+1（最后面）与Maxsize无关
		printf("插入位置错误\n");
		return 0;
	}
	//先移动元素后插入新元素,不能在循环里L->length自增，会导致length多次变化
	for(int i=L->length-1;i>=pos-1;i--){
	L->Data[i+1]=L->Data[i];
	}
	//插入新元素
	L->Data[pos-1]=e;
	L->length++;
	return 1;
}
int Deletemle(Sqelist*L,int pos,int *e){//用*e带出要删除的值
	if(pos<1||pos>L->length){
		printf("位置错误\n");
		return 0;
	}
	if(L->length==0){
		return 0;
	}
	for(int i=L->length-1;i<=pos-1;i--){
		if(pos>0){
				*e=L->Data[pos-1];
				L->Data[i-1]=L->Data[i];
		}
	
	}
	L->length--;
	return 1;	
}
int main(){
	int i;
	return 0;
}



