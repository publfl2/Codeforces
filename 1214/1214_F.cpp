#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

std::pair<int,int> x[200010],y[200010];
bool cmp(std::pair<int,int> A, std::pair<int,int> B)
{
	return A.first<B.first;
}
std::priority_queue<int> Q1;
std::priority_queue<int, std::vector<int> , std::greater<int> > Q2;

int check[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int limit = a/2;
	for(int i=1;i<=b;i++) scanf("%d",&x[i].first);
	for(int i=1;i<=b;i++) scanf("%d",&y[i].first);
	for(int i=1;i<=b;i++) x[i].second = y[i].second = i;
	std::sort(x+1,x+b+1,cmp);
	std::sort(y+1,y+b+1,cmp);
	
	long long int ans = 0;
	int pivot = 1;
	for(int i=1;i<=b;i++)
	{
		int dist = ((y[i].first+a)-x[i].first)%a;
		
		if(dist<=limit) Q1.push(dist),ans += dist;
		else Q2.push(a-dist), ans += a-dist;
	}
	
	long long int sum = ans;
	int shift = 0;
	for(int i=2;i<=b;i++)
	{
		sum += (long long int)Q1.size()*(y[i].first-y[i-1].first) - (long long int)Q2.size()*(y[i].first-y[i-1].first);
		shift += (y[i].first-y[i-1].first);
		while(!Q1.empty())
		{
			int t = Q1.top();
			if(t+shift>limit)
			{
				sum -= (t+shift);
				sum += (a-(t+shift));
				Q2.push(a-t);
				Q1.pop();
			}
			else break;
		}
		while(!Q2.empty())
		{
			int t = Q2.top();
			if(t-shift<0)
			{
				sum -= (t-shift);
				sum += (a-(t-shift));
				Q1.push(a-t);
				Q2.pop();
			}
			else break;
		}
		printf("%d : %lld!!\n",i,sum);
		if(sum<ans) ans = sum, pivot = i;
	}
	printf("%lld\n",ans);
	for(int i=pivot;i<pivot+b;i++) check[x[i-pivot+1].second] = y[(i-1)%b+1].second;
	for(int i=1;i<=b;i++) printf("%d ",check[i]);
}
