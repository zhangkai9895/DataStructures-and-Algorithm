#include<stdio.h>
#include<stdlib.h>

//����huffman�ڵ� ����ָ�����ҽڵ�ָ��
typedef struct hfmTreeNode {
	//��¼������ַ�
	struct hfmTreeNode *left;
	struct hfmTreeNode *right
}hfmTreeNode,*phTreeNode;


typedef struct queueNode {
	phTreeNode ptr;
	//
	struct queueNode *next;
};

//������нڵ㣬�ɶ��е����ڵ�
typedef struct queueNode {
	phTreeNode ptr;//ptrָ��
	int count;//��¼���ֵ�Ƶ��
	struct queueNode *next//ָ����һ�����нڵ�

}*ptrQueue;

//����ָ����е�ͷ�ڵ�
typedef struct hQueneNode{
	int size;//��¼�ڵ������
    ptrQueue first;

}hQueueNode;

//���г�ʼ�������ͷ�ڵ�
void initQueue(hQueueNode **hQueue) {
	*hQueue = (hQueueNode*)malloc(sizeof(hQueueNode));//����ͷ�ڵ��С�����ڴ�
	(*hQueue)->size = 0;
	(*hQueue)->first = NULL;
}


