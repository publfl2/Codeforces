#include <stdio.h>
#include <string.h>

int odd[110],even[110];
int next[100010][30];
char x[100010],y[100010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=0;i<26;i++) odd[i] = even[i] = a+1;
		
		for(int i=a;i>=1;i--)
		{
			if(i%2==0)
			{
				for(int j=0;j<26;j++) next[i][j] = odd[j];
				even[x[i]-'a'] = i;
			}
			else
			{
				for(int j=0;j<26;j++) next[i][j] = even[j];
				odd[x[i]-'a'] = i;
			}
		}
		scanf("%s",y+1);
		int b = strlen(y+1);
		for(int i=1;i<=a;i+=2)
		{
			if(x[i]==y[1])
			{
				int p = i;
				for(int j=2;j<=b;j++)
				{
					p = next[p][y[j]-'a'];
					if(p>a) goto u1;
				}
				printf("YES\n");
				goto v;
			}
		}
		u1:;
		
		for(int i=2;i<=a;i+=2)
		{
			if(x[i]==y[1])
			{
				int p = i;
				for(int j=2;j<=b;j++)
				{
					p = next[p][y[j]-'a'];
					if(p>a) goto u2;
				}
				printf("YES\n");
				goto v;
			}
		}
		u2:;
		printf("NO\n");
		v:;
	}
}