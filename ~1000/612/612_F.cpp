#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#define MAX 1234567890

struct segTree{
	std::pair<int,int> value[16010];
	void setValue(int ind, int val, int l=1, int r=4000, int v=1)
	{
		if(l==r) value[v] = {val,ind};
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	std::pair<int,int> getMin(int L, int R, int l=1, int r=4000, int v=1)
	{
		if(L>R) return {MAX,0};
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return {MAX,0};
		else if(R<l) return {MAX,0};
		else
		{
			int h = (l+r)/2;
			std::pair<int,int> s1 = getMin(L,R,l,h,2*v);
			std::pair<int,int> s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
	
	void clear(int l=1,int r=4000, int v=1)
	{
		value[v] = {MAX,0};
		if(l==r) return;
		
		int h = (l+r)/2;
		clear(l,h,2*v);
		clear(h+1,r,2*v+1);
	}
}T[3][5];

void update(int type, int ind, int val)
{
	T[type][1].setValue(ind,val+ind);
	T[type][2].setValue(ind,val-ind);
	T[type][3].setValue(ind,val-ind);
	T[type][4].setValue(ind,val+ind);
}

std::vector<int> index;
std::map<int,int> hash;

int x[4010];
std::vector<int> V[2010];
std::pair<int,int> value[4010];
int type[4010];
std::vector<int> ans;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) index.push_back(x[i]);
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i;
	for(int i=1;i<=a;i++) x[i] = hash[x[i]];
	int n = index.size()-1;
	
	for(int i=a+1;i<=2*a;i++) x[i] = x[i-a];
	for(int i=1;i<=2*a;i++) V[x[i]].push_back(i);
	//V[0].push_back(b);
	
	for(int j=1;j<=4;j++) T[1][j].clear();
	update(1,b,0);
	update(1,a+b,0);
	
	for(int i=0;i<=n;i++)
	{
		for(int j=1;j<=4;j++) T[i%2][j].clear();
		for(int j=0;j<V[i].size()/2;j++)
		{
			int L = V[i][j];
			int R = V[i][j]+a;
			
			std::pair<int,int> P;
			if(V[i][j+1]==R)
			{
				P = T[1-i%2][1].getMin(L,R);
				value[L] = {P.first-L,P.second};
				P = T[1-i%2][3].getMin(L,R);
				value[R] = {P.first+R,P.second};
				if(value[L]>value[R])
				{
					type[L] = type[R] = 2;
					value[L] = value[R];
				}
				else
				{
					type[L] = type[R] = 1;
					value[R] = value[L];
				}
				
				update(i%2,L,value[L].first);
				update(i%2,R,value[R].first);
			}
			else
			{
				int Llimit = V[i][j+1];
				int Rlimit = V[i][j+(V[i].size()/2)-1];
				
				P = T[1-i%2][1].getMin(Rlimit,R);
				value[L] = {P.first-L,P.second};
				P = T[1-i%2][2].getMin(L,Rlimit);
				P.first += 2*Rlimit - L;
				if(P.first<value[L].first) value[L] = P;
				
				P = T[1-i%2][3].getMin(L,Llimit);
				value[R] = {P.first+R,P.second};
				P = T[1-i%2][4].getMin(Llimit,R);
				P.first += (-2)*Llimit + R;
				if(P.first<value[R].first) value[R] = P;
				if(value[L]>value[R])
				{
					type[L] = type[R] = 2;
					value[L] = value[R];
				}
				else
				{
					type[L] = type[R] = 1;
					value[R] = value[L];
				}
				
				update(i%2,L,value[L].first);
				update(i%2,R,value[R].first);
			}
		}
	}
	
	
	int min = MAX;
	int p;
	
	for(int i=1;i<=a;i++)
	{
		if(x[i]==n && value[i].first<min)
		{
			min = value[i].first;
			p = i;
		}
	}
	
	
	for(int i=n;i>=0;i--)
	{
		if(p>a) p -=a;
		for(int j=0;j<V[i].size()/2;j++)
		{
			if(V[i][j]==p)
			{
				int L = V[i][j];
				int R = V[i][j]+a;
				if(V[i][j+1]==V[i][j]+a)
				{
					if(type[L]==1)
					{
						ans.push_back(value[L].second-L);
						p = value[L].second;
						break;
					}
					else
					{
						ans.push_back(R-value[R].second);
						p = value[R].second;
						break;
					}
				}
				else
				{		
					int L = V[i][j];
					int R = V[i][j]+a;	
					int Llimit = V[i][j+1];
					int Rlimit = V[i][j+(V[i].size()/2)-1];
					if(type[L]==1)
					{
						int t = value[L].second;
						int start;
						for(int k=j;k<j+(V[i].size()/2);k++) if(V[i][k]<t) start = k;
						for(int k=start+1;k<j+(V[i].size()/2);k++)
						{
							ans.push_back(V[i][k]-t);
							t = V[i][k];
						}
						ans.push_back(V[i][start]-t);
						t = V[i][start];
						for(int k=start-1;k>=j;k--)
						{
							ans.push_back(V[i][k]-t);
							t = V[i][k];
						}
						p = value[L].second;
						break;
					}
					else
					{
						int t = value[L].second;
						int start;
						for(int k=j+(V[i].size())/2;k>j;k--) if(V[i][k]>t) start = k;
						
						for(int k=start-1;k>j;k--)
						{
							ans.push_back(V[i][k]-t);
							t = V[i][k];
						}
						ans.push_back(V[i][start]-t);
						t = V[i][start];
						for(int k=start+1;k<=j+(V[i].size()/2);k++)
						{
							ans.push_back(V[i][k]-t);
							t = V[i][k];
						}
						p = value[L].second;
						break;
					}
				}
			}
		}
	}
	
	std::reverse(ans.begin(),ans.end());
	printf("%d\n",min);
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i]>=0) printf("+");
		printf("%d\n",ans[i]);
	}
}