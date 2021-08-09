#include <stdio.h>
#include <bitset>
std::bitset<510> A1[510],A2[510],B1[510],B2[510];
int main()
{
	int a,b,c,d,e;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		scanf("%d%d%d",&c,&d,&e);
		if(e==0)
		{
			A1[c].set(d,true);
			A2[d].set(c,true);
		}
		else
		{
			B1[c].set(d,true);
			B2[d].set(c,true);
		}
	}
}
