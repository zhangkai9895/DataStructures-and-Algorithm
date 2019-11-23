#include <stdlib.h>;
#include<stdio.h>;

struct Node{
	int data;
	struct Node* next;//结构体指针，存放下一个节点的地址
}node;//声明Node变量

Node* initList();
void display(Node* p);


void main() {
	Node* p = initList();
	display(p);
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

void isEmpty(Node* p) {
	if (p->next == NULL) {
		printf("empty list");
	}
	else {
		printf("not empty");
	}
}

Node* find(Node* p,int data) {
	Node* temp = p;
	
}




