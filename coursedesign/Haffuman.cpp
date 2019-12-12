//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//typedef struct {
//	int weight;//节点权值
//	int parent;//父亲 
//	int left;//左孩子
//	int right;//右孩子
//}HTNode,*HuffmanTree;
//
//typedef char ** HuffmanCode;
//
////从数组中找出权值最小的两个叶子节点
//void Select(HuffmanTree HT,int end,int*s1,int *s2){
//	int min1;
//	int min2;
//	int i = 1;
//	while (HT[i].parent!=0&&i<end){//遍历哈夫曼节点
//		i++;
//	}
//	min1 = HT[i].weight;
//	*s1 = i;
//	i++;
//	while (HT[i].parent != 0 && i < end) {//再遍历哈夫曼节点
//		i++;
//	}
//	if (HT[i].weight < min1) {
//		min2 = min1;
//		*s2 = *s1;
//		min1 = HT[i].weight;
//		*s1 = i;
//	}else{
//		min2 = HT[i].weight;
//		*s2 = i;
//	}
//	for (int j = i + 1; j < end; j++) {//将两个权值和后续节点进行比较
//		if (HT[j].parent != 0) {
//			continue;
//		}
//		if (HT[j].weight < min1) {
//			min2 = min1;
//			min1 = HT[j].weight;
//			*s2 = *s1;
//			*s1 = j;
//		}else if(HT[j].weight >= min1 && HT[j].weight < min2){
//			min2 = HT[j].weight;
//			*s2 = j;
//		}
//	}
//}
//
////构建哈夫曼树
//void creatHuffmanTree(HuffmanTree *HT,int *w,int n) {
//	if (n <= 1) {//节点数为1 哈夫曼编码为0
//		return;
//	}
//	int m = 2 * n - 1;
//	*HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));//初始化哈夫曼数组
//	HuffmanTree p = *HT;
//	//初始化哈夫曼树中所有节点
//	for (int i = 1; i <= n; i++)
//	{
//		(p + i)->weight = *(w + i - 1);
//		(p + i)->parent = 0;
//		(p + i)->left = 0;
//		(p + i)->right = 0;
//	}
//
//	//初始化除叶子节点外所有节点
//	for (int i = n + 1; i <= m; i++)
//	{
//		(p + i)->weight = 0;
//		(p + i)->parent = 0;
//		(p + i)->left = 0;
//		(p + i)->right = 0;
//	}
//	//构建哈夫曼树
//	for (int i = n + 1; i <= m; i++)
//	{
//		int s1, s2;
//		Select(*HT, i - 1, &s1, &s2);
//		(*HT)[s1].parent = (*HT)[s2].parent = i;
//		(*HT)[i].left = s1;
//		(*HT)[i].right = s2;
//		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
//	}
//
//}
////哈夫曼编码
//void HuffmanCoding(HuffmanTree HT, HuffmanCode *HC, int n) {
//	*HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
//	char *cd = (char *)malloc(n * sizeof(char)); //存放结点哈夫曼编码的字符串数组
//	cd[n - 1] = '\0';//字符串结束符
//
//	for (int i = 1; i <= n; i++) {
//		//从叶子结点出发，得到的哈夫曼编码是逆序的，需要在字符串数组中逆序存放
//		int start = n - 1;
//		//当前结点在数组中的位置
//		int c = i;
//		//当前结点的父结点在数组中的位置
//		int j = HT[i].parent;
//		// 一直寻找到根结点
//		while (j != 0) {
//			// 如果该结点是父结点的左孩子则对应路径编码为0，否则为右孩子编码为1
//			if (HT[j].left == c)
//				cd[--start] = '0';
//			else
//				cd[--start] = '1';
//			//以父结点为孩子结点，继续朝树根的方向遍历
//			c = j;
//			j = HT[j].parent;
//		}
//		//跳出循环后，cd数组中从下标 start 开始，存放的就是该结点的哈夫曼编码
//		(*HC)[i] = (char *)malloc((n - start) * sizeof(char));
//		strcpy((*HC)[i], &cd[start]);
//	}
//	//使用malloc申请的cd动态数组需要手动释放
//	free(cd);
//}
//
//void PrintHuffmanCode(HuffmanCode htable, int *w, int n)
//{
//	printf("Huffman code : \n");
//	for (int i = 1; i <= n; i++)
//		printf("%d code = %s\n", w[i - 1], htable[i]);
//}
//int main(void)
//{
//	int w[5] = { 2, 8, 7, 6, 5 };
//	int n = 5;
//	HuffmanTree htree;
//	HuffmanCode htable;
//	creatHuffmanTree(&htree, w, n);
//	HuffmanCoding(htree, &htable, n);
//	PrintHuffmanCode(htable, w, n);
//	system("pause");
//	return 0;
//	
//}