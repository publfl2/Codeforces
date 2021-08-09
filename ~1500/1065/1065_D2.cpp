#include <stdio.h>
#include <vector>

int x[110][110];
std::pair<int,int> P[110];
int knight[110][110];

int abs(int k)
{
	return k>0?k:-k;
}

std::pair<int,int> func(int s1, int t1, int s2, int t2)
{
	if(t1==t2)
	{
		if(t1==1) // knight
		{
			int t = knight[P[s1].first-P[s2].first+10][P[s1].second-P[s2].second+10];
			if(t<=4) return {t,0};
			else return {4,2};
		}
		else if(t1==2)
		{
			if(abs(P[s1].first-P[s2].first)==abs(P[s1].second-P[s2].second)) return {1,0};
			else if((P[s1].first+P[s1].second)%2==(P[s2].first+P[s2].second)%2) return {2,0};
			else return {4,2};
		}
		else
		{
			if(P[s1].first==P[s2].first) return {1,0};
			else if(P[s1].second==P[s2].second) return {1,0};
			else return {2,0};
		}
	}
	else
	{
		if(t2==1) // knight
		{
			int t = knight[P[s1].first-P[s2].first+10][P[s1].second-P[s2].second+10];
			if(t<=3) return {t+1,1};
			else if(t1==3) return {3,1};
			else return {4,2};
		}
		else if(t2==2)
		{
			if(abs(P[s1].first-P[s2].first)==abs(P[s1].second-P[s2].second)) return {2,1};
			else if((P[s1].first+P[s1].second)%2==(P[s2].first+P[s2].second)%2) return {3,1};
			else if(t1==3) return {3,1};
			else return {4,2};
		}
		else
		{
			if(P[s1].first==P[s2].first) return {2,1};
			else if(P[s1].second==P[s2].second) return {2,1};
			else return {3,1};
		}
	}
}

void func2(int s, int t, int k)
{
	if(k==5) return;
	knight[s+10][t+10] = knight[s+10][t+10]<k?knight[s+10][t+10]:k;
	func2(s-2,t-1,k+1);
	func2(s-2,t+1,k+1);
	func2(s-1,t-2,k+1);
	func2(s-1,t+2,k+1);
	func2(s+2,t-1,k+1);
	func2(s+2,t+1,k+1);
	func2(s+1,t-2,k+1);
	func2(s+1,t+2,k+1);
}

std::pair<int,int> operator+(std::pair<int,int> A, std::pair<int,int> B)
{
	return {A.first+B.first,A.second+B.second};
}

std::pair<int,int> max(std::pair<int,int> A, std::pair<int,int> B)
{
	return A<B?A:B;
}

std::pair<int,int> DP[110][4];
int main()
{
	for(int i=1;i<=20;i++) for(int j=1;j<=20;j++) knight[i][j] = 10;
	func2(0,0,0);
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			int b;
			scanf("%d",&b);
			P[b] = {i,j};
		}
	}
	
	DP[1][1] = DP[1][2] = DP[1][3] = {0,0};
	
	for(int i=2;i<=a*a;i++)
	{
		std::pair<int,int> s1,s2,s3;
		s1 = DP[i-1][1] + max(func(i,1,i-1,1),{4,2}), s2 = DP[i-1][2] + max(func(i,1,i-1,2),{4,2}), s3 = DP[i-1][3] + max(func(i,1,i-1,3),{4,2});
		DP[i][1] = max(s1,max(s2,s3));
		s1 = DP[i-1][1] + max(func(i,2,i-1,1),{4,2}), s2 = DP[i-1][2] + max(func(i,2,i-1,2),{4,2}), s3 = DP[i-1][3] + max(func(i,2,i-1,3),{4,2});
		DP[i][2] = max(s1,max(s2,s3));
		s1 = DP[i-1][1] + max(func(i,3,i-1,1),{4,2}), s2 = DP[i-1][2] + max(func(i,3,i-1,2),{4,2}), s3 = DP[i-1][3] + max(func(i,3,i-1,3),{4,2});
		DP[i][3] = max(s1,max(s2,s3));
		
		std::pair<int,int> P = max(DP[i][1],max(DP[i][2],DP[i][3]));
		DP[i][1] = max(DP[i][1],P+std::make_pair(1,1));
		DP[i][2] = max(DP[i][2],P+std::make_pair(1,1));
		DP[i][3] = max(DP[i][3],P+std::make_pair(1,1));
		
	}
	
	std::pair<int,int> ans = max(DP[a*a][1],max(DP[a*a][2],DP[a*a][3]));
	printf("%d %d",ans.first,ans.second);
}