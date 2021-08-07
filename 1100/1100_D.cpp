#include <stdio.h>
#include <vector>

std::pair<int,int> x,y[1010];

int check[1010][1010];
int valid()
{
	check[x.first-1][x.second-1] = 0;
	check[x.first-1][x.second] = 0;
	check[x.first-1][x.second+1] = 0;
	check[x.first][x.second-1] = 0;
	check[x.first][x.second] = 0;
	check[x.first][x.second+1] = 0;
	check[x.first+1][x.second-1] = 0;
	check[x.first+1][x.second] = 0;
	check[x.first+1][x.second+1] = 0;
	
	for(int i=1;i<=666;i++)
	{
		if(y[i].first==x.first-1) for(int j=-1;j<=1;j++) check[x.first-1][x.second+j] = 1;
		if(y[i].first==x.first+1) for(int j=-1;j<=1;j++) check[x.first+1][x.second+j] = 1;
		if(y[i].second==x.second-1) for(int j=-1;j<=1;j++) check[x.first+j][x.second-1] = 1;
		if(y[i].second==x.second+1) for(int j=-1;j<=1;j++) check[x.first+j][x.second+1] = 1;
	}
	for(int i=1;i<=666;i++) check[y[i].first][y[i].second] = -1;
	for(int i=-1;i<=1;i++)
	{
		for(int j=-1;j<=1;j++)
		{
			if(check[x.first+i][x.second+j]==1)
			{
				printf("%d %d\n",x.first+i,x.second+j);
				return 1;
			}
		}
	}
	return 0;
}

int getQuery()
{
	printf("%d %d\n",x.first,x.second);
	fflush(stdout);
	
	int c,d,e;
	scanf("%d%d%d",&c,&d,&e);
	if(c==-1) return -1;
	y[c] = std::make_pair(d,e);
	return 0;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	x = std::make_pair(a,b);
	for(int i=1;i<=666;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		y[i] = std::make_pair(c,d);
	}
	
	while(1)
	{
		if(valid()) return 0;
		if(x.first==500 && x.second==500) break;
		if(x.first>500) x.first--;
		else if(x.first<500) x.first++;
		if(x.second>500) x.second--;
		else if(x.second<500) x.second++;
		
		int t = getQuery();
		if(t==-1) return 0;
	}
	
	int count1 = 0 ,count2 = 0, count3 = 0, count4 = 0;
	for(int i=1;i<=666;i++)
	{
		if(y[i].first<500 && y[i].second<500) count1++;
		if(y[i].first<500 && y[i].second>500) count2++;
		if(y[i].first>500 && y[i].second<500) count3++;
		if(y[i].first>500 && y[i].second>500) count4++;
	}
	
	int direX = 1 ,direY = 1;
	if(count1+count2+count3>=500) direX = -1, direY = -1;
	if(count1+count2+count4>=500) direX = -1, direY = 1;
	if(count1+count3+count4>=500) direX = 1, direY = -1;
	if(count2+count3+count4>=500) direX = 1, direY = 1;
	
	while(1)
	{
		if(valid()) return 0;
		x.first += direX;
		x.second += direY;
		int t = getQuery();
		if(t==-1) return 0;
	}
}