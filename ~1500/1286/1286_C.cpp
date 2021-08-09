#include <stdio.h>
#include <string.h>

int x[5][110];
char temp[10010][110];
int count[110][30];
int count2[110][110][30];
int a;

void clear()
{
	for(int i=0;i<=a;i++) for(int j=0;j<26;j++) count[i][j] = 0;
	for(int i=0;i<=a;i++) for(int j=0;j<=a;j++) for(int k=0;k<26;k++) count2[i][j][k] = 0;
}
void getQuery(int k, int L, int R)
{
	printf("? %d %d\n",L,R);
	fflush(stdout);
	int a = (R-L+1);
	int N = a*(a+1)/2;
	for(int i=1;i<=N;i++) scanf("%s",temp[i]+1);
	
	for(int i=1;i<=N;i++)
	{
		int b = strlen(temp[i]+1);
		for(int j=1;j<=b;j++) count[b][temp[i][j]-'a']++;
	}
	
	for(int j=0;j<26;j++) count2[1][a][j] = count[a][j];
	
	for(int i=a-1;i>=1;i--)
	{
		int r = i, l = (a-i+1);
		if(l>r) break;
		for(int j=0;j<26;j++) count2[l][r][j] = count[i][j] - count[i+1][j];
	}
	
	for(int j=0;j<26;j++)
	{
		if(count2[1][a][j]-count2[2][a-1][j]==2)
		{
			x[k][(L-1)+1] = j;
			x[k][(L-1)+a] = j;
			break;
		}
		else if(count2[1][a][j]-count2[2][a-1][j]==1)
		{
			if(x[k][(L-1)+1]==-1) x[k][(L-1)+1] = j;
			else x[k][(L-1)+a] = j;
		}
	}
	
	for(int i=a-1;i>=1;i--)
	{
		int r = i, l = (a-i+1);
		if(l==r)
		{
			for(int j=0;j<26;j++)
			{
				if(count2[l][r][j]==1)
				{
					x[k][(L-1)+l] = j;
					break;
				}
			}
			break;
		}
		
		for(int j=1;j<=N;j++)
		{
			int tempCount[30]={};
			
			int b = strlen(temp[j]+1);
			if(b==(l-r+1))
			{
				for(int u=1;u<=b;u++) tempCount[temp[j][u]-'a']++;
				for(int u=0;u<26;u++) tempCount[u] -= count2[l+1][r-1][u];
				
				// 1
				for(int u=1;u<l;u++) tempCount[x[k][(L-1)+u]]--;
				for(int u=0;u<26;u++)
				{
					if(tempCount[u]<0) goto v1;
					if(tempCount[u]>1) goto v1;
				}
				for(int u=0;u<26;u++) if(tempCount[u]==1) x[k][(L-1)+l] = u;
				v1:;
				for(int u=1;u<l;u++) tempCount[x[k][(L-1)+u]]++;
				
				// 2
				for(int u=r+1;u<=a;u++) tempCount[x[k][(L-1)+u]]--;
				for(int u=0;u<26;u++)
				{
					if(tempCount[u]<0) goto v2;
					if(tempCount[u]>1) goto v2;
				}
				for(int u=0;u<26;u++) if(tempCount[u]==1) x[k][(L-1)+r] = u;
				v2:;
			}
			
		}
	}
	
}

int L1,L2,L3,R1,R2,R3;
int y[110];
int func(int t1, int t2, int t3)
{
	for(int i=1;i<=a;i++) y[i] = -1;
	
	if(t1==1)
	{
		for(int i=L1;i<=R1;i++)
		{
			if(y[i]!=-1 && y[i]!=x[1][i]) return 0;
			y[i] = x[1][i];
		}
	}
	else
	{
		for(int i=L1;i<=R1;i++)
		{
			if(y[R1-i+L1]!=-1 && y[R1-i+L1]!=x[1][i]) return 0;
			y[R1-i+L1] = x[1][i];
		}
	}
	
	if(t2==1)
	{
		for(int i=L2;i<=R2;i++)
		{
			if(y[i]!=-1 && y[i]!=x[2][i]) return 0;
			y[i] = x[2][i];
		}
	}
	else
	{
		for(int i=L2;i<=R2;i++)
		{
			if(y[R2-i+L2]!=-1 && y[R2-i+L2]!=x[2][i]) return 0;
			y[R2-i+L2] = x[2][i];
		}
	}
	
	if(t3==1)
	{
		for(int i=L3;i<=R3;i++)
		{
			if(y[i]!=-1 && y[i]!=x[3][i]) return 0;
			y[i] = x[3][i];
		}
	}
	else
	{
		for(int i=L3;i<=R3;i++)
		{
			if(y[R3-i+L3]!=-1 && y[R3-i+L3]!=x[3][i]) return 0;
			y[R3-i+L3] = x[3][i];
		}
	}
	return 1;
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=3;i++) for(int j=1;j<=a;j++) x[i][j] = -1;
	int k = a/4;
	if(a%4==0)
	{
		L1 = 1, L2 = k+1, L3 = 2*k+1;
		R1 = 2*k, R2 = 3*k, R3 = 4*k;
	}
	else if(a%4==1)
	{
		L1 = 1, L2 = k+1, L3 = 2*k+1;
		R1 = 2*k, R2 = 3*k, R3 = 4*k+1;
	}
	else if(a%4==2)
	{
		L1 = 1, L2 = k+1, L3 = 2*k+2;
		R1 = 2*k+1, R2 = 3*k+1, R3 = 4*k+2;
	}
	else if(a%4==3)
	{
		L1 = 1, L2 = k+1, L3 = 2*k+2;
		R1 = 2*k+1, R2 = 3*k+2, R3 = 4*k+3;
	}
	
	clear();
	if(L1<=R1) getQuery(1,L1,R1);
	clear();
	if(L2<=R2) getQuery(2,L2,R2);
	clear();
	if(L3<=R3) getQuery(3,L3,R3);
	
	
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
		{
			for(int k=1;k<=2;k++)
			{
				if(func(i,j,k)==1)
				{
					printf("! ");
					for(int i=1;i<=a;i++) printf("%c",y[i]+'a');
					fflush(stdout);
					return 0;
				}
			}
		}
	}
	
	fflush(stdout);
}
