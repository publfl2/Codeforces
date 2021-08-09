#include <stdio.h>
long long int time = 1;
long long int b,c;
int ans=0;
long long int size(long long int k)
{
	if(k<=1) return 1;
	return 2*size(k/2)+1;
}
void func(long long int k)
{
	if(time>c) return;
	if(k<=1)
	{
		if(b<=time&&time<=c) ans+=k;
		time++;
		return;
	}
	if(size(k/2)+time<b) time+=size(k/2);
	else func(k/2);
	if(b<=time&&time<=c) ans+=k%2;
	time++;
	func(k/2);
}
int main()
{
	long long int a;
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	func(a);
	printf("%d",ans);
}
