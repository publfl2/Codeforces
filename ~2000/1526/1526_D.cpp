#include <stdio.h>
#include <string.h>
#include <algorithm>

int abs(int k)
{
	return k>0?k:-k;
}

char x[100010];
std::vector<int> V[50];
std::vector<int> temp[50];

char p[10],save[10];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=30;i++) V[i].clear();
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=1;i<=a;i++) V[x[i]-'A'].push_back(i);
		
		p[1] = 'A', p[2] = 'N', p[3] = 'O', p[4] = 'T';
		long long int ans = 0;
		do{
			int s = a;
			long long int sum = 0;
			
			for(int i=0;i<V[p[4]-'A'].size();i++) temp[p[4]-'A'].push_back(s--);
			for(int i=0;i<V[p[3]-'A'].size();i++) temp[p[3]-'A'].push_back(s--);
			for(int i=0;i<V[p[2]-'A'].size();i++) temp[p[2]-'A'].push_back(s--);
			for(int i=0;i<V[p[1]-'A'].size();i++) temp[p[1]-'A'].push_back(s--);
			
			int count = 0;
			for(int i=1;i<=a;i++)
			{
				if(temp[x[i]-'A'].back()+count>i)
				{
					sum += abs(temp[x[i]-'A'].back()+count - i);
					count++;
				}
				temp[x[i]-'A'].pop_back();
			}
			
			if(ans<=sum)
			{
				ans = sum;
				for(int i=1;i<=4;i++) save[i] = p[i];
			}
		}while(std::next_permutation(p+1,p+5));
		
		for(int j=1;j<=4;j++) for(int i=0;i<V[save[j]-'A'].size();i++) printf("%c",save[j]);
		printf("\n");
	}
	
}