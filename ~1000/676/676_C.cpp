#include <stdio.h>
char x[100010];
int a,b,ans;
void func2(int h, char target,int L,int R)
{
	int s = 0, t = 0,i,j,count;
	for(i=h;i<=R;i++)
	{
		if(x[i]==target);
		else
		{
			if(t<b) t++;
			else break;
		}
	}
	i--;
	if(t<b)
	{
		for(j=h-1;j>=L;j--)
		{
			if(x[j]==target);
			else
			{
				if(s<b-t) s++;
				else break;
			}
		}
		j++;
	}
	else j = h;
	ans = ans>i-j?ans:i-j;
	
	while(1)
	{
		if(i<L)
		{
			i = L;
			goto u;
		}
		if(x[i]==target) i--;
		else
		{
			i--;
			count = 0;
			while(1)
			{
				j--;
				if(j<L)
				{
					j = L;
					goto u;
				}
				if(x[j]==target);
				else if(count==0) count++;
				else 
				{
					j++;
					ans = ans>i-j?ans:i-j;
					break;
				}
			}
		}
	}
	u:;
	ans = ans>i-j?ans:i-j;
}
void func(int s, int t)
{
	if(s>t) return;
	int h = (s+t)/2;
	func2(h,'a',s,t);
	func2(h,'b',s,t);
	func(s,h-1);
	func(h+1,t);
}
int main()
{
	scanf("%d%d%s",&a,&b,x+1);
	func(1,a);
	printf("%d",ans+1);
}
