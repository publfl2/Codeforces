#include <stdio.h>

int main()
{
	int ans = 0;
	for(int i=83160;i<=83160;i++)
	{
		int S = 0;
		for(int j=1;j*j<=i;j++)
		{
			if(i%j==0) S+=2;
		}
		ans = ans>S?ans:S;
	}
	printf("%d",ans);
}
