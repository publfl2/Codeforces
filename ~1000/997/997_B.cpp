#include <stdio.h>
#include <vector>
#include <algorithm>

int save[7010][10010];
int size[7010];
int ans[7010];
int main()
{
	int a;
	for(int i=0;i<=4;i++)
	{
		for(int j=0;j<=1;j++)
		{
			for(int k=0;k<=4;k++)
			{
				for(int l=0;l<=100;l++)
				{
					save[i+5*j+10*k+50*l][size[i+5*j+10*k+50*l]++] = i+j+k+l;
				}
			}
		}
	}
	for(int i=0;i<=7000;i++) std::sort(save[i],save[i]+size[i]);
	
	for(int i=0;i<=7000;i++)
	{
		for(int j=1;j<size[i];j++) if(save[i][j]==save[i][j-1])ans[save[i][j]]++;
	}
	for(int i=0;i<=100;i++) printf("%lld ",ans[i]);
}
