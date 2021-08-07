#include <stdio.h>
#include <vector>
#include <string.h>
#define MAX 12345678

int limit;
int possible[1100010];
int next[1100010][10];
int b;
char x[1010];

int DP[3][300010];
int func2(int L, int R)
{
	for(int j=0;j<(1<<(b-2));j++) DP[(R+1)%2][j] = 0;
	
	int ans = R-L+1;
	for(int i=R;i>=L;i--)
	{
		if(x[i]!=b) ans = ans<DP[(i+1)%2][(1<<(x[i]-2))]+(i-L)?ans:DP[(i+1)%2][(1<<(x[i]-2))]+(i-L);
		
		for(int j=0;j<(1<<(b-2));j++)
		{
			int bit = j;
			int s1 = DP[(i+1)%2][bit]+1;
			int newBit = next[bit][x[i]];
			
			int s2 = MAX;
			if(possible[newBit]==1) s2 = DP[(i+1)%2][1<<(x[i]-2)];
			if((newBit&(1<<(b-2)))==0) s2 = DP[(i+1)%2][newBit%(1<<(b-2))];
			else if(possible[newBit]==1) s2 = DP[(i+1)%2][newBit%(1<<(b-2))];
			DP[i%2][j] = s1<s2?s1:s2;
		}
	}
	return ans;
}

int func(int k, long long int bit) // bit->->2
{
	if(k>limit) return 0;
	
	int s1 = func(k+1,bit)+1;
	int newBit = next[bit][x[k]];
	
	int s2 = MAX;
	if((newBit&(1<<(b-2)))==0) s2 = func(k+1,newBit%(1<<(b-2)));
	else if(possible[newBit]==1) s2 = func(k+1,newBit%(1<<(b-2)));
	return s1<s2?s1:s2;
}

std::vector<int> start,last;
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	
	scanf("%d",&b);
	if(b==1)
	{
		int count = 0;
		for(int i=1;i<=a;i++) if(x[i]=='1') count++;
		printf("%d",count);
		return 0;
	}
	
	x[0] = '1';
	x[a+1] = '1';
	for(int i=1;i<=a;i++)
	{
		if(x[i]!='1'&&x[i-1]=='1') start.push_back(i);
		if(x[i]!='1'&&x[i+1]=='1') last.push_back(i);
	}
	
	for(int i=1;i<=a;i++) x[i]-='0';
	for(long long int i=0;i<(1<<(b-2));i++)
	{
		long long int k = 2*i;
		for(int j=2;j<=9;j++)
		{
			k*=2;
			k%=(1<<(b-1));
			next[i][j] = k+(1<<(j-2));
		}
	}
	
	
	int ans = 0;
	for(int i=0;i<start.size();i++)
	{
		limit = last[i];
		int S = func2(start[i],last[i]);
		ans += S;
	}
	printf("%d",ans);
}
