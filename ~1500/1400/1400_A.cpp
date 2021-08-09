#include <stdio.h>
#include <map>

std::map<long long int,int> check;
char x[110];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		check.clear();
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		for(int i=1;i<=a;i++)
		{
			long long int S = 0;
			for(int j=i;j<=i+a-1;j++)
			{
				S*=2;
				S += x[j]-'0';
			}
			long long int k = 1;
			for(int j=1;j<=a;j++) k*=2;
			check[k-1-S] = 1;
		}
		
		for(int i=0;i<=a+1;i++)
		{
			if(check[i]==0)
			{
				long long int k = 1;
				for(int j=1;j<=a-i;j++) k*=2;
				for(int j=1;j<=a;j++) printf("%d",(i/k)%2);
				printf("\n");
				break;
			}
		}
	}
}
