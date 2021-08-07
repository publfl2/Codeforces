#include <stdio.h>


int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	for(int i=1;i<=a;i++) check[y[i]] = i;
	for(int i=1;i<=a;i++)
	{
		next[i] = check[x[i]];
		prev[check[x[i]]] = i;
	}
	
	T.init();
	for(int i=1;i<=a;i++) T.setValue(i,next[i]);
}