#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#define MOD 99999973

std::set<long long int> S;
char ans[1000010],y[1000010];
std::vector<char> x[100010];
int len[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",y+1);
		len[i] = strlen(y+1);
		x[i].push_back(0);
		for(int j=1;j<=len[i];j++) x[i].push_back(y[j]);
	}
	for(int i=1;i<=len[1];i++) ans[i] = x[1][i];
	
	int p = len[1];
	for(int i=2;i<=a;i++)
	{
		S.clear();
		int start = 0;
		long long int hash1 = 0,hash2 = 0;
		long long int mul = 1;
		for(int j=p;j>=(p-len[i]+1>=1?p-len[i]+1:1);j--)
		{
			hash1 += mul*ans[j];
			mul *= MOD;
			S.insert(hash1);
		}
		for(int j=1;j<=len[i];j++)
		{
			hash2 *= MOD, hash2 += x[i][j];
			if(S.find(hash2)!=S.end()) start = j;
		}
		for(int j=start+1;j<=len[i];j++) ans[++p] = x[i][j];
	}
	for(int i=1;i<=p;i++) printf("%c",ans[i]);
}
