#include <stdlib.h>;
#include<stdio.h>;

struct Node{
	int data;
	struct Node* next;//�ṹ��ָ�룬�����һ���ڵ�ĵ�ַ
}node;//����Node����

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
//�ж��Ƿ�Ϊ��
void isEmpty(Node* p) {
	//ͷ�ڵ���һ���ڵ�Ϊ�� �ж�����Ϊ������
	if (p->next == NULL) {
		printf("empty list");
	}
	else {
		printf("not empty");
	}
}

//�жϵ�ǰ�ڵ��Ƿ�Ϊ�����ĩβ
int isLast(Node* temp,Node*p) {
	return temp->next == NULL;
}

//find���� ����������ĳ��Ԫ��λ��
Node* find(Node* p,int data) {
	Node* temp = p->next;//���嵱��ָ�� Ϊheader�ڵ���һ��Ԫ�� ��ͷ��ʼ����
	while (temp!=NULL&&temp->data!=data)
	{
		temp = temp->next;//ʹ��ָ�������һ��Ԫ��
	}
	return temp;
}
//����ǰ��Ԫ�ط���
Node* FindPrevious(Node* p, int data) {
	Node* temp = p;//��ǰָ��
	while (temp != NULL && temp->next->data != data) {
		temp = temp->next;
	}
	return temp;
}

//ɾ��������ĳ��Ԫ�� 
void Delete(Node* p,int data) {
	Node* c;
	Node* temp;
	//�ҵ�ǰ��Ԫ 
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
	//ͷ�ڵ㴦��
	c = p->next;
	p->next = NULL;
	while (c != NULL) {
		temp = c->next;
		free(c);
		c = temp;
		
	}
}




