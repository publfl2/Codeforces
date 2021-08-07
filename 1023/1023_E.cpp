#include <stdio.h>
#include <vector>

char x[10];
int a;
int getQuery(int x1, int y1, int x2, int y2)
{
	if(x1==0) return 0;
	if(y1==0) return 0;
	if(x2==a+1) return 0;
	if(y2==a+1) return 0;
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	
	scanf("%s",x+1);
	if(x[1]=='Y') return 1;
	else return 0;
}

char ans[510][510];

std::vector<char> V;
int main()
{
	scanf("%d",&a);
	
	int x1=1,y1=1;
	int x2,y2;
	for(int i=1;i<=a;i++)
	{
		int s1 = getQuery(1,1,i,a-i+1);
		int s2 = getQuery(i,a-i+1,a,a);
		if(s1==1&&s2==1)
		{
			x2 = i;
			y2 = a-i+1;
			break;
		}
	}
	for(int i=1;i<=a-1;i++)
	{
		int s1 = getQuery(x1,y1,x2+1,y2);
		if(s1==1)
		{
			int s2 = getQuery(x1+1,y1,x2+1,y2);
			if(s2==1)
			{
				ans[x1][y1] = 'D';
				ans[x2][y2] = 'D';
				x1++,x2++;
			}
			else
			{
				ans[x1][y1] = 'R';
				ans[x2][y2] = 'D';
				y1++,x2++;
			}
		}
		else
		{
			int s2 = getQuery(x1+1,y1,x2,y2+1);
			if(s2==1)
			{
				ans[x1][y1] = 'D';
				ans[x2][y2] = 'R';
				x1++,y2++;
			}
			else
			{
				ans[x1][y1] = 'R';
				ans[x2][y2] = 'R';
				y1++,y2++;
			}
		}
	}
	
	int s = 1, t = 1;
	for(int i=1;i<=2*a-2;i++)
	{
		V.push_back(ans[s][t]);
		if(ans[s][t]=='D') s++;
		else t++;
	}
	printf("! ");
	fflush(stdout);
	for(int i=0;i<V.size();i++) printf("%c",V[i]);
	fflush(stdout);
}
