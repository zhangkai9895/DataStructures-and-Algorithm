#include <stdlib.h>;
#include<stdio.h>;

struct Node{
	int data;
	struct Node* next;//�ṹ��ָ�룬�����һ���ڵ�ĵ�ַ
}node;//����Node����

Node* initList();
void display(Node* p);


void main() {
	Node* p = initList();
	display(p);
	system("pause");
}


//��ʼ������ ��������ΪNode����ָ��
Node * initList() {
	Node *p = (Node*)malloc(sizeof(node));//����ͷ�ڵ� �����ڴ沢���ص�ַ
	Node *temp = p;
	for (int i = 1; i < 5; i++) {
		Node *a = (Node*)malloc(sizeof(node));//��������ڵ� �����ڴ沢���ص�ַ
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




