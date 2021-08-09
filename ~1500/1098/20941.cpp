#include <stdio.h>
#include <vector>
#include <string.h>

std::vector<int> V,V2,V3,temp;
char x[110];
int check[2000010];
int main()
{
	int a;
	scanf("%d%s",&a,x+1);
	int c = strlen(x+1);
	int b = 0;
	for(int i=1;i<=c;i++) b*=2, b+=(x[i]-'0');
	
	V.push_back(0);
	V.push_back(1);
	for(int i=2;i<=a;i++)
	{
		V2.clear();
		V3.clear();
		int s = (1<<(i-1));
		for(int j=0;j<V.size();j++)
		{
			if(j%2==0) V2.push_back(V[j]);
			else V2.push_back(V[j]+s);
		}
		for(int j=0;j<V.size();j++)
		{
			if(j%2==0) V3.push_back(V[j]+s);
			else V3.push_back(V[j]);
		}
		int start1=0,start2=0;
		
		int bit = (1<<(i-1))-1;
		for(int j=0;j<V.size();j++) check[V[j]] = j;
		for(int j=0;j<V.size();j++)
		{
			int t = (V[j]^bit);
			start1 = check[t];
			start2 = j;
			if((check[t]+j)%2==0)
			{
				start1 = check[t];
				start2 = j;
				break;
			}
		}
		
		V.clear();
		for(int j=start1+1;j<V2.size();j++) V.push_back(V2[j]);
		for(int j=0;j<=start1;j++) V.push_back(V2[j]);
		for(int j=start2;j<V3.size();j++) V.push_back(V3[j]);
		for(int j=0;j<start2;j++) V.push_back(V3[j]);
	}
	
	int t = (V[0]^b);
	for(int i=0;i<V.size();i++) V[i] ^= t;
	for(int i=0;i<V.size();i++)
	{
		temp.clear();
		for(int j=0;j<a;j++)
		{
			temp.push_back(V[i]%2);
			V[i]/=2;
		}
		for(int j=temp.size()-1;j>=0;j--) printf("%d",temp[j]);
		printf("\n");
	}
}