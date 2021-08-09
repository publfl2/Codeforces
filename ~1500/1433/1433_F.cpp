#include <stdio.h>
#define MIN -12345678
 
int a,b,c;
int x[110][110];
int check2[71][71],check1[71][71][71][71];
int func1(int s, int t, int count, int rem)
{
	if(count*2>b) return MIN;
	if(t>b)
	{
		if(rem==0) return 0;
		else return MIN;
	}
	if(check1[s][t][count][rem]!=-1) return check1[s][t][count][rem];
	
	int s1 = func1(s,t+1,count,rem);
	int s2 = func1(s,t+1,count+1,((rem-x[s][t]%c)+c)%c)+x[s][t];
	return check1[s][t][count][rem] = s1>s2?s1:s2;
}
int func2(int s, int t)
{
	if(s>a)
	{
		if(t==0) return 0;
		else return MIN;
	}
	if(check2[s][t]!=-1) return check2[s][t];
	int ans = 0;
	for(int i=0;i<c;i++)
	{
		int k = func2(s+1,(t+i)%c) + func1(s,1,0,i);
		ans = ans>k?ans:k;
	}
	return check2[s][t] = ans;
}

int main()
{
	for(int i=0;i<=70;i++) for(int j=0;j<=70;j++) check2[i][j] = -1;
	for(int i=0;i<=70;i++) for(int j=0;j<=70;j++) for(int k=0;k<=35;k++) for(int l=0;l<=70;l++) check1[i][j][k][l] = -1;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
	printf("%d",func2(1,0));
}
