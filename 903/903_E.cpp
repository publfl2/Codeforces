#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <functional>
char x[2510][5010];
char ans[5010];
int func(int s, int b)
{
	int count = 0;
	for(int i=1;i<=b;i++)
	{
		if(x[s][i]!=ans[i]) count++;
	}
	return count;
}

int check[5010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	
	int D[30]={};
	for(int i=1;i<=b;i++) D[x[1][i]-'a']++;
	for(int i=2;i<=a;i++)
	{
		int E[30]={};
		for(int j=1;j<=b;j++) E[x[i][j]-'a']++;
		for(int j=0;j<=25;j++)
		{
			if(D[j]!=E[j])
			{
				printf("-1");
				return 0;
			}
		}
	}
	
	int color = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			int count = 0;
			color++;
			for(int k=1;k<=b;k++)
			{
				if(x[i][k]!=x[j][k])
				{
					count++;
					check[k] = color;
				}
			}
			if(count==1)
			{
				printf("-1");
				return 0;
			}
			if(count>4)
			{
				printf("-1");
				return 0;
			}
			
			if(3<=count&&count<=4)
			{
				for(int k=1;k<=b;k++)
				{
					if(check[k]!=color)
					{
						if(ans[k]!=0&&ans[k]!=x[i][k])
						{
							printf("-1");
							return 0;
						}
						ans[k] = x[i][k];
					}
				}
			}
			else if(count==2)
			{
				int u,v;
				for(int k=1;k<=b;k++)
				{
					if(check[k]==color)
					{
						u = k;
						break;
					}
				}
				for(int k=b;k>=1;k--)
				{
					if(check[k]==color)
					{
						v = k;
						break;
					}
				}
				for(int k=1;k<=b;k++)
				{
					if(x[i][k]!=x[i][u]&&x[i][k]!=x[i][v])
					{
						if(ans[k]!=0&&ans[k]!=x[i][k])
						{
							printf("-1");
							return 0;
						}
						ans[k] = x[i][k];
					}
				}
			}
		}
	}
	
	
	/*for(int i=1;i<=b;i++)
	{
		if(ans[i]==0) printf("-1 ");
		else printf("%c ",ans[i]);
	}
	printf("\n");*/
	
	int count = 0;
	for(int i=1;i<=b;i++) if(ans[i]==0) count++;
	if(count>4)
	{
		for(int i=1;i<=b;i++)
		{
			if(ans[i]==0) printf("%c",x[1][i]);
			else printf("%c",ans[i]);
		}
		return 0;
	}
	else
	{
		char y[10]={};
		int z[10]={};
		int s = 1,t =1;

		int C[30]={};
		int control = 0;
		for(int i=1;i<=b;i++) C[x[1][i]-'a']++;
		for(int i=0;i<=25;i++) if(C[i]>=2) control = 1;
		for(int i=1;i<=b;i++) if(ans[i]!=0) C[ans[i]-'a']--;
		for(int i=1;i<=b;i++) if(ans[i]==0) z[s++] = i;
		
		for(int i=0;i<=25;i++)
		{
			while(C[i]>0)
			{
				y[t++] = i+'a';
				C[i]--;
			}
		}
		do{
			for(int i=1;i<s;i++) ans[z[i]] = y[i];
			/*for(int i=1;i<=b;i++) printf("%c",ans[i]);
			printf("!!\n");*/
			for(int i=1;i<=a;i++)
			{
				if(control==1)
				{
					if(func(i,b)>2) goto u;
				}
				else
				{
					if(func(i,b)!=2) goto u;
				}
			}
			
			for(int i=1;i<=b;i++) printf("%c",ans[i]);
			return 0;
			u:;
		}while(std::next_permutation(z+1,z+s));
		printf("-1");
	}
	
	//for(int i=1;i<=b;i++) if(ans[i]==0) ans[i] = x[1][i];
	//for(int i=1;i<=b;i++) printf("%c",ans[i]);
}
