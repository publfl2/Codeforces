#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<long long int> V1,V2,V3,temp;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		long long int b;
		scanf("%lld",&b);
		V1.push_back(b);
	}
	
	long long int ans = 0;
	int max = a;
	
	for(int i=60;i>=0;i--)
	{
		long long int C = 1;
		for(int j=1;j<=i;j++) C*=2;
		int count = 0;
		for(int j=0;j<V1.size();j++) if((V1[j]&C)!=0) count++;
		if(count>0)
		{
			ans += C;
			temp.clear();
			for(int j=0;j<V1.size();j++) if((V1[j]&C)!=0) temp.push_back(V1[j]);
			for(int j=0;j<V1.size();j++) if((V1[j]&C)==0) V2.push_back(V1[j]);
			V1.clear();
			V1 = temp;
		}
		else
		{
			int count2 = 0;
			for(int j=0;j<V2.size();j++) if((V2[j]&C)!=0) count2++;
			if(count2>0)
			{
				ans += C;
				temp.clear();
				for(int j=0;j<V2.size();j++) if((V2[j]&C)!=0) temp.push_back(V2[j]);
				for(int j=0;j<V2.size();j++) if((V2[j]&C)==0) V3.push_back(V2[j]);
				V2.clear();
				V2 = temp;
			}
			else
			{
				int count3 = 0;
				for(int j=0;j<V3.size();j++) if((V3[j]&C)!=0) count3++;
				if(count3>0)
				{
					ans += C;
					temp.clear();
					for(int j=0;j<V2.size();j++) if((V3[j]&C)!=0) temp.push_back(V3[j]);
					V3.clear();
					V3 = temp;
				}
			}
		}
	}
	printf("%lld",ans);
}
