#include<stdio.h>
#include<stdlib.h>

//HashTable ��������

//����List�� 
struct ListNode{
	int data;
	struct ListNode* next;
};

typedef struct ListNode* List;

struct HashTb {
	int tablesize;//�����Ĵ�С
	List *theLists;//��������������
};

//��ʼ��HashTable
HashTb* initTable(int tablesize) {
	HashTb* H;


	H = (HashTb*)malloc(sizeof(struct HashTb));
	H->tablesize = tablesize;
	H->theLists = (List*)malloc(sizeof(List)*H->tablesize);//��������ռ�

	for (int i = 0; i < tablesize; i++) {
		H->theLists[i] = (List)malloc(sizeof(struct ListNode));
		H->theLists[i]->next = NULL;
	}
	return H;
}

//����Hash����
typedef int Index;
Index Hash(int key,int tablesize) {
	return (key % 10);
}



List Find(int key, HashTb* H) {
	List p;
	List l;
	l = H->theLists[Hash(key, H->tablesize)];
	p = l->next;
	while (p != NULL && p->data != key) {
		p = p->next;
	}
	return p;
}
	
void Insert(int key, HashTb* H) {
		List temp;
		List pos;
		List L;

		pos = Find(key, H);
		if (pos == NULL) {
			temp = (List)malloc(sizeof(struct ListNode));
			L = H->theLists[Hash(key, H->tablesize)];
			temp->next = L->next;
			temp->data = key;
			L->next = temp;
		}
		
	
}

void Insert(int key,HashTb* H);
List Find(int key,HashTb* H);
Index Hash(int key, int tablesize);
HashTb* initTable(int tablesize);


void main() {
	HashTb* H = initTable(5);
	Insert(3, H);
	printf("%d",Find(3,H)->data);
	system("pause");
}
