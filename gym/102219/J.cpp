#include <stdio.h>
#include <string.h>
#include <algorithm>

int cmp[10][10];
char x[10],y[10];
int main()
{
	for(int i=1;i<=5;i++)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		if(x[2]=='>')
		{
			cmp[x[1]-'A'][x[3]-'A'] = -1;
			cmp[x[3]-'A'][x[1]-'A'] = 1;
		}
		else if(x[2]=='<')
		{
			cmp[x[1]-'A'][x[3]-'A'] = 1;
			cmp[x[3]-'A'][x[1]-'A'] = -1;
		}
	}
	for(int i=1;i<=5;i++) y[i] = 'A'+i-1;
	do{
		for(int i=1;i<=5;i++)
		{
			for(int j=i+1;j<=5;j++)
			{
				if(cmp[y[i]-'A'][y[j]-'A']==-1) goto u;
			}
		}
		for(int i=1;i<=5;i++) printf("%c",y[i]);
		return 0;
		u:;
	}while(std::next_permutation(y+1,y+6));
	printf("impossible");
}
