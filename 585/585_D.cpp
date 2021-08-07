#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

std::vector<int> V;
long long int sum1, sum2, sum3;
std::map< std::pair<long long int, long long int> , int > M,M2;

struct str{
	int x0;
	int y0;
	int z0;
}P[110];

int control = 0;
void rehash(int k, std::vector<int>& V)
{
	while(k)
	{
		V.push_back((k%4));
		k/=4;
	}
	std::reverse(V.begin(),V.end());
}

int h;
void func1(int L, int R)
{
	if(L>R)
	{
		if(sum3>=M2[std::make_pair(sum3-sum1,sum3-sum2)])
		{
			M[std::make_pair(sum3-sum1,sum3-sum2)] = h;
			M2[std::make_pair(sum3-sum1,sum3-sum2)] = sum3;
		}
		return;
	}
	sum1 += P[L].x0, sum2 += P[L].y0;
	h*=4;
	h+=1;
	func1(L+1,R);
	h-=1;
	h/=4;
	sum1 -= P[L].x0, sum2 -= P[L].y0;
	
	sum2 += P[L].y0, sum3 += P[L].z0;
	h*=4;
	h+=2;
	func1(L+1,R);
	h-=2;
	h/=4;
	sum2 -= P[L].y0, sum3 -= P[L].z0;
	
	sum1 += P[L].x0, sum3 += P[L].z0;
	h*=4;
	h+=3;
	func1(L+1,R);
	h-=3;
	h/=4;
	sum1 -= P[L].x0, sum3 -= P[L].z0;
}

int ans1, ans2, ans3;
void func2(int L, int R)
{
	if(L>R)
	{
		if(M.find(std::make_pair(sum1-sum3,sum2-sum3))!=M.end())
		{
			control = 1;
			if(ans3<=sum3+M2[std::make_pair(sum1-sum3,sum2-sum3)])
			{
				ans1 = M[std::make_pair(sum1-sum3,sum2-sum3)];
				ans2 = h;
				ans3 = sum3+M2[std::make_pair(sum1-sum3,sum2-sum3)];
			}
		}
		return;
	}
	sum1 += P[L].x0, sum2 += P[L].y0;
	h*=4;
	h+=1;
	func2(L+1,R);
	h-=1;
	h/=4;
	sum1 -= P[L].x0, sum2 -= P[L].y0;
	
	sum2 += P[L].y0, sum3 += P[L].z0;
	h*=4;
	h+=2;
	func2(L+1,R);
	h-=2;
	h/=4;
	sum2 -= P[L].y0, sum3 -= P[L].z0;
	
	sum1 += P[L].x0, sum3 += P[L].z0;
	h*=4;
	h+=3;
	func2(L+1,R);
	h-=3;
	h/=4;
	sum1 -= P[L].x0, sum3 -= P[L].z0;
}

std::vector<int> V1,V2;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d%d%d",&P[i].x0,&P[i].y0,&P[i].z0);
	if(a==1)
	{
		if(P[1].x0==0&&P[1].y0==0) printf("LM\n");
		else if(P[1].y0==0&&P[1].z0==0) printf("MW\n");
		else if(P[1].x0==0&&P[1].z0==0) printf("LW\n");
		else printf("Impossible");
		return 0;
	}
	
	func1(1,((a+1)/2));
	func2((a+1)/2+1,a);
	
	if(control==0) printf("Impossible");
	else
	{
		rehash(ans1,V1);
		rehash(ans2,V2);
		for(int i=0;i<V1.size();i++)
		{
			if(V1[i]==1) printf("LM\n");
			else if(V1[i]==2) printf("MW\n");
			else printf("LW\n");
		}
		for(int i=0;i<V2.size();i++)
		{
			if(V2[i]==1) printf("LM\n");
			else if(V2[i]==2) printf("MW\n");
			else printf("LW\n");
		}
	}
}
