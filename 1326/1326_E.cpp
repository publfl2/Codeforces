#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i].x0);
	for(int i=1;i<=a;i++) x[i].y0 = i;
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	
	std::sort(x+1,x+a+1,cmp);
	
	int p = 0;
	for(int i=1;i<=a;i++)
	{
		while(p)
		{
			T.insert(y[p]);
			int v = S.find(y[p]+1,1,a);
			if(v>0)
			{
				T.insert(v);
			}
			if(T.find(x[i].y0+1,a)==1) break;
			else ans[p] = x[i].x0;
		}
		
	}
}
