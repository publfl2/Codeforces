#include <stdio.h>
#include <string.h>
long long int a;
long long int left(long long int k, long long int index = (a+1)/2,long long int size = a)
{
	if(k<index) return left(k,index-(size+1)/4,size/2);
	else if(k>index) return left(k,index+(size+1)/4,size/2);
	else
	{
		if(size==1) return index;
		else return index-(size+1)/4;
	}
}
long long int right(long long int k, long long int index = (a+1)/2,long long int size = a)
{
	if(k<index) return right(k,index-(size+1)/4,size/2);
	else if(k>index) return right(k,index+(size+1)/4,size/2);
	else
	{
		if(size==1) return index;
		else return index+(size+1)/4;
	}
}
long long int up(long long int k, long long int index = (a+1)/2,long long int size = a, long long int parent = (a+1)/2)
{
	if(k<index) return up(k,index-(size+1)/4,size/2,index);
	else if(k>index) return up(k,index+(size+1)/4,size/2,index);
	else return parent;
}
char x[100010];
int main()
{
	int b,d;
	long long int c;
	scanf("%I64d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		scanf("%I64d%s",&c,x+1);
		d = strlen(x+1);
		for(int j=1;j<=d;j++)
		{
			if(x[j]=='U') c = up(c);
			else if(x[j]=='L') c = left(c);
			else if(x[j]=='R') c = right(c);
		}
		printf("%I64d\n",c);
	}
}
