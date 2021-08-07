#include <stdio.h>
#include <string.h>
#include <vector>

int abs(int k)
{
	return k>0?k:-k;
}
int func(std::pair<int,int> P,int x, int y)
{
	if(P.first==-1) return 0;
	if(P.first>=x&&P.second>=y) return P.first-x>P.second-y?P.first-x:P.second-y;
	else if(P.first<=x&&P.second<=y) return x-P.first>y-P.second?x-P.first:y-P.second;
	else return abs(P.first-x)+abs(P.second-y);
}

char x[500010];
std::vector<int> y[500010];
std::pair< std::pair<int,int> ,std::pair<int,int> > small[500010],large[500010];
int value[500010];
int number[500010];

int main()
{
	int a;
	scanf("%d",&a);
	
	int xMin = 12345678, xMax = -1;
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		int b = strlen(x+1);
		
		int count1 = 0, count2 = 0;
		for(int j=1;j<=b;j++)
		{
			if(x[j]=='B') count1++;
			else count2++;
		}
		y[count1].push_back(count2);
		xMin = xMin<count1?xMin:count1;
		xMax = xMax>count1?xMax:count1;
	}
	
	std::pair<int,int> L = std::make_pair(-1,-1);
	std::pair<int,int> R = std::make_pair(-1,-1);
	for(int i=0;i<=500000;i++)
	{
		for(int j=0;j<y[i].size();j++)
		{
			if(R==std::make_pair(-1,-1)) R = std::make_pair(i,y[i][j]);
			else if(y[i][j]<=R.second-(i-R.first)) R = std::make_pair(i,y[i][j]);
			if(L==std::make_pair(-1,-1)) L = std::make_pair(i,y[i][j]);
			else if(y[i][j]>=L.second) L = std::make_pair(i,y[i][j]);
		}
		small[i] = std::make_pair(L,R);
	}
	
	L = std::make_pair(-1,-1);
	R = std::make_pair(-1,-1);
	for(int i=500000;i>=0;i--)
	{
		for(int j=0;j<y[i].size();j++)
		{
			if(R==std::make_pair(-1,-1)) R = std::make_pair(i,y[i][j]);
			else if(y[i][j]<=R.second) R = std::make_pair(i,y[i][j]);
			if(L==std::make_pair(-1,-1)) L = std::make_pair(i,y[i][j]);
			else if(y[i][j]>=L.second+(L.first-i)) L = std::make_pair(i,y[i][j]);
		}
		large[i] = std::make_pair(L,R);
	}
	
	for(int i=xMin;i<=xMax;i++)
	{
		value[i] = 12345678;
		int limit = xMax-i>i-xMin?xMax-i:i-xMin;
		int min = 0, max = 500000;
		if(i==0) min = 1;
		while(min<=max)
		{
			int h = (min+max)/2;
			int s1 = func(small[i].first,i,h);
			int s2 = func(small[i].second,i,h);
			int t1 = func(large[i].first,i,h);
			int t2 = func(large[i].second,i,h);
			int M = limit;
			M = M>s1?M:s1;
			M = M>s2?M:s2;
			M = M>t1?M:t1;
			M = M>t2?M:t2;
			if(value[i]>M)
			{
				value[i] = M;
				number[i] = h;
			}
			
			if(M==s1) min = h+1;
			else if(M==s2) max = h-1;
			else if(M==t1) min = h+1;
			else if(M==t2) max = h-1;
			else break;
		}
	}
	
	long long int ans = 12345678;
	int ans2 = 0;
	for(int i=xMin;i<=xMax;i++)
	{
		if(ans>value[i])
		{
			ans = value[i];
			ans2 = i;
		}
	}
	printf("%lld\n",ans);
	for(int i=1;i<=ans2;i++) printf("B");
	for(int i=1;i<=number[ans2];i++) printf("N");
}
