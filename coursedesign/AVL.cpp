//#include<stdio.h>
//#include<stdlib.h>
//
//
//
//typedef struct AvlNode* AvlTree;
//typedef struct AvlNode* position;
//定义AVL树的节点
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
//计算AVL树节点高度的函数
// int Height(AvlTree t) {
//	if (t == NULL) {
//		return -1;
//	}else{
//		return t->height;
//	}
//}
//
// 单旋转
// position sigleRotateLeft(position k2) {
//	 position k1;
//	 k1 = k2->Left;
//	 k2->Left = k1->Right;
//	 k1->Right = k2;
//	 int a = Height(k2->Left);
//	 int b = Height(k2->Right);
//	 k2->height = max(a, b) + 1;//更新节点高度信息
//	 int c = Height(k1->Left);
//	 int d = Height(k1->Right);
//	 k1->height = max(c, d) + 1;
//	 return k1;//返回旋转后的根
// }
// position sigleRotateRight(position k1) {
//	 position k2;
//	 k2 = k1->Right;
//	 k1->Right = k2->Left;
//	 k2->Left = k1;
//	 int a = Height(k2->Left);
//	 int b = Height(k2->Right);
//	 k2->height = max(a, b) + 1;//更新节点高度信息
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
//向AVL树中插入节点
//AvlTree Insert(int x, AvlTree t) {
//	if (t == NULL) {
//		t = (AvlTree)malloc(sizeof(struct AvlNode));//如果为空树 创建树
//		t->data = x;
//		t->Left = NULL;//左右子树为空
//		t->Right = NULL;
//		t->height = 0;
//	}else if( x<t->data){
//		t->Left = Insert(x, t->Left);//插入到左子树中
//		if (Height(t->Left)-Height(t->Right)==2){//如果插入后此节点不满足平衡条件
//			if (x < t->Left->data) {
//				t=sigleRotateLeft(t);//左左
//			}else{
//				t = DoubleRotateLeft(t);//左右
//			}
//		}	    
//	}else if(x>t->data){
//		t->Right = Insert(x, t->Right);
//		if (Height(t->Right) - Height(t->Left) == 2) {
//			if (x > t->Right->data) {
//      			t = sigleRotateRight(t);        //右右
//			}else{
//				t = DoubleRotateRight(t); //右左
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