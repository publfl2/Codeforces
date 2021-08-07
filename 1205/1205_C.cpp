#include <stdio.h>

int getQuery(int x1, int y1, int x2, int y2)
{
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	int a;
	scanf("%d",&a);
	return a;
}

struct str{
	int x1;
	int y1;
	int x2;
	int y2;
}x[10];

int check[60][60][60][60];
int ans[60][60];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) ans[i][j] = -1;
	
	ans[1][1] = 1 , ans[a][a] = 0;
	for(int i=3;i<a;i+=2)
	{
		int s = getQuery(i-2,i-2,i,i);
		if(s==1) ans[i][i] = ans[i-2][i-2];
		else ans[i][i] = 1 - ans[i-2][i-2];
	}
	
	int start = 1;
	for(int i=1;i<a;i+=2)
	{
		if((ans[i][i]+ans[i+2][i+2])%2==1)
		{
			start = i;
			break;
		}
	}
	
	int control = 1;
	ans[start][start+1] = 0; // initialize
	int q = getQuery(start,start+1,start+1,start+2);
	if(q==1) ans[start+1][start+2] = ans[start][start+1];
	else ans[start+1][start+2] = 1 - ans[start][start+1];
	q = getQuery(start+1,start,start+1,start+2);
	if(q==1) ans[start+1][start] = ans[start+1][start+2];
	else ans[start+1][start] = 1 - ans[start+1][start+2];
	q = getQuery(start+1,start,start+2,start+1);
	if(q==1) ans[start+2][start+1] = ans[start+1][start];
	else ans[start+2][start+1] = 1 - ans[start+1][start];
	
	
	if(ans[start][start+1]!=ans[start+1][start])
	{
		q = getQuery(start,start,start+1,start+2);
		if(q==1&&ans[start+1][start+2]!=ans[start][start]) control = -1;
		if(q==-1&&ans[start+1][start+2]==ans[start][start]) control = -1;
	}
	else if(ans[start+1][start+2]!=ans[start+2][start+1])
	{
		q = getQuery(start,start+1,start+2,start+2);
		if(q==1&&ans[start][start+1]!=ans[start+2][start+2]) control = -1;
		if(q==-1&&ans[start][start+1]==ans[start+2][start+2]) control = -1;
	}
}
