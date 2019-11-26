#include<stdio.h>
#include<stdlib.h>


enum kindofEntry { Legitimate,Empty,Deleted };
//ɢ�� ���Ŷ�ַ��
struct HashEntry {
	int data;
	kindofEntry info;
};

typedef struct HashEntry Cell;//����Ϊ��Ԫ��

struct HashTb {
	int tablezize;
	Cell *theCells;

};

//��ʼ��ɢ�� ɢ����һ�鵥Ԫ�����Ϣ ��Ԫ�����Ϣ��ʼ��ΪEmpty
HashTb * initTable(int tablesize) {
	HashTb* h = (HashTb*)malloc(sizeof(struct HashTb));

	h->tablezize = tablesize;
	//���䵥Ԫ�ռ�
	h->theCells = (Cell*)malloc(sizeof(Cell)*h->tablezize);

	for (int i = 0; i < h->tablezize; i++) {
		h->theCells[i].info =Empty;
	}
	return h;
}
typedef int Index;

//��ϣ����
Index Hash(int key, int tablesize) {
	return (key%tablesize);
}

//ʹ��ƽ��̽��ɢ�з�Find()����
Index Find(int key,HashTb* h){
	Index currentPos;
	int collinum = 0;
	currentPos = Hash(key,h->tablezize);
	//����Ԫ��Ϣ��Ϊempty �� data������key
	while (h->theCells[currentPos].info != Empty && h->theCells[currentPos].data != key) {
		currentPos = 2 * ++collinum - 1;
		if (currentPos > h->tablezize) {
			currentPos -= h->tablezize;
		}
	}
	return currentPos;
}

void Insert(int key, HashTb* h) {
	Index temp;
	
	temp = Find(key,h);
	if (h->theCells[temp].info != Legitimate) {
		h->theCells[temp].info = Legitimate;
		h->theCells[temp].data = key;
	}
}

HashTb* initTable(int tablesize);
Index Find(int key, HashTb*h);
void Insert(int key, HashTb* h);
Index Hash(int key, int tablesize);

void main() {
	HashTb* h = initTable(10);
	Insert(18, h);
	printf("%d \n", h->theCells[Find(18, h)]);
	printf("%d \n", Find(18, h));
	Insert(28, h);
	printf("%d \n", h->theCells[Find(28, h)]);
	printf("%d \n", Find(28, h));
	system("pause");
}
