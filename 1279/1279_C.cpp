#include <stdio.h>

int x[100010],y[100010],check[100010];
int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=b;i++) scanf("%d",&y[i]);
		for(int i=1;i<=a;i++) check[i] = 0;
		
		int p = 0;
		int count = 0;
		long long int ans = 0;
		for(int i=1;i<=b;i++)
		{
			if(check[y[i]]==0)
			{
				while(p<a)
				{
					p++;
					check[x[p]] = 1;
					count++;
					if(x[p]==y[i])
					{
						ans += 2*count-1;
						count--;
						break;
					}
				}
			}
			else ans++,count--;
		}
		printf("%lld\n",ans);
	}
}
