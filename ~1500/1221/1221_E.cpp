#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>


int a,b;
char x[300010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int count1 = 0, count2 = 0, count3=0;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		int c = strlen(x+1);
		
		x[c+1] = 'X';
		int p = 0;
		int ans = 0;
		for(int i=1;i<=c+1;i++)
		{
			if(x[i]=='X')
			{
				//p+1~i-1
				int s = (i-1)-(p+1)+1;
				if(s>0)
				{
					if(a<=s&&s<=a+2*(b-1)) count1++;
					else if(2*a<=s&&s<=2*a+3*(b-1)) count3++;
					else if(s>=b) count2++;
				}
				p = i;
			}
		}
		if(count1%2==0)
		{
			if(count3>0)
			{
				if(count2==0) printf("YES\n");
				else printf("NO\n");
			}
			else printf("NO\n");
		}
		else
		{
			if(count2>0) printf("NO\n");
			else printf("YES\n");
		}
	}
}
