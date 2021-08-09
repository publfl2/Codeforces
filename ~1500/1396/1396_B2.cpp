#include <stdio.h>

int check[20][20][20][20][20][10];
int func(int s1, int s2, int s3, int s4,int s5, int prev)
{
	if(check[s1][s2][s3][s4][s5][prev]) return check[s1][s2][s3][s4][s5][prev];
	int t1=1,t2=1,t3=1,t4=1,t5=1;
	if(s1>0&&prev!=1) t1 = func(s1-1,s2,s3,s4,s5,1);
	if(s2>0&&prev!=2) t2 = func(s1,s2-1,s3,s4,s5,2);
	if(s3>0&&prev!=3) t3 = func(s1,s2,s3-1,s4,s5,3);
	if(s4>0&&prev!=4) t4 = func(s1,s2,s3,s4-1,s5,4);
	if(s5>0&&prev!=5) t5 = func(s1,s2,s3,s4,s5-1,5);
	if(t1==2||t2==2||t3==2||t4==2||t5==2) return check[s1][s2][s3][s4][s5][prev] = 1;
	else return check[s1][s2][s3][s4][s5][prev] = 2;
}
int main()
{
	for(int i=1;i<=10;i++)
	{
		for(int j=i;j<=10;j++)
		{
			for(int k=j;k<=10;k++)
			{
				for(int l=k;l<=10;l++)
				{
					for(int x=l;x<=10;x++)
					{
						int s = func(i,j,k,l,x,0);
						int t = 0;
						if(x>i+j+k+l) t = 1;
						else if ((i+j+k+l-x)%2==0) t = 2;
						else t = 1;
						printf("%d %d %d %d %d: %d %d!!\n",i,j,k,l,x,s,t);
						if(s!=t) return 0;
					}
				}
			}
		}
	}
}
