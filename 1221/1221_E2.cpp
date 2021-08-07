#include <stdio.h>
#include <string.h>
 
int a,b;
int check[300010],check2[300010];
 
int func(int k)
{
	if(k<=b-1) return 0;
	if(check2[k]) return check[k];
	
	int ans = 0;
	if(a<=k)
	{
		ans++;
		k -= a;
		if(k>=(b-1)) k -= (b-1);
		else k = 0;
	}
	if(b<=k)
	{
		ans--;
		k -= b;
		int c = k<a-1?k:a-1;
		int d = (c/b)*b;
		ans -= (c/b);
		k -= d;
	}
	
	check2[k] = 1;
	return check[k] = ans + func(k);
}
 
char x[300010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		int c = strlen(x+1);
		for(int i=0;i<=c+1;i++) check[i] = check2[i] = 0;
		
		x[c+1] = 'X';
		int p = 0;
		int ans = 0;
		for(int i=1;i<=c+1;i++)
		{
			if(x[i]=='X')
			{
				//p+1~i-1
				ans += func(i-1-(p+1)+1);
				p = i;
			}
		}
		if(ans>0) printf("YES\n");
		else printf("NO\n");
	}
}
