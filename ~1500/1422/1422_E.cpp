#include <stdio.h>
#include <string.h>

int V1[100010][20];
int V2[100010][10];
int y[100010];
char x[100010];
int p1[100010],p2[100010];
int size[100010];

void copy(int s, int t)
{
	size[s] = size[t];
	for(int i=1;i<=10;i++) V1[s][i] = V1[t][i];
	for(int i=1;i<=2;i++) V2[s][i] = V2[t][i];
}
void insert(int k, int val)
{
	size[k]++;
	for(int i=10;i>=1;i--) V1[k][i] = V1[k][i-1];
	V1[k][1] = val;
	if(size[k]==1) V2[k][1] = V1[k][1];
	else if(size[k]==2) V2[k][1] = V1[k][1],V2[k][2] = V1[k][2];
}
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++) y[i] = x[i]-'a'+1;
	
	insert(a,y[a]);
	p1[a] = y[a];
	
	for(int i=a-1;i>=1;i--)
	{
		if(y[i]==y[i+1])
		{
			if(p1[i+2]==y[i])
			{
				if(p2[i+2]<y[i])
				{
					copy(i,i+2);
					p1[i] = p1[i+2];
					p2[i] = p2[i+2];
				}
				else
				{
					copy(i,i+2);
					p1[i] = y[i];
					p2[i] = p2[i+2];
					insert(i,y[i]);
					insert(i,y[i+1]);
				}
			}
			else
			{
				if(p1[i+2]<y[i])
				{
					copy(i,i+2);
					p1[i] = p1[i+2];
					p2[i] = p2[i+2];
				}
				else
				{
					copy(i,i+2);
					insert(i,y[i]);
					insert(i,y[i+1]);
					p1[i] = y[i];
					p2[i] = p1[i+2];
				}
			}
		}
		else
		{
			copy(i,i+1);
			insert(i,y[i]);
			p1[i] = y[i];
			p2[i] = p1[i+1];
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		printf("%d ",size[i]);
		if(size[i]<=10) for(int j=1;j<=size[i];j++) printf("%c",'a'+V1[i][j]-1);
		else
		{
			for(int j=1;j<=5;j++) printf("%c",'a'+V1[i][j]-1);
			printf("...");
			for(int j=1;j<=2;j++) printf("%c",'a'+V2[i][j]-1);
		}
		printf("\n");
	}
}
