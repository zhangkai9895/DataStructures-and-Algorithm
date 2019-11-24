#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
}node;
typedef struct Node* stack;//type���� ��Nodeָ���ַ����Ϊstack

//�ж��Ƿ�Ϊ��ջ
int isEmpty(stack s) {
	return s->next == NULL;
}

//������ջ
stack  CreateStack() {
	stack s = (stack)malloc(sizeof(node));
	if (s == NULL) {
		printf("out of space");
	}
	s->next = NULL;
	return s;
}

void MakeEmpety(){
}

//ѹջ����
void Push(stack s,int data) {
	stack temp = (stack)malloc(sizeof(node));
	if (temp == NULL) {
		printf("out of space");
	}
	else
	{
		temp->data = data;
		temp->next = s->next;
		s->next = temp;
	}
}
void Pop(stack s) {
	stack temp = (stack)malloc(sizeof(node));
	if (isEmpty(s)) {
		printf("empty stack");
	}
	else {
		temp = s->next;
		s->next = s->next->next;
		free(temp);
	}
}

void Display(stack s) {
	stack temp = (stack)malloc(sizeof(node));
	temp = s->next;
	while (temp!=NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

stack CreateStack();
void Push(stack s,int data);
void Pop(stack s);
void Display(stack s);




int main() {
	stack s = CreateStack();
	Push(s, 1);
	Push(s, 2);
	Push(s, 3);
	Push(s, 4);
	Push(s, 5);
	Display(s);
	Pop(s);
	printf("\n");
	Display(s);
	system("pause");
	return 0;
}