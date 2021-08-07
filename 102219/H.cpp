#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>

std::pair<int,int> x[100010];
std::pair<int,int> limit = std::make_pair(1000,1000);
bool cmp1(std::pair<int,int> P1, std::pair<int,int> P2)
{
	return P1.first<P2.first;
}
bool cmp2(std::pair<int,int> P1, std::pair<int,int> P2)
{
	return atan2(P1.second-x[1].second,P1.first-x[1].first) < atan2(P2.second-x[1].second,P2.first-x[1].first);
}
int ccw(std::pair<int,int> P1, std::pair<int,int> P2, std::pair<int,int> P3)
{
	int s1 = P1.first*P2.second + P2.first*P3.second + P3.first * P1.second;
	int s2 = P2.first*P1.second + P3.first*P2.second + P1.first * P3.second;
	if(s1>s2) return 1;
	else return -1;
}

std::vector< std::pair<int,int> > St;

int main()
{
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		printf("Case %d\n",T);
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			x[i] = std::make_pair(c,d);
		}
		std::sort(x+1,x+a+1,cmp1);
		std::sort(x+2,x+a+1,cmp2);
		
		St.clear();
		St.push_back(x[1]);
		St.push_back(x[2]);
		for(int i=3;i<=a;i++)
		{
			while(St.size()>=2)
			{
				std::pair<int,int> P2 = St.back();
				St.pop_back();
				std::pair<int,int> P1 = St.back();
				St.pop_back();
				if(ccw(P1,P2,x[i])==-1) St.push_back(P1);
				else
				{
					St.push_back(P1);
					St.push_back(P2);
					break;
				}
			}
			St.push_back(x[i]);
		}
		St.push_back(x[1]);
		for(int i=0;i<St.size();i++) printf("%d %d\n",St[i].first,St[i].second);
		
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			std::pair<int,int> P = std::make_pair(c,d);
			
			int count = 0;
			for(int j=0;j<St.size()-1;j++)
			{
				if(ccw(P,limit,St[j])*ccw(P,limit,St[j+1])==-1 && ccw(St[j],St[j+1],P)*ccw(St[j],St[j+1],limit)==-1) count++;
			}
			if(count%2==1) printf("%d %d is unsafe!\n",c,d);
			else printf("%d %d is safe!\n",c,d);
		}
		printf("\n");
	}
}
