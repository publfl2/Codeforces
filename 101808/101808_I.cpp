#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		if(a%2==1)
		{
			int sum = 0;
			for(int i=1;i<=a;i++) sum+=x[i];
			if(sum%2==1) printf("Yalalov\n");
			else printf("Shin\n");
		}
		else
		{
			int min = x[1];
			for(int i=2;i<=a;i++) min = min<x[i]?min:x[i];
			int sum = 0;
			for(int i=1;i<=a;i++) sum += (x[i]-min);
			if(min%2==1) printf("Yalalov\n");
			else
			{
				if(sum%2==1) printf("Yalalov\n");
				else printf("Shin\n");
			}
		}
	}
}
