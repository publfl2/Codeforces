#include <stdio.h>

char x[100010];
int check[100010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	int k = (a-11)/2;
	
	int count1 = 0,count2 = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='8'&& count2<k) count2++,check[i] = 1;
		if(x[i]!='8'&& count1<k) count1++,check[i] = 1;
	}
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0)
		{
			if(x[i]=='8') printf("YES");
			else printf("NO");
			return 0;
		}
	}
}
