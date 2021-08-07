#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>


struct mergeTree{
	std::vector< std::pair<int,int> > V[800010];
	void add(int ind1, int ind2, int val, int l=1, int r=200000, int v=1)
	{
		if(l==r) V[v].push_back({ind2,val});
		else
		{
			int h = (l+r)/2;
			if(ind1<=h) add(ind1,ind2,val,l,h,2*v);
			else add(ind1,ind2,val,h+1,r,2*v+1);
		}
	}
	void sorting(int l=1, int r=200000, int v=1)
	{
		if(l==r) std::sort(V[v].begin(),V[v].end());
		else
		{
			int h = (l+r)/2;
			sorting(l,h,2*v);
			sorting(h+1,r,2*v+1);
			int s = 0, t = 0;
			while(s<V[2*v].size() || t<V[2*v+1].size())
			{
				if(s>=V[2*v].size()) V[v].push_back(V[2*v+1][t]), t++;
				else if(t>=V[2*v+1].size()) V[v].push_back(V[2*v][s]), s++;
				else
				{
					if(V[2*v+1][t].first < V[2*v][s].first) V[v].push_back(V[2*v+1][t]), t++;
					else V[v].push_back(V[2*v][s]), s++;
				}
			}
		}
	}
	
	std::pair<int,int> getIndex(int L1, int R1, int L2, int R2, int type=1, int l=1,int r=200000, int v=1)
	{
		if(L1<=l&&r<=R1)
		{
			int min = 0, max = V[v].size()-1;
			int s = V[v].size(), t = -1;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(V[v][h].first>=L2)
				{
					s = h;
					max = h-1;
				}
				else min = h+1;
			}
			min = 0, max = V[v].size()-1;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(V[v][h].first<=R2)
				{
					t = h;
					min = h+1;
				}
				else max = h-1;
			}
			
			if(s<=t)
			{
				if(type==1) return std::make_pair(V[v][s].second,t-s+1);
				else return std::make_pair(V[v][t].second,t-s+1);
			}
			else return std::make_pair(-1,0);
		}
		else if(R1<l) return std::make_pair(-1,0);
		else if(r<L1) return std::make_pair(-1,0);
		else
		{
			int h = (l+r)/2;
			
			std::pair<int,int> s1 = getIndex(L1,R1,L2,R2,type,l,h,2*v);
			std::pair<int,int> s2 = getIndex(L1,R1,L2,R2,type,h+1,r,2*v+1);
			
			if(type==1)
			{
				if(s1.first==-1) return std::make_pair(s2.first,s1.second+s2.second);
				else return std::make_pair(s1.first,s1.second+s2.second);
			}
			else
			{
				if(s2.first==-1) return std::make_pair(s1.first,s1.second+s2.second);
				else return std::make_pair(s2.first,s1.second+s2.second);
			}
		}
	}
}T;

int x[200010],y[200010];
int left[200010],right[200010],next[200010],check[200010],ans[200010];
int left2[200010],right2[200010],next2[200010],check2[200010],ans2[200010];

std::queue< std::pair<int,int> > Q;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=a;i++) T.add(x[i],y[i],i);
	T.sorting();
	printf("!!\n");
	
	for(int i=1;i<=a;i++) left[i] = right[i] = next[i] = i;
	
	for(int i=1;i<=a;i++)
	{
		if(check[i]) continue;
		
		std::pair<int,int> P = T.getIndex(i,i,i,i);
		if(P.second==1) Q.push( std::make_pair(P.first,i) );
		
		while(!Q.empty())
		{
			int x0 = Q.front().first;
			int y0 = Q.front().second;
			Q.pop();
			
			ans[x0] = y0;
			check[y0] = 1;
			
			if(check[y0-1]==1)
			{
				int v = y0-1;
				while(next[v]!=v) v = next[v];
				next[v] = y0;
				left[y0] = left[v];
			}
			if(check[y0+1]==1)
			{
				int v = y0+1;
				while(next[v]!=v) v = next[v];
				next[v] = y0;
				right[y0] = right[v];
			}
			
			int L = left[y0]-1;
			int R = right[y0]+1;
			if(check[L]==0)
			{
				if(check[L-1]==1)
				{
					int v = L-1;
					while(next[v]!=v) v = next[v];
					std::pair<int,int> P = T.getIndex(left[v],L,L,right[y0]);
					if(P.second==1) Q.push( std::make_pair(P.first,L) );
				}
				else
				{
					std::pair<int,int> P = T.getIndex(L,L,L,right[y0]);
					if(P.second==1) Q.push( std::make_pair(P.first,L) );
				}
			}
			if(check[R]==0)
			{
				if(check[R+1]==1)
				{
					int v = R+1;
					while(next[v]!=v) v = next[v];
					std::pair<int,int> P = T.getIndex(left[y0],R,R,right[v]);
					if(P.second==1) Q.push( std::make_pair(P.first,R) );
				}
				else
				{
					std::pair<int,int> P = T.getIndex(left[y0],R,R,R);
					if(P.second==1) Q.push( std::make_pair(P.first,R) );
				}
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0)
		{
			printf("NO\n");
			goto u;
		}
	}
	
	u:;
	printf("YES\n");
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
	printf("\n");
	//return 0;
	
	//u:;
	
	for(int i=1;i<=a;i++)
	{
		ans2[i] = ans[i];
		check2[i] = check[i];
		left2[i] = left[i];
		right2[i] = right[i];
		next2[i] = next[i];
		
	}
	for(int i=1;i<=a;i++)
	{
		if(check2[i]) continue;
		
		std::pair<int,int> P = T.getIndex(1,i,i,a);
		printf("%d %d %d!!\n",i,P.first,P.second);
		if(P.second>=1) Q.push( std::make_pair(P.first,i) ), printf("?\n");
		
		while(!Q.empty())
		{
			int x0 = Q.front().first;
			int y0 = Q.front().second;
			Q.pop();
			
			ans2[x0] = y0;
			check2[y0] = 1;
			
			if(check2[y0-1]==1)
			{
				int v = y0-1;
				while(next2[v]!=v) v = next2[v];
				next2[v] = y0;
				left2[y0] = left2[v];
			}
			if(check2[y0+1]==1)
			{
				int v = y0+1;
				while(next[v]!=v) v = next2[v];
				next2[v] = y0;
				right2[y0] = right2[v];
			}
			
			int L = left2[y0]-1;
			int R = right2[y0]+1;
			if(check2[L]==0)
			{
				if(check2[L-1]==1)
				{
					int v = L-1;
					while(next2[v]!=v) v = next2[v];
					std::pair<int,int> P = T.getIndex(left2[v],L,L,right2[y0]);
					if(P.second==1) Q.push( std::make_pair(P.first,L) );
				}
				else
				{
					std::pair<int,int> P = T.getIndex(L,L,L,right2[y0]);
					if(P.second==1) Q.push( std::make_pair(P.first,L) );
				}
			}
			if(check2[R]==0)
			{
				if(check2[R+1]==1)
				{
					int v = R+1;
					while(next2[v]!=v) v = next2[v];
					std::pair<int,int> P = T.getIndex(left2[y0],R,R,right2[v]);
					if(P.second==1) Q.push( std::make_pair(P.first,R) );
				}
				else
				{
					std::pair<int,int> P = T.getIndex(left2[y0],R,R,R);
					if(P.second==1) Q.push( std::make_pair(P.first,R) );
				}
			}
		}
	}
	
	for(int i=1;i<=a;i++) printf("%d ",ans2[i]);
	printf("\n");
}
