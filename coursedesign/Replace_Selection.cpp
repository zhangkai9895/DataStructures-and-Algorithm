#include<stdio.h>
#include<stdlib.h>
#define w 6//�����ڴ��������Դ���ļ�¼����
#define MAXKEY 10000
#define RUNEND_SYMBOL 10000
typedef int KeyType;//�ؼ��ֵ�����Ϊ����
#define N 24


typedef struct {
	KeyType key;
}RedType;

typedef int LoserTree[w];//������ ��ȫ������ ˳��������ʽ����

typedef struct {
	RedType rec;
	KeyType key;
	int rnum;
}RedNode,WorkArea[w];

//�Ӽ�¼��ѡ����С��
void SelectMiniMax(LoserTree ls, WorkArea wa, int q) {
	int p;
	int s;
	int t;
	for (t = (w + q) / 2, p = ls[t]; t > 0; t = t / 2, p = ls[t]) {
		if (wa[p].rnum < wa[q].rnum || (wa[p].rnum == wa[q].rnum && wa[p].key < wa[q].key)) {
			s = q;
			q = ls[t]; //qָʾ�µ�ʤ����
			ls[t] = s;
		}
	}
	ls[0] = q;
}


//��w����¼���������� 
void Construct_Loser(LoserTree ls, WorkArea wa,FILE*fi) {
	int i;
	for (i = 0; i < w; ++i) {
		wa[i].rnum = 0;//��ʼ�������� ȫ��Ϊ0
		wa[i].key = 0;
		ls[i] = 0;
	}
	for (i = w - 1; i >= 0; --i) {
		fread(&wa[i].rec, sizeof(RedType), 1,fi);
		wa[i].key = wa[i].rec.key;
		wa[i].rnum = 1;//�κ�Ϊ1s
		SelectMiniMax(ls, wa, i);
	}
}

void get_run(LoserTree ls, WorkArea wa, int rc, int *rmax, FILE*fi,FILE*fo) {
	int q;
	KeyType minimax;

	while (wa[ls[0]].rnum == rc)
    {
		q = ls[0];//minimax �������е�λ��
		minimax = wa[q].key;
		fwrite(&wa[q].rec, sizeof(RedType), 1, fo);
		if (feof(fi)) {
			wa[q].rnum = *rmax + 1;
			wa[q].key = MAXKEY;
		}
		else { // �����ļ��ǿ�ʱ
		   // �������ļ�������һ��¼
			fread(&wa[q].rec, sizeof(RedType), 1, fi);
			wa[q].key = wa[q].rec.key;// ��ȡ�ؼ���
			if (wa[q].key < minimax) {
				// �¶���ļ�¼����һ�ֵ���С�ؼ��ֻ�С����������һ��
				*rmax = rc + 1;
				wa[q].rnum = *rmax;
			}
			else {
				// �¶���ļ�¼��������ǰ��
				wa[q].rnum = rc;
			}
		}
		// ѡ���µ�MINIMAX��¼
		SelectMiniMax(ls, wa, q);
	}
}

void Replace_Selection(LoserTree ls, WorkArea wa, FILE *fi, FILE *fo) {
	int rc, rmax;
	RedType j;
	j.key = RUNEND_SYMBOL;
	// ����������
	Construct_Loser(ls, wa, fi);
	rc = rmax = 1;//rcָʾ��ǰ���ɵĳ�ʼ�鲢�εĶκţ�rmaxָʾwa�йؼ���������ʼ�鲢�ε����κ�

	while (rc <= rmax) {// ��rc=rmax+1����־�����ļ����û���ѡ�����������
		// ���һ����ʼ�鲢��
		get_run(ls, wa, rc, &rmax, fi, fo);
		fwrite(&j, sizeof(RedType), 1, fo);//���ν�����־д������ļ�
		rc = wa[ls[0]].rnum;//������һ�εĶκ�
	}
}

void print(RedType t) {
	printf("%d ", t.key);
}

int main() {
	RedType a[N] = { 51,49,39,46,38,29,14,61,15,30,1,48,52,3,63,27,4,13,89,24,46,58,33,76};
	RedType b;
	FILE *fi, *fo; //��������ļ�
	LoserTree ls; // ������
	WorkArea wa; // �ڴ湤����
	int i, k;
	fo = fopen("ori.txt", "w+"); //׼���� ori �ı��ļ�����д����
	//������ a д����ļ�ori
	fwrite(a, sizeof(RedType), N, fo);
	fclose(fo); //�ر�ָ�� fo ��ʾ���ļ�
	fi = fopen("ori.txt", "r+");//׼���� ori �ı��ļ����ж�����
	printf("untoped:\n");
	for (i = 1; i <= N; i++) {
		// ���ν��ļ�ori�����ݶ��벢��ֵ��b
		fread(&b, sizeof(RedType), 1, fi);
		print(b);
	}
	printf("\n");
	rewind(fi);// ʹfi��ָ�����·��ش��ļ�ori����ʼλ�ã��Ա����¶����ڴ棬������������ļ���
	fo = fopen("out.txt", "w+");
	// ���û���ѡ���������ʼ�鲢��
	Replace_Selection(ls, wa, fi, fo);
	fclose(fo);
	fclose(fi);
	fi = fopen("out.txt", "r+");
	printf("toped segment:\n");
	do {
		k = fread(&b, sizeof(RedType), 1, fi); //�� fi ָ��ָ����ļ����������ļ�¼��ֵ�� b�����������ɹ����Ľ����ֵ�� k
		if (k == 1) {
			if (b.key == MAXKEY) {//����ֵ�������ֵʱ��������ǰ��ʼ�鲢���Ѿ����
				printf("\n\n");
				continue;
			}
			print(b);
		}
	} while (k == 1);
	system("pause");
	return 0;
}