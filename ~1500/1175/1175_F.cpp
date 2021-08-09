#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > V1,V2;
int x[300010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) if(x[i]==1) V1.push_back(std::make_pair(i,i));
	
	long long int ans = 0;
	ans += V1.size();
	for(int i=2;i<=a;i++)
	{
		for(int j=0;j<V1.size();j++)
		{
			if(x[V1[j].first-1]==i) V2.push_back(std::make_pair(V1[j].first-1,V1[j].second));
			if(x[V1[j].second+1]==i) V2.push_back(std::make_pair(V1[j].first,V1[j].second+1));
		}
		printf("%d: %d!!\n",i,V2.size());
		ans += V2.size();
		V1.clear();
		for(int j=0;j<V2.size();j++) V1.push_back(V2[j]);
		V2.clear();
	}
	printf("%lld",ans);
}
