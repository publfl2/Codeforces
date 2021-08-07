#include <stdio.h>

int check1[300010],check2[300010];
int next[300010];
long long int sizeX[300010],sizeY[300010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

int main()
{
	long long int ans = 0;
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		if(check1[b]==0&&check2[c]==0)
		{
			check1[b] = check2[c] = i;
			sizeX[i] = sizeY[i] = 1;
			next[i] = i;
			ans++;
		}
		else if(check1[b]==0)
		{
			int t = find(check2[c]);
			ans -= (sizeX[t]*sizeY[t]);
			sizeX[t]++;
			ans += (sizeX[t]*sizeY[t]);
			check1[b] = t;
		}
		else if(check2[c]==0)
		{
			int s = find(check1[b]);
			ans -= (sizeX[s]*sizeY[s]);
			sizeY[s]++;
			ans += (sizeX[s]*sizeY[s]);
			check2[c] = s;
		}
		else
		{
			int s = find(check1[b]);
			int t = find(check2[c]);
			if(s==t) goto u;
			ans -= (sizeX[s]*sizeY[s]);
			ans -= (sizeX[t]*sizeY[t]);
			sizeX[t] += sizeX[s];
			sizeY[t] += sizeY[s];
			next[s] = t;
			ans += (sizeX[t]*sizeY[t]);
		}
		u:;
		printf("%lld\n",ans);
	}
}
