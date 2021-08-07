#include <stdio.h>
#include <vector>
int next[40010],y[20010],prev[20010],temp[40010];
char x[20010];

int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		for(int j=1;j<=b/4;j++)
		{
			int c;
			if('0'<=x[j]&&x[j]<='9') c = x[j]-'0';
			else c = x[j]-'A'+10;
			y[4*j-3] = c/8;
			y[4*j-2] = (c/4)%2;
			y[4*j-1] = (c/2)%2;
			y[4*j] = (c/1)%2;
		}
		y[0] = 0, prev[0] = 0;
		for(int j=1;j<=b;j++) if(y[j]==1) ans++;
		for(int j=1;j<=b;j++) if(y[j]==1) next[b+j] = b+j;
		
		for(int j=1;j<=b;j++)
		{
			if(y[j]==1 && prev[j]==1)
			{
				int s = find(j);
				int t = find(b+j);
				if(s==t) continue;
				ans--;
				next[s] = t;
			}
			if(y[j]==1 && y[j-1]==1)
			{
				int s = find(b+j);
				int t = find(b+j-1);
				if(s==t) continue;
				ans--;
				next[s] = t;
			}
		}
		for(int j=1;j<=b;j++) prev[j] = y[j];
		for(int j=1;j<=b;j++) if(y[j]==1) temp[j] = find(b+j);
		for(int j=1;j<=2*b;j++) next[j] = 0;
		for(int j=1;j<=b;j++) if(y[j]==1) next[j] = temp[j]-b;
	}
	printf("%d",ans);
}
