#include <stdio.h>
#include <vector>
#include <algorithm>

long long int x[1010];
std::vector<long long int> V,V2;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	if(a==1) printf("%lld",x[1]);
	else if(a==2) printf("%lld",x[1]|x[2]);
	else
	{
		long long int ans = 0;
		for(int i=1;i<=a;i++) V.push_back(x[i]);
		int T = 3;
		while(T--)
		{
			std::sort(V.begin(),V.end());
			int p = V.size()-1;
			ans += V[p];
			
			if(T==0) break;
			
			V2.clear();
			for(int i=0;i<=V.size()-2;i++)
			{
				V2.push_back(0);
				long long int C = 1;
				for(int j=0;j<60;j++)
				{
					if((V[i]&C)!=0 && (V[p]&C)==0) V2[V2.size()-1] += C;
					C*=2;
				}
			}
			V.clear();
			V = V2;
		}
		printf("%lld",ans);
	}
}
