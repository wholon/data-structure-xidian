// 顺序串的模式匹配
#include <stdio.h>
#include <string.h>
#include <malloc.h>
//顺序串的结构类型定义
#define maxsize 100
typedef struct
{  
	char str[maxsize];
	int len;
} seqstring;

int Index(seqstring*, seqstring*);

int main(void)
{
	seqstring*S,*subS;
	S=(seqstring*)malloc(sizeof(seqstring));
	subS=(seqstring*)malloc(sizeof(seqstring));
	
	printf("请输入目标串S："); 
	gets(S->str);
	S->len=strlen(S->str);

	printf("请输入模式串subS："); 
	gets(subS->str);
	subS->len=strlen(subS->str);
	
	if(Index(S,subS) > 0) 
		printf("匹配成功！模式串在目标串中的位置为：%d\n", Index(S,subS));
	else
		printf("匹配失败！\n");
	return 0;
}


int Index(seqstring* seq1, seqstring* seq2)
{
	int i, j, m, k;
	m = seq1->len;
	k = seq2->len;
	for (i = 0; i < m; i++) {
		for (j = 0; j < k; j++) {
			int ti = i;
			int tj = j;
			while (seq1->str[ti] == seq2->str[tj]) {
				ti++;
				tj++;
			}
			if (tj >=k) {
				return i + 1;
			}
		}
	}
	return -1;
}
