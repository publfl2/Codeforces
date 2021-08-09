#include <stdio.h>

long long int MAX = 1;
struct segTree{
	long long int value[4000010];
	long long int lazy[4000010];
	void addValue(int L, int R, int val, int l=1, int r=1000000, int v=1)
	{
		if(L<=l&&r<=R) value[v]+=val, lazy[v]+=val;
		else if(r<L) return;
		else if(R<l) return;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]>0)
			{
				value[2*v] += lazy[v], lazy[2*v]+=lazy[v];
				value[2*v+1] += lazy[v], lazy[2*v+1]+=lazy[v];
				lazy[v] = 0;
			}
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	long long int getMin(int L, int R, int l=1, int r=1000000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MAX;
		else if(R<l) return MAX;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]>0)
			{
				value[2*v] += lazy[v], lazy[2*v]+=lazy[v];
				value[2*v+1] += lazy[v], lazy[2*v+1]+=lazy[v];
				lazy[v] = 0;
			}
			long long int s1 = getMin(L,R,l,h,2*v);
			long long int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T2,T3;

long long int r1,r2,r3,d;
long long int first[1000010],second[1000010];
int main()
{
	for(int i=1;i<=18;i++) MAX*=10;
	
	long long int a;
	scanf("%lld%lld%lld%lld%lld",&a,&r1,&r2,&r3,&d);
	for(int i=1;i<=a;i++)
	{
		long long int b;
		scanf("%lld",&b);
		first[i] = r1*b+r3<r3*b+r3?r1*b+r3:r3*b+r3;
		
		long long int c = r1<r2?r3<r1?r3:r1:r3<r2?r3:r2;
		second[i] = r1*(b+1)<r2?r1*(b+1):r2;
		second[i] = second[i]<r3*b+r1?second[i]:r3*b+r1;
		second[i] += c;
	}
	
	long long int T1 = 0;
	for(long long int i=1;i<=a;i++)
	{
		long long int t = first[i]<second[i]?first[i]:second[i];
		
		long long int val1 = T1 + first[i];
		long long int val2 = T2.getMin(1,i-1)+2*i*d+t; // -2i
		long long int val4 = T1 + second[i] + 2*d;
		long long int val3 = T1 + second[i];
		
		if(i==a)
		{
			long long int ans1 = T3.getMin(1,a-1)+a*d+first[i];
			long long int ans2 = T3.getMin(1,a-1)+a*d+second[i]+2*d;
			long long int ans3 = T1 + first[i];
			long long int ans4 = T1 + second[i] + 2*d;
			long long int ans5 = T2.getMin(1,a-1)+2*a*d+second[i];
			long long int ans6 = T2.getMin(1,a-1)+2*a*d+first[i];
			long long int min = ans1;
			min = min<ans2?min:ans2;
			min = min<ans3?min:ans3;
			min = min<ans4?min:ans4;
			min = min<ans5?min:ans5;
			min = min<ans6?min:ans6;
			printf("%lld",min+(a-1)*d);
			return 0;
		}
		
		T1 = val1<val2?val1<val4?val1:val4:val2<val4?val2:val4;
		T2.addValue(1,i-1,t);
		T2.addValue(i,i,val3-2*i*d);
		T3.addValue(1,i-1,t);
		T3.addValue(i,i,val3-i*d);
	}
}
