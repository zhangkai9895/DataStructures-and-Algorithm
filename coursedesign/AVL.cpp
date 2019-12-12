//#include<stdio.h>
//#include<stdlib.h>
//
//
//
//typedef struct AvlNode* AvlTree;
//typedef struct AvlNode* position;
//����AVL���Ľڵ�
//struct AvlNode
//{
//	int data;
//	AvlTree Left;
//	AvlTree Right;
//	int height;
//};
//
//int max(int a, int b) {
//	if (a > b) {
//		return a;
//	}else
//	{
//		return b;
//	}
//}
//
//����AVL���ڵ�߶ȵĺ���
// int Height(AvlTree t) {
//	if (t == NULL) {
//		return -1;
//	}else{
//		return t->height;
//	}
//}
//
// ����ת
// position sigleRotateLeft(position k2) {
//	 position k1;
//	 k1 = k2->Left;
//	 k2->Left = k1->Right;
//	 k1->Right = k2;
//	 int a = Height(k2->Left);
//	 int b = Height(k2->Right);
//	 k2->height = max(a, b) + 1;//���½ڵ�߶���Ϣ
//	 int c = Height(k1->Left);
//	 int d = Height(k1->Right);
//	 k1->height = max(c, d) + 1;
//	 return k1;//������ת��ĸ�
// }
// position sigleRotateRight(position k1) {
//	 position k2;
//	 k2 = k1->Right;
//	 k1->Right = k2->Left;
//	 k2->Left = k1;
//	 int a = Height(k2->Left);
//	 int b = Height(k2->Right);
//	 k2->height = max(a, b) + 1;//���½ڵ�߶���Ϣ
//	 int c = Height(k1->Left);
//	 int d = Height(k1->Right);
//	 k1->height = max(c, d) + 1;
//	 return k2;
// }
//
// position DoubleRotateLeft(position k3) {
//	 k3->Left = sigleRotateRight(k3->Left);
//	 return sigleRotateLeft(k3);
// }
//
// position DoubleRotateRight(position k3) {
//	 k3->Right = sigleRotateLeft(k3->Right);
//	 return sigleRotateRight(k3);
// }
//��AVL���в���ڵ�
//AvlTree Insert(int x, AvlTree t) {
//	if (t == NULL) {
//		t = (AvlTree)malloc(sizeof(struct AvlNode));//���Ϊ���� ������
//		t->data = x;
//		t->Left = NULL;//��������Ϊ��
//		t->Right = NULL;
//		t->height = 0;
//	}else if( x<t->data){
//		t->Left = Insert(x, t->Left);//���뵽��������
//		if (Height(t->Left)-Height(t->Right)==2){//��������˽ڵ㲻����ƽ������
//			if (x < t->Left->data) {
//				t=sigleRotateLeft(t);//����
//			}else{
//				t = DoubleRotateLeft(t);//����
//			}
//		}	    
//	}else if(x>t->data){
//		t->Right = Insert(x, t->Right);
//		if (Height(t->Right) - Height(t->Left) == 2) {
//			if (x > t->Right->data) {
//      			t = sigleRotateRight(t);        //����
//			}else{
//				t = DoubleRotateRight(t); //����
//			}
//		}
//	}
//	int h1 = Height(t->Left);
//	int h2 = Height(t->Right);
//	t->height = max(h1,h2) + 1;
//	return t;
//}
//
//
//AvlTree Insert(int x, AvlTree t);
//position sigleRotateLeft(position k2);
//position sigleRotateRight(position k1);
//position DoubleRotateLeft(position k3);
//position DoubleRotateRight(position k3);
//int max(int a, int b);
//int Height(AvlTree t);
//void main() {
//	AvlTree t = (AvlTree)malloc(sizeof(struct AvlNode));
//	t->data = 5;
//	t->Left = NULL;
//	t->Right = NULL;
//	t=Insert(4, t);
//	t=Insert(3, t);
//	printf("%d",t->height);
//	system("pause");
//}