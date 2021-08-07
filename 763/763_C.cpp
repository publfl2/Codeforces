#include <stdio.h>
#include <algorithm>
long long int x[200010],check[200010],y[200010];
long long int abs(long long int k)
{
	return k>0?k:-k;
}
long long int inverse(long long int a, long long int p)
{
	long long int k = p-2;
	long long int s = 1,t = a;
	while(k)
	{
		if(k%2==1) s*=t,s%=p;
		t*=t,t%=p;
		k/=2;
	}
	return s;
}
long long int search(long long int L, long long int R, long long int key)
{
	long long int l = L, r = R;
	while(l<=r)
	{
		long long int h = (l+r)/2;
		if(x[h]==key) return h;
		else if(x[h]>key) r = h-1;
		else l = h+1;
	}
	return 0;
}
long long int search2(long long int L, long long int R, long long int key)
{
	long long int l = L, r = R;
	while(l<=r)
	{
		long long int h = (l+r)/2;
		if(y[h]==key) return h;
		else if(y[h]>key) r = h-1;
		else l = h+1;
	}
	return 0;
}
int main()
{
	long long int a,b;
	scanf("%I64d%I64d",&a,&b);
	if(b==1)
	{
		long long int c;
		scanf("%I64d",&c);
		printf("%I64d 0",c);
		return 0;
	}
	for(long long int i=1;i<=b;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+b+1);
	if(a>=2*b)
	{
		long long int d = abs(x[2]-x[1])%a;
		// d = kd(mod a)
		long long int s = 0;
		for(long long int i=1;i<=b;i++) s += search(1,b,(x[i]+d)%a)?1:0;
		//s = b-k
		long long int k = b-s;
		long long int dist = d*inverse(k,a)%a;
		for(long long int i=-b+1;i<=b-1;i++)
		{
			long long int f = search(1,b,(x[1]+i*dist+b*a)%a);
			if(f!=0) check[f] = i;
		}
		
		long long int m = 0;
		for(long long int i=2;i<=b;i++)
		{
			if(check[i]==0)
			{
				printf("-1");
				return 0;
			}
			else m = m<check[i]?m:check[i];
		}
		printf("%I64d %I64d",(x[1]+m*dist+b*a)%a,dist);
	}
	else
	{
		long long int count = 1;
		for(long long int i=1;i<=b;i++) check[x[i]] = 1;
		for(long long int i=0;i<a;i++) if(check[i]==0) y[count++] = i;
		count--;
		for(long long int i=0;i<=a;i++) check[i] = 0;
		
		long long int d = abs(y[2]-y[1])%a;
		// d = kd(mod a)
		long long int s = 0;
		for(long long int i=1;i<=count;i++) s += search2(1,count,(y[i]+d)%a)?1:0;
		//s = b-k
		long long int k = count-s;
		long long int dist = d*inverse(k,a)%a;
		for(long long int i=-count+1;i<=count-1;i++)
		{
			long long int f = search2(1,count,(y[1]+i*dist+count*a)%a);
			if(f!=0) check[f] = i;
		}
		
		long long int m = 0;
		for(long long int i=2;i<=count;i++)
		{
			if(check[i]==0)
			{
				printf("-1");
				return 0;
			}
			else m = m<check[i]?m:check[i];
		}
		printf("%I64d %I64d",(y[1]+m*dist+count*a-b*dist+b*a)%a,dist);
	}
}
