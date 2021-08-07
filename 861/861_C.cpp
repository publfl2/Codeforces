#include <stdio.h>
#include <string.h>
char x[3010],y[6010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	int s = 1;
	int state=0;
	char b;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='a'||x[i]=='e'||x[i]=='u'||x[i]=='i'||x[i]=='o')
		{
			state = 0;
			y[s++] = x[i];
		}
		else
		{
			if(state==0)
			{
				state = 1;
				b = x[i];
				y[s++] = x[i];
			}
			else if(state==1)
			{
				if(b==x[i])
				{
					state = 2;
					y[s++] = x[i];
				}
				else
				{
					state = 3;
					y[s++] = x[i];
				}
			}
			else if(state==2)
			{
				if(b==x[i])
				{
					y[s++] = x[i];
				}
				else
				{
					y[s++] = ' ';
					y[s++] = x[i];
					state = 1;
				}
			}
			else if(state==3)
			{
				y[s++] = ' ';
				y[s++] = x[i];
				state = 1;
			}
		}
	}
	for(int i=1;i<s;i++) printf("%c",y[i]);
}
