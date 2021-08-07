#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		V[d].push_back(e);
		count1[d]++, count2[e]++;
	}
	
	for(int i=1;i<=a;i++)
	{
		if(count1[i]>=1&&count2[i]>=1) sum += count1[i]-1;
		else if(count1[i]>=1) sum += count1[i];
		else if(count2[i]>=1);
		else sum++;
	}
	
	while(1)
	{
		for(int i=1;i<=a;i++)
		{
			if(count1[i])
		}
	}
	
	for(int i=1;i<=c;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		P[i]={d,e};
	}
	
	if(sum>c)
	{
		printf("%d\n",c);
		for(int i=1;i<=c;i++) printf("0 ");
		return 0;
	}
	
	for(int i=sum;i<=c;i++)
	{
		DP[i] = DP[i-1] + min[i];
		mode[i] = 0;
		for(int j=1;j<=i;j++)
		{
			int s = (i-sum+1)<(i-j+1)?(i-sum+1):(i-j+1);
			if(P[j].second*s > P[j].first)
			{
				long long int t = P[j].first + DP[j-1];
				if(DP[i]>t)
				{
					DP[i] = t;
					mode[i] = j;
				}
			}
		}
	}
	
	int p = c;
	while(p>=sum)
	{
		if(mode[p]!=0)
		{
			for(int j=mode[p];j<=p;j++) count[mode[p]]++;
			p = mode[p] - 1;
		}
		else
		{
			int p2;
			for(int j=1;j<=p;j++) if(P[j].second == min[p]) p2 = j;
			count[p2]++;
			p--;
		}
	}
}