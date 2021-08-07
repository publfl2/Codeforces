#include <stdio.h>
#include <string.h>

char x[500010],y[500010];
int fail[500010];
int main()
{
	scanf("%s%s",x+1,y+1);
	int a = strlen(x+1);
	int b = strlen(y+1);
	
	fail[1] = 0;
	for(int i=2;i<=b;i++)
	{
		int s = i-1;
		while(1)
		{
			s = fail[s];
			if(y[s+1]==y[i])
			{
				fail[i] = s+1;
				break;
			}
			else if(s==0)
			{
				fail[i] = 0;
				break;
			}
		}
	}
	
	int init1 = 0, init2 = 0;
	for(int i=1;i<=b;i++) if(y[i]=='0') init1++;
	for(int i=1;i<=b;i++) if(y[i]=='1') init2++;
	int k = fail[b];
	int plus1 = 0, plus2 = 0;
	for(int i=k+1;i<=b;i++) if(y[i]=='0') plus1++;
	for(int i=k+1;i<=b;i++) if(y[i]=='1') plus2++;
	int limit1 = 0, limit2 = 0;
	for(int i=1;i<=a;i++) if(x[i]=='0') limit1++;
	for(int i=1;i<=a;i++) if(x[i]=='1') limit2++;
	int ans;
	if(init1<=limit1 && init2<=limit2)
	{
		for(int i=1;;i++)
		{
			if(init1+i*plus1<=limit1 && init2+i*plus2<=limit2);
			else
			{
				ans = i-1;
				break;
			}
		}
	}
	else
	{
		for(int i=1;i<=a;i++) printf("%c",x[i]);
		return 0;
	}
	
	for(int i=1;i<=b;i++) printf("%c",y[i]);
	for(int j=1;j<=ans;j++) for(int i=k+1;i<=b;i++) printf("%c",y[i]);
	int l1 = limit1-(init1+ans*plus1);
	int l2 = limit2-(init2+ans*plus2);
	for(int i=1;i<=l2;i++) printf("1");
	for(int i=1;i<=l1;i++) printf("0");
}
