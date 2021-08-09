#include <stdio.h>
#include <string.h>

char x[100010];
int check[100010],check2[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		
		for(int i=0;i<=25;i++) check[i] = check2[i] = 0;
		for(int i=1;i<=a;i++) check2[x[i]-'a'] = 1;
		
		for(int i=1;i<=a;i++) if(x[i]!=x[i+1] &&x[i]!=x[i-1]) check[x[i]-'a'] = 1;
		
		for(int i=0;i<26;i++) if(check[i]==1 && check2[i]==1) printf("%c",i+'a');
		printf("\n");
	}
}
