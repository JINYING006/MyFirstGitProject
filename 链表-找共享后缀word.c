 #include <stdio.h>
 #include <stdlib.h>
 
 // 链表节点结构
 typedef struct Node {
     char data;
     struct Node *next;
 } Node;
 
 // 计算链表长度
 int getLength(Node *head) {
     int len = 0;
  // 头结点不计入长度
     Node *p = head->next;
     while (p != NULL) {
         len++;
         p = p->next;
     }
     return len;
 }
 
 // 查找共同后缀的起始节点
 Node* findCommonSuffix(Node *str1, Node *str2) {
     // 1. 计算两个链表的长度
     int len1 = getLength(str1);
     int len2 = getLength(str2);
     
     Node *p = str1->next;  // 指向str1的第一个数据节点
     Node *q = str2->next;  // 指向str2的第一个数据节点
     
     // 2. 让较长链表的指针先移动长度差步
     if (len1 > len2) {
         for (int i = 0; i < len1 - len2; i++) {
             p = p->next;
         }
     } else if (len2 > len1) {
         for (int i = 0; i < len2 - len1; i++) {
             q = q->next;
         }
     }
     
     // 3. 同步移动指针，直到找到相同节点
     while (p != NULL && q != NULL && p != q) {
         p = p->next;
         q = q->next;
     }
     
     // 返回共同后缀的起始节点（若没有则返回NULL）
     return p;
 }
 
 // 测试用例（可忽略）
 int main() {
     // 构建共享后缀的链表
     Node *str1 = (Node*)malloc(sizeof(Node));
     Node *str2 = (Node*)malloc(sizeof(Node));
     str1->next = NULL;
     str2->next = NULL;
     
     // 共享后缀节点：i -> n -> g
     Node *g = (Node*)malloc(sizeof(Node));
     g->data = 'g'; g->next = NULL;
     Node *n = (Node*)malloc(sizeof(Node));
     n->data = 'n'; n->next = g;
     Node *i = (Node*)malloc(sizeof(Node));
     i->data = 'i'; i->next = n;
     
     // str1: l -> o -> a -> d -> i -> n -> g
     Node *d = (Node*)malloc(sizeof(Node));
     d->data = 'd'; d->next = i;
     Node *a = (Node*)malloc(sizeof(Node));
     a->data = 'a'; a->next = d;
     Node *o = (Node*)malloc(sizeof(Node));
     o->data = 'o'; o->next = a;
     Node *l = (Node*)malloc(sizeof(Node));
     l->data = 'l'; l->next = o;
     str1->next = l;
     
     // str2: b -> e -> i -> n -> g
     Node *e = (Node*)malloc(sizeof(Node));
     e->data = 'e'; e->next = i;
     Node *b = (Node*)malloc(sizeof(Node));
     b->data = 'b'; b->next = e;
     str2->next = b;
     
     // 查找共同后缀起始节点
     Node *common = findCommonSuffix(str1, str2);
     if (common != NULL) {
         printf("共同后缀起始节点的data值：%c\n", common->data);
     } else {
         printf("没有共同后缀\n");
     }
     
     return 0;
 }
