#include <stdio.h>
#define MAX 12345678
int a;
int x[510];

int check[510][510], check2[510][1010];
int func(int s, int t)
{
	if(x[s]>t) return MAX;
	else if(x[s]==t) return s;
	else if(check[s][t]) return check[s][t];
	else
	{
		int p = s+1;
		for(int i=x[s];i<t;i++)
		{
			if(p>a) return check[s][t] = MAX;
			p = func(p,i) + 1;
			if(p>=MAX) return check[s][t] = MAX;
		}
		return check[s][t] = p-1;
	}
}

int func2(int s, int t)
{
	if(s>a) return 0;
	if(check2[s][t]) return check2[s][t];
	int s1 = MAX,s2 = MAX,s3 = MAX, s4 = MAX;
	if(x[s]==t) s1 = func2(s+1,t+1);
	s2 = func2(s+1,x[s])+1;
	if(func(s+1,x[s])<=a) s3 = func2(func(s+1,x[s])+1,x[s]+1)+1;
	if(func(s,t)<=a) s4 = func2(func(s,t)+1,t+1);
	
	int k = s1<s2?s1<s3?s1:s3:s2<s3?s2:s3;
	k = k<s4?k:s4;
	return check2[s][t] = k;
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	printf("%d",func2(1,0));
}
