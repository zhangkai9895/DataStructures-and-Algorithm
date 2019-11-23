#include <stdlib.h>;
#include<stdio.h>;

struct Node{
	int data;
	struct Node* next;//结构体指针，存放下一个节点的地址
}node;//声明Node变量

Node* initList();
void display(Node* p);
Node *find(Node*p,int data);
void isEmpty(Node *p);
void Delete(Node*p, int data);
void DeleteList(Node* p);



void main() {
	Node* p = initList();
	display(p);
	printf("\n");
	find(p,2);
	isEmpty(p);
	printf("\n");
	Delete(p,2);
	display(p);
	printf("\n");
	DeleteList(p);
	isEmpty(p);
	system("pause");

}


//初始化链表 返回类型为Node类型指针
Node * initList() {
	Node *p = (Node*)malloc(sizeof(node));//创建头节点 分配内存并返回地址
	Node *temp = p;
	for (int i = 1; i < 5; i++) {
		Node *a = (Node*)malloc(sizeof(node));//创建链表节点 分配内存并返回地址
		a->data = i;
		a->next = NULL;
		temp->next = a;
		temp = temp->next;
	}
	return p;
}

void display(Node* p){
	Node* temp = p;
	temp = p->next;
	while (temp) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void insert(Node *p,int data, int position) {
	Node* temp = p;
	for (int i = 1; i < position; i++) {
		if (temp->next == NULL) {
			printf("wrong place");
			return ;
		}
		temp = temp->next;
	}
	Node *c = (Node*)malloc(sizeof(node));
	c->data = data;
	c->next = temp->next;
	temp->next = c;
}
//判断是否为空
void isEmpty(Node* p) {
	//头节点下一个节点为空 判断链表为空链表
	if (p->next == NULL) {
		printf("empty list");
	}
	else {
		printf("not empty");
	}
}

//判断当前节点是否为链表的末尾
int isLast(Node* temp,Node*p) {
	return temp->next == NULL;
}

//find方法 查找链表中某个元素位置
Node* find(Node* p,int data) {
	Node* temp = p->next;//定义当下指针 为header节点下一个元素 从头开始遍历
	while (temp!=NULL&&temp->data!=data)
	{
		temp = temp->next;//使用指针访问下一个元素
	}
	return temp;
}
//查找前置元素方法
Node* FindPrevious(Node* p, int data) {
	Node* temp = p;//当前指针
	while (temp != NULL && temp->next->data != data) {
		temp = temp->next;
	}
	return temp;
}

//删除链表中某个元素 
void Delete(Node* p,int data) {
	Node* c;
	Node* temp;
	//找到前驱元 
	c = FindPrevious(p, data);
	if (!isLast(c,p)) {
		temp = c->next;
		c->next = temp->next;
		free(temp);
	}
}

void DeleteList(Node *p) {
	Node* c;
	Node* temp;
	//头节点处理
	c = p->next;
	p->next = NULL;
	while (c != NULL) {
		temp = c->next;
		free(c);
		c = temp;
		
	}
}




