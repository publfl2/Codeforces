#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

struct segTree{
	int value[40010];
	void add(int ind, int val, int l=1, int r=10000, int v=1)
	{
		if(l==r) value[v] += val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) add(ind,val,l,h,2*v);
			else add(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	int get(int L, int R, int l=1, int r=10000, int v=1)
	{
		if(L>R) return 0;
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			return get(L,R,l,h,2*v)+get(L,R,h+1,r,2*v+1);
		}
	}
}T1,T2;

long long int func(int k)
{
	if(k<=0) return 0;
	
	int v = 1;
	int l = 1, r = 10000;
	int t = k;
	
	while(l<r)
	{
		int h = (l+r)/2;
		if(T1.value[2*v]<t)
		{
			t -= T1.value[2*v];
			l = h+1;
			v = 2*v+1;
		}
		else
		{
			r = h;
			v = 2*v;
		}
	}
	
	int ans = l;
	return T2.get(1,ans) + (k-T1.get(1,ans))*(ans+1);
}

std::set< std::pair<int,int> > S;
std::vector< std::pair<int,int> > V1,V2,V3,V4,W1,W2,W3,W4;
int S1[200010],S2[200010],S3[200010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		if(e==1&&f==1)
		{
			V1.push_back(std::make_pair(d,i));
		}
		if(e==1&&f==0)
		{
			V2.push_back(std::make_pair(d,i));
		}
		if(e==0&&f==1)
		{
			V3.push_back(std::make_pair(d,i));
		}
		if(e==0&&f==0)
		{
			V4.push_back(std::make_pair(d,i));
		}
	}
	std::sort(V1.begin(),V1.end());
	std::sort(V2.begin(),V2.end());
	std::sort(V3.begin(),V3.end());
	std::sort(V4.begin(),V4.end());
	W1 = V1;
	W2 = V2;
	W3 = V3;
	W4 = V4;
	
	for(int i=0;i<V4.size();i++)
	{
		T1.add(V4[i].first,1);
		T2.add(V4[i].first,V4[i].first);
	}
	while(V1.size()>c)
	{
		T1.add(V1[V1.size()-1].first,1);
		T2.add(V1[V1.size()-1].first,V1[V1.size()-1].first);
		V1.pop_back();
	}
	while(V2.size()>c)
	{
		T1.add(V2[V2.size()-1].first,1);
		T2.add(V2[V2.size()-1].first,V2[V2.size()-1].first);
		V2.pop_back();
	}
	while(V3.size()>c)
	{
		T1.add(V3[V3.size()-1].first,1);
		T2.add(V3[V3.size()-1].first,V3[V3.size()-1].first);
		V3.pop_back();
	}
	for(int i=0;i<V1.size();i++)
	{
		if(i==0) S1[i] = V1[i].first;
		else S1[i] = S1[i-1] + V1[i].first;
	}
	for(int i=0;i<V2.size();i++)
	{
		if(i==0) S2[i] = V2[i].first;
		else S2[i] = S2[i-1] + V2[i].first;
	}
	for(int i=0;i<V3.size();i++)
	{
		if(i==0) S3[i] = V3[i].first;
		else S3[i] = S3[i-1] + V3[i].first;
	}
	
	long long int ans = ((1<<31)-1);
	int ans2 = -1;
	
	for(int i=0;i<=V1.size();i++)
	{
		if(i>c) continue;
		if((b-2*c+i)<0) goto u;
		
		if(V2.size()<c-i) goto u;
		if(V3.size()<c-i) goto u;
		if(T1.get(1,10000)<(b-2*c+i)) goto u;
		
		long long int s1,s2,s3,s4;
		if(i==0) s1 = 0;
		else s1 = S1[i-1];
		if(c-i==0) s2 = 0;
		else s2 = S2[c-i-1];
		if(c-i==0) s3 = 0;
		else s3 = S3[c-i-1];
		s4 = func((b-2*c+i));
		if(ans>s1+s2+s3+s4)
		{
			ans = s1+s2+s3+s4;
			ans2 = i;
		}
		
		u:;
		if(i==c) break;
		if(V2.size()>=c-i)
		{
			T1.add(V2[V2.size()-1].first,1);
			T2.add(V2[V2.size()-1].first,V2[V2.size()-1].first);
			V2.pop_back();
		}
		if(V3.size()>=c-i)
		{
			T1.add(V3[V3.size()-1].first,1);
			T2.add(V3[V3.size()-1].first,V3[V3.size()-1].first);
			V3.pop_back();
		}
	}
	if(ans2==-1)
	{
		printf("-1");
		return 0;
	}
	
	printf("%lld\n",ans);
	for(int i=0;i<ans2;i++) printf("%d ",W1[i].second);
	for(int i=0;i<c-ans2;i++) printf("%d ",W2[i].second);
	for(int i=0;i<c-ans2;i++) printf("%d ",W3[i].second);
	for(int i=ans2;i<W1.size();i++) W4.push_back(W1[i]);
	for(int i=c-ans2;i<W2.size();i++) W4.push_back(W2[i]);
	for(int i=c-ans2;i<W3.size();i++) W4.push_back(W3[i]);
	
	std::sort(W4.begin(),W4.end());
	//printf("%d %d??\n",S.size(),b-2*c+ans2);
	for(int i=0;i<(b-2*c+ans2);i++) printf("%d ",W4[i].second);
}
