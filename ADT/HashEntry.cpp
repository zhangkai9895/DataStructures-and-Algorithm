#include<stdio.h>
#include<stdlib.h>


enum kindofEntry { Legitimate,Empty,Deleted };
//散列 开放定址法
struct HashEntry {
	int data;
	kindofEntry info;
};

typedef struct HashEntry Cell;//定义为单元格

struct HashTb {
	int tablezize;
	Cell *theCells;

};

//初始化散列 散列有一组单元格的信息 单元格的信息初始化为Empty
HashTb * initTable(int tablesize) {
	HashTb* h = (HashTb*)malloc(sizeof(struct HashTb));

	h->tablezize = tablesize;
	//分配单元空间
	h->theCells = (Cell*)malloc(sizeof(Cell)*h->tablezize);

	for (int i = 0; i < h->tablezize; i++) {
		h->theCells[i].info =Empty;
	}
	return h;
}
typedef int Index;

//哈希函数
Index Hash(int key, int tablesize) {
	return (key%tablesize);
}

//使用平方探测散列法Find()方法
Index Find(int key,HashTb* h){
	Index currentPos;
	int collinum = 0;
	currentPos = Hash(key,h->tablezize);
	//当单元信息不为empty 且 data不等于key
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
