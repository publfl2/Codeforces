#include <stdio.h>

int check[300010];
char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		for(int i=0;i<=200000;i++) check[i] = 0;
		
		int s = 100000, ans = 0;
		for(int i=1;i<=a;i++)
		{
			check[s]++;
			if(x[i]=='1') s--;
			else s++;
		}
		s-=100000;
		if(s<0) // n*s + (i-100000) == b
		{
			for(int i=0;i<=200000;i++)
			{
				if((b-i+100000)<=0 && (i-100000-b)%(-s)==0) ans += check[i];
			}
			printf("%d\n",ans);
		}
		else if(s>0)
		{
			for(int i=0;i<=200000;i++)
			{
				if((b-i+100000)>=0 && (b-i+100000)%s==0) ans += check[i];
			}
			printf("%d\n",ans);
		}
		else
		{
			for(int i=0;i<=200000;i++)
			{
				if((b-i+100000)==0)
				{
					if(check[i]>0) printf("-1\n");
					else printf("0\n");
					break;
				}
			}
		}
	}
}
