#include <stdio.h>
#include <deque>
int x[110];
std::deque<int> D;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) D.push_back(i);
	for(int i=1;i<=b;i++)
	{
		x[i]%=(a-i+1);
		for(int j=1;j<=x[i];j++)
		{
			D.push_back(D.front());
			D.pop_front();
		}
		printf("%d ",D.front());
		D.pop_front();
	}
}
