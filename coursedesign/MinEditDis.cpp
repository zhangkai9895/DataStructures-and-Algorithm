#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*�ݹ����༭���� ɾ�����滻������ (i��,j��)*/
int dis(const char *s,const char *t,int j,int i){
	int a,b,c,min;
	if(i>0 && j>0){
		a=t[i-1]==s[j-1]?dis(s,t,j-1,i-1):dis(s,t,j-1,i-1)+1;
		b=dis(s,t,j,i-1)+1;
		c=dis(s,t,j-1,i)+1;	
		min=a>b?b:a;
		return min>c?c:min;
	}else if(i==0 && j==0){
		return t[0]==s[0]?0:1;
	}else if(i==0){
		return j;
	}else if(j==0){
		return i;
	}
}

void main(){
	const char *s = "addd";
	const char *t = "acxx";
	printf("\n\n%s��%s֮��ľ���Ϊ��%d\n\n",s,t,dis(s,t,strlen(s),strlen(t)));
	system("pause");
}