//#include <stdio.h>
//#include <malloc.h>
//#include<stdlib.h>
//#define MAX_SIZE 50
//#define MAX_VERTEX_NUM 50//����ͼ����󶥵���
//int Queue[50];
//int pre = 0;
//int last = 0;
//struct EdgeNode  //����
//{
//	int adjvex;  //�ڽӵ���
//	//int indegree;
//	struct EdgeNode * next;
//};
//struct VertexNode  //ͷ���
//{
//	char data;
//	int indegree;
//	struct EdgeNode *firstEdge;
//};
//
//struct AdjList
//{
//	int verNum;
//	int ArcNum;
//	struct VertexNode vertex[MAX_VERTEX_NUM];
//};
//
//void CreateGraph(struct AdjList *adj)
//{
//	int edge;       //����
//	int vertexNum;   //������
//	int start;      //�ߵ����
//	int adjvetex;   //�ߵ��յ�
//	//char name;       
//	int i = 0;
//	struct EdgeNode *q = NULL;
//
//	printf("vexNum and edgNum��");
//	scanf("%d%d", &vertexNum, &edge);
//	adj->verNum = vertexNum;
//	adj->ArcNum = edge;
//	for (i = 1; i <= vertexNum; i++)
//	{
//		printf("Vertex[%d]��",i);
//		//getchar();
//		//scanf("%c",&name);
//		getchar();
//		adj->vertex[i].data = getchar();
//		adj->vertex[i].firstEdge = NULL;
//	}
//
//	for (i = 1; i <= edge; i++)
//	{
//		printf("Edge[%d]��", i);
//		scanf("%d%d", &start, &adjvetex);
//		q = (struct EdgeNode*)malloc(sizeof(struct EdgeNode));
//		q->adjvex = adjvetex;
//		q->next = adj->vertex[start].firstEdge;
//		adj->vertex[start].firstEdge = q;
//	}
//
//}
//
////void DisplayGraph(struct AdjList *adj)
////{
////	int i = 0;
////	int j = 0;
////	struct EdgeNode *p = NULL;
////	for (i = 1; i <= adj->verNum; i++)
////	{
////		printf("����%c�ı�Ϊ��", adj->vertex[i].data);
////		p = adj->vertex[i].firstEdge;
////		while (p != NULL)
////		{
////			printf("%d ", p->adjvex);
////			p = p->next;
////		}
////		printf("\n");
////	}
////}
//
//void CaculateIndegree(struct AdjList *adj)
//{
//	int num = adj->verNum;
//	int counter = 0;
//	int i = 0, j = 0;
//	struct EdgeNode *p = NULL;
//	for (i = 1; i <= num; i++)
//	{
//		adj->vertex[i].indegree = 0;
//		counter = 0;
//		for (j = 1; j <= num; j++)
//		{
//			if (i == j)
//				continue;
//			//   printf("ok\n");
//			//   printf("j=%d\n",j);
//			//   printf("///%d\n",adj->vertex[j].firstEdge->adjvex);
//			p = adj->vertex[j].firstEdge;
//			while (p != NULL)
//			{
//				//printf("...%d\n",adj->vertex[j].firstEdge->adjvex);
//				if (p->adjvex == i)
//					counter++;
//				//   printf("ok1\n");
//				p = p->next;
//			}
//		}
//		adj->vertex[i].indegree = counter;
//		//printf("����%c��indegree:%d\n",adj->vertex[i].data,counter);
//	}
//
//}
//int isEmpty()       //�ж϶����Ƿ�Ϊ��
//{
//	int flag = 0;
//	if (pre == last)
//		flag = 1;
//	return flag;
//}
//void enqueue(char c)    //������
//{
//	if ((pre + MAX_SIZE - last) % MAX_SIZE != MAX_SIZE)   //���в������Խ�����
//	{
//		//   printf("�����У���\n");
//		Queue[pre] = c;
//		pre++;
//	}
//}
//char dequeue()   //������
//{
//	char temp = 0;
//	if (isEmpty() != 1)
//	{
//		//printf("�����У�����\n");
//		temp = Queue[last];
//		last++;
//	}
//	return temp;
//}
//
//void topSort(struct AdjList *adj)
//{
//	int num = adj->verNum;
//	int i = 0;
//	int j = 0;
//	char test = 0;
//	struct EdgeNode *p = NULL;
//	printf("TopSort:");
//	for (i = 1; i <= num; i++)
//	{
//		if (adj->vertex[i].indegree == 0)
//			enqueue(adj->vertex[i].data);
//	}
//	//printf("isempty=%d\n",isEmpty());
//	while (isEmpty() == 0)
//	{
//		test = dequeue();
//		printf("%c ", test);
//		for (j = 1; j <= num; j++)
//		{
//			if (adj->vertex[j].data == test)
//				break;
//		}
//		p = adj->vertex[j].firstEdge;
//		while (p != NULL)
//		{
//			if (--(adj->vertex[p->adjvex].indegree) == 0)
//			{
//				enqueue(adj->vertex[p->adjvex].data);
//				//printf("%c->",test);
//			}
//			p = p->next;
//		}
//
//	}
//}
//int main()
//{
//	struct AdjList *adj = (struct AdjList*) malloc(sizeof(struct AdjList));
//	CreateGraph(adj);
//	//DisplayGraph(adj);
//	CaculateIndegree(adj);
//	topSort(adj);
//	system("pause");
//}