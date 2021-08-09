#include <stdio.h>

long long int x[5];
int p[5];
int main()
{
	long long int a,b,c;
	scanf("%lld%lld%lld",&x[1],&x[2],&x[3]);
	if(x[1]<x[2]&&x[2]<x[3]) p[1] = 1, p[2] = 2, p[3] = 3; 
	if(x[1]<x[3]&&x[3]<x[2]) p[1] = 1, p[2] = 3, p[3] = 2;
	if(x[2]<x[1]&&x[1]<x[3]) p[1] = 2, p[2] = 1, p[3] = 3;
	if(x[2]<x[3]&&x[3]<x[1]) p[1] = 2, p[2] = 3, p[3] = 1;
	if(x[3]<x[1]&&x[1]<x[2]) p[1] = 3, p[2] = 1, p[3] = 2;
	if(x[3]<x[2]&&x[2]<x[1]) p[1] = 3, p[2] = 2, p[3] = 1;
	
	int s;
	printf("FIRST\n");
	fflush(stdout);
	if(x[p[3]]-x[p[2]] >= x[p[2]] - x[p[1]])
	{
		long long int C = x[p[3]]-x[p[2]];
		printf("%lld\n",C);
		fflush(stdout);
		
		scanf("%d",&s);
		if(s==0) return 0;
		
		if(s==p[1])
		{
			long long int D = (x[p[1]]+C) - x[p[2]];
			printf("%lld\n",D);
			fflush(stdout);
		
			scanf("%d",&s);
			if(s==0) return 0;
			
			printf("%lld\n",2*(x[p[3]]+D-x[p[1]]-C)+(x[p[1]]+C-x[p[2]]));
			fflush(stdout);
			return 0;
		}
		else
		{
			printf("%lld\n",2*(x[p[3]]+C-x[p[2]])+(x[p[2]]-x[p[1]]));
			fflush(stdout);
			return 0;
		}
	}
	else
	{
		long long int C = x[p[2]]-x[p[1]];
		printf("%lld\n",C);
		fflush(stdout);
		
		scanf("%d",&s);
		if(s==0) return 0;
		
		if(s==p[2])
		{
			printf("%lld\n",2*(x[p[2]]+C-x[p[3]])+(x[p[3]]-x[p[1]]));
			fflush(stdout);
			return 0;
		}
		else
		{
			printf("%lld\n",2*(x[p[3]]+C-x[p[2]])+(x[p[2]]-x[p[1]]));
			fflush(stdout);
			return 0;
		}
	}
}
