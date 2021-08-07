#include <stdio.h>
#include <set>
int x[100];
int bit[100];
std::multiset<int> S;
int main()
{
	int a;
	x[0] = 1;
	for(int i=1;i<=30;i++) x[i] = x[i-1]*2;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		if(b==1)
		{
			int c;
			scanf("%d",&c);
			S.insert(c);
		}
		if(b==2)
		{
			int c;
			scanf("%d",&c);
			S.erase(S.find(c));
		}
		if(b==3)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			
			for(int i=0;i<30;i++)
			{
				if((d%x[i+1])/x[i]==1) bit[i] = 1;
				else bit[i] = 0;
			}
			
			int count = 0;
			for(int i = 29;i>=0;i--)
			{
				if(bit[i]==0) continue;
				//i번째 bit가 다름,
				int t = (((d/x[i])^1)^(c/x[i]))*x[i];
				//printf("%d %d !! \n",t,t+x[i]-1);
				// t ~ t+x[i]-1
				std::multiset<int> ::iterator l = S.lower_bound(t);
				std::multiset<int> ::iterator r = S.upper_bound(t+x[i]-1);
				for(;l!=r;l++) count ++;
				//printf("%d\n",r-l);
			}
			printf("%d\n",count);
		}
	}
}
