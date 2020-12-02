// delete substring
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// 顺序串的结构类型定义
#define MAXSIZE 100

typedef struct
{
	char str[MAXSIZE];
	int len;
} seqstring;

void strPut(seqstring*);
void strDelete(seqstring *, int, int);
void gets(char []);

int main(void)
{
	seqstring * S;
	int i, m;
	S = (seqstring *)malloc(sizeof(seqstring *));
	printf("请输入字符串：\n");
	gets(S->str);
	S->len = strlen(S->str);
	printf("输入的字符串为：");
	strPut(S);
	printf("输入字符串的长度为：%d \n", S->len);
	printf("请输入删除的开始位置：");
	scanf("%d", &i);
	printf("请输入删除的字符个数：");
	scanf("%d", &m);
	strDelete(S, i, m);
	printf("删除子串后的字符串为：\n");
	strPut(S);
	return 0;
}

void strPut(seqstring * seqstring)
{
	int i;
	for (i = 0; i < MAXSIZE; i++) {
		if ((seqstring->str)[i] == '\0') {
			break;
		} else {
			printf("%c", (seqstring->str)[i]);
		}
	}
	printf("\n");
}

void strDelete(seqstring * seqstring, int i, int m)
{
	int e = i + m;
	int slen = seqstring->len;
	if (e > slen) {
		e = slen;
		for (i--; i < e; i++) {
			seqstring->str[i] = seqstring->str[e];
		}
	} else {	
		for (i--,e--; e <= slen; i++, e++) {
			seqstring->str[i] = seqstring->str[e];
		}
	}
}
