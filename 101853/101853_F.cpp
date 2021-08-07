#include <stdio.h>

struct time{
	int hour;
	int minute;
}start[100010],end[100010];

time operator+(time A, time B)
{
	time C = {A.hour+B.hour,A.minute+B.minute};
	C.hour += C.minute/60;
	C.minute %= 60;
	return C;
}

time operator-(time A, time B)
{
	time C = {A.hour-B.hour-1,A.minute-B.minute+60};
	C.hour += C.minute/60;
	C.minute %= 60;
	return C;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++)
		{
			int c,d;
			scanf("%d:%d",&c,&d);
			start[i] = {c,d};
			scanf("%d:%d",&c,&d);
			end[i] = {c,d};
		}
		
		time sum = {0,0};
		for(int i=1;i<=a;i++) sum = sum + (end[i]-start[i]);
		if(sum.hour>=b) printf("YES\n");
		else printf("NO\n");
	}
}
