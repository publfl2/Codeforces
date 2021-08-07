#include <stdio.h>
#include <algorithm>

int a,b;
char x[1010][1010];
int y[1010],z[1010],y2[1010],z2[1010];
int save[10010],check[5000010];
int control = 0;
int func1(int s, int t)
{
	int C = 0;
	for(int j=1;j<=b;j++)
	{
		if(x[s][j]=='<'&&x[t][j]=='>') // s<t
		{
			if(C!=0 && C!=1) control = 1;
			C = 1;
		}
		if(x[s][j]=='<'&&x[t][j]=='=') // s<t
		{
			if(C!=0 && C!=1) control = 1;
			C = 1;
		}
		if(x[s][j]=='='&&x[t][j]=='>') // s<t
		{
			if(C!=0 && C!=1) control = 1;
			C = 1;
		}
		if(x[s][j]=='='&&x[t][j]=='=') // s=t
		{
			if(C!=0 && C!=2) control = 1;
			C = 2;
		}
		if(x[s][j]=='='&&x[t][j]=='<') // s>t
		{
			if(C!=0 && C!=3) control = 1;
			C = 3;
		}
		if(x[s][j]=='>'&&x[t][j]=='<') // s>t
		{
			if(C!=0 && C!=3) control = 1;
			C = 3;
		}
		if(x[s][j]=='>'&&x[t][j]=='=') // s>t
		{
			if(C!=0 && C!=3) control = 1;
			C = 3;
		}
	}
	return C;
}

int func2(int s, int t)
{
	int C = 0;
	for(int j=1;j<=a;j++)
	{
		if(x[j][s]=='<'&&x[j][t]=='>') // s<t
		{
			if(C!=0 && C!=3) control = 1;
			C = 3;
		}
		if(x[j][s]=='<'&&x[j][t]=='=') // s<t
		{
			if(C!=0 && C!=3) control = 1;
			C = 3;
		}
		if(x[j][s]=='='&&x[j][t]=='>') // s<t
		{
			if(C!=0 && C!=3) control = 1;
			C = 3;
		}
		if(x[j][s]=='='&&x[j][t]=='=') // s=t
		{
			if(C!=0 && C!=2) control = 1;
			C = 2;
		}
		if(x[j][s]=='='&&x[j][t]=='<') // s>t
		{
			if(C!=0 && C!=1) control = 1;
			C = 1;
		}
		if(x[j][s]=='>'&&x[j][t]=='<') // s>t
		{
			if(C!=0 && C!=1) control = 1;
			C = 1;
		}
		if(x[j][s]=='>'&&x[j][t]=='=') // s>t
		{
			if(C!=0 && C!=1) control = 1;
			C = 1;
		}
	}
	return C;
}


bool cmp1(int s, int t)
{
	int C = func1(s,t);
	if(C==1) return true;// s<t
	if(C==3) return false;// s>t
	return true; // s=t
}

bool cmp2(int s, int t)
{
	int C = func2(s,t);
	if(C==1) return true;// s<t
	if(C==3) return false;// s>t
	return true; // s=t
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++) y[i] = i;
	for(int i=1;i<=b;i++) z[i] = i;
	std::sort(y+1,y+a+1,cmp1);
	std::sort(z+1,z+b+1,cmp2);
	if(control==1)
	{
		printf("No");
		return 0;
	}
	y2[y[1]] = 2000;
	for(int i=2;i<=a;i++)
	{
		int C = func1(y[i-1],y[i]);
		if(C==2||C==0) y2[y[i]] = y2[y[i-1]];
		else y2[y[i]] = y2[y[i-1]] + 2000;
	}
	for(int i=1;i<=b;i++)
	{
		int s = z[i-1], t = z[i];
		int min = 1, max = 4000000;
		for(int j=1;j<=a;j++)
		{
			if(x[j][t]=='<') min = min>y2[j]+1?min:y2[j]+1;
			if(x[j][t]=='>') max = max<y2[j]-1?max:y2[j]-1;
			if(x[j][t]=='=')
			{
				max = max<y2[j]?max:y2[j];
				min = min>y2[j]?min:y2[j];
			}
		}
		if(min>max) control = 1;
		
		if(i==1)
		{
			z2[t] = min;
			continue;
		}
		int C = func2(s,t);
		if(C==2||C==0)
		{
			if(min<=z2[s]&&z2[s]<=max) z2[t] = z2[s];
			else control = 1;
		}
		else
		{
			int m = min>z2[s]+1?min:z2[s]+1;
			if(m>max) control = 1;
			z2[t] = m;
		}
	}
	
	if(control==1)
	{
		printf("No");
		return 0;
	}
	
	int p = 1;
	for(int i=1;i<=a;i++) save[p++] = y2[i];
	for(int i=1;i<=b;i++) save[p++] = z2[i];
	std::sort(save+1,save+p);
	
	int p2 = 1;
	for(int i=1;i<p;i++) if(check[save[i]]==0) check[save[i]] = p2++;
	
	printf("Yes\n");
	for(int i=1;i<=a;i++) printf("%d ",check[y2[i]]);
	printf("\n");
	for(int i=1;i<=b;i++) printf("%d ",check[z2[i]]);
}
