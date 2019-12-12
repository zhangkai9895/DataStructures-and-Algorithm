//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//typedef struct {
//	int weight;//�ڵ�Ȩֵ
//	int parent;//���� 
//	int left;//����
//	int right;//�Һ���
//}HTNode,*HuffmanTree;
//
//typedef char ** HuffmanCode;
//
////���������ҳ�Ȩֵ��С������Ҷ�ӽڵ�
//void Select(HuffmanTree HT,int end,int*s1,int *s2){
//	int min1;
//	int min2;
//	int i = 1;
//	while (HT[i].parent!=0&&i<end){//�����������ڵ�
//		i++;
//	}
//	min1 = HT[i].weight;
//	*s1 = i;
//	i++;
//	while (HT[i].parent != 0 && i < end) {//�ٱ����������ڵ�
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
//	for (int j = i + 1; j < end; j++) {//������Ȩֵ�ͺ����ڵ���бȽ�
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
////������������
//void creatHuffmanTree(HuffmanTree *HT,int *w,int n) {
//	if (n <= 1) {//�ڵ���Ϊ1 ����������Ϊ0
//		return;
//	}
//	int m = 2 * n - 1;
//	*HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));//��ʼ������������
//	HuffmanTree p = *HT;
//	//��ʼ���������������нڵ�
//	for (int i = 1; i <= n; i++)
//	{
//		(p + i)->weight = *(w + i - 1);
//		(p + i)->parent = 0;
//		(p + i)->left = 0;
//		(p + i)->right = 0;
//	}
//
//	//��ʼ����Ҷ�ӽڵ������нڵ�
//	for (int i = n + 1; i <= m; i++)
//	{
//		(p + i)->weight = 0;
//		(p + i)->parent = 0;
//		(p + i)->left = 0;
//		(p + i)->right = 0;
//	}
//	//������������
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
////����������
//void HuffmanCoding(HuffmanTree HT, HuffmanCode *HC, int n) {
//	*HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
//	char *cd = (char *)malloc(n * sizeof(char)); //��Ž�������������ַ�������
//	cd[n - 1] = '\0';//�ַ���������
//
//	for (int i = 1; i <= n; i++) {
//		//��Ҷ�ӽ��������õ��Ĺ���������������ģ���Ҫ���ַ���������������
//		int start = n - 1;
//		//��ǰ����������е�λ��
//		int c = i;
//		//��ǰ���ĸ�����������е�λ��
//		int j = HT[i].parent;
//		// һֱѰ�ҵ������
//		while (j != 0) {
//			// ����ý���Ǹ������������Ӧ·������Ϊ0������Ϊ�Һ��ӱ���Ϊ1
//			if (HT[j].left == c)
//				cd[--start] = '0';
//			else
//				cd[--start] = '1';
//			//�Ը����Ϊ���ӽ�㣬�����������ķ������
//			c = j;
//			j = HT[j].parent;
//		}
//		//����ѭ����cd�����д��±� start ��ʼ����ŵľ��Ǹý��Ĺ���������
//		(*HC)[i] = (char *)malloc((n - start) * sizeof(char));
//		strcpy((*HC)[i], &cd[start]);
//	}
//	//ʹ��malloc�����cd��̬������Ҫ�ֶ��ͷ�
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