#include <stdio.h>
#include <vector>
int func(int h)
{
	if(h%2==0)
	{
		int k = h/2;
		return k*(k-1);
	}
	else return (h-1)*(h-1)/4;
}

std::vector<int> V,V2;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	for(int i=a;i>=1;i--)
	{
		int S = func(i);
		if(S>b) continue;
		
		V.clear();
		for(int j=1;j<=i;j++) V.push_back(j);
		int c = a-i, d = b - S;
		int start = 2*i-1;
		while(d>0)
		{
			if(c<=1) break;
			
			int min = 2, max = (i+1)<c?(i+1):c;
			int ans = max;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(h*(h-1)/2<=d)
				{
					ans = h;
					min = h+1;
				}
				else max = h-1;
			}
			for(int j=1;j<=ans;j++) V.push_back(start+j);
			c -= ans, d -= ans*(ans-1)/2;
			start = 2*(start+ans)-1;
		}
		if(d==0)
		{
			int gap = (start+1)/2 + 1;
			for(int j=1;j<=c;j++) V2.push_back(1000000000 - (j-1)*gap);
			for(int j=0;j<V.size();j++) printf("%d ",V[j]);
			for(int j=V2.size()-1;j>=0;j--) printf("%d ",V2[j]);
			return 0;
		}
	}
	printf("-1");
}
