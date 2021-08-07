#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a==12) a = 0;
	int t1,t2;
	scanf("%d%d",&t1,&t2);
	if(t1==12) t1 = 0;
	if(t2==12) t2 = 0;
	int a1,b1,c1;
	if(b==0&&c==0) a1 = 0;
	else a1 = 1;
	if(c==0&&b%5==0) b1 = 0;
	else b1 = 1;
	if(c%5==0) c1 = 0;
	else c1 = 1;
	b/=5,c/=5;
	t1++;
	while(1)
	{
		if(t1==12) t1 = 0;
		if(t1==c+c1||t1==a+a1||t1==b+b1)
		{
			t1-=2;
			break;
		}
		else if(t1==t2)
		{
			printf("YES");
			return 0;
		}
		t1++;
	}
	while(1)
	{
		if(t1==-1) t1 = 11;
		if(t1==c||t1==a||t1==b)
		{
			printf("NO");
			return 0;
		}
		else if(t1==t2)
		{
			printf("YES");
			return 0;
		}
		t1--;
	}
}
