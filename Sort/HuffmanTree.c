#include<stdio.h>
#include<stdlib.h>

//定义huffman节点 设置指向左右节点指针
typedef struct hfmTreeNode {
	//记录储存的字符
	struct hfmTreeNode *left;
	struct hfmTreeNode *right
}hfmTreeNode,*phTreeNode;


typedef struct queueNode {
	phTreeNode ptr;
	//
	struct queueNode *next;
};

//定义队列节点，由队列弹出节点
typedef struct queueNode {
	phTreeNode ptr;//ptr指针
	int count;//记录出现的频次
	struct queueNode *next//指向下一个队列节点

}*ptrQueue;

//定义指向队列的头节点
typedef struct hQueneNode{
	int size;//记录节点的数量
    ptrQueue first;

}hQueueNode;

//队列初始化，添加头节点
void initQueue(hQueueNode **hQueue) {
	*hQueue = (hQueueNode*)malloc(sizeof(hQueueNode));//根据头节点大小分配内存
	(*hQueue)->size = 0;
	(*hQueue)->first = NULL;
}


