#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
#include <vector>

#define LENMAX 1048575
#define HASHMOD 1399031723
#define MOD 1000000007

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int save[30][100010];
long long int sum(int type, int L, int R)
{
	if(L>R) return 0;
	return (save[type][R]-save[type][L-1]+MOD)%MOD;
}

std::vector<long long int> acceptedL,acceptedR;
int possL[1000010],possR[1000010];
std::vector<char> V;

char x[100010],y[1000010];

int find(std::vector<long long int >& V, long long int val)
{
	int L = 0, R = V.size()-1;
	while(L<=R)
	{
		int h = (L+R)/2;
		if(V[h]==val) return 1;
		else if(V[h]<val) L = h+1;
		else R = h-1;
	}
	return 0;
}

long long int doQuery(int k)
{
	if(V.empty()) return power(2,k);
	if(k==0) return 0;
	if(k<20 && V.size()>=(1<<k)) return 0;
	
	long long int hashSum = 0;
	for(int i=1;i<=V.size();i++)
	{
		hashSum *= HASHMOD;
		hashSum += V[i-1];
		if(find(acceptedL,hashSum)==1) possL[i] = 1;
		else possL[i] = 0;
	}
	hashSum = 0;
	long long int hashMul = 1;
	for(int i=V.size();i>=1;i--)
	{
		hashSum += hashMul*V[i-1];
		if(find(acceptedR,hashSum)==1) possR[i] = 1;
		else possR[i] = 0;
		hashMul *= HASHMOD;
	}
	possL[0] = 1, possR[V.size()+1] = 1;
	
	long long int ans = 0;
	for(int i=1;i<=V.size();i++)
	{
		if(possL[i-1]==1&&possR[i+1]==1)
		{
			int l = (i-1)>(V.size()-i)?(i-1):(V.size()-i);
			int L = 0;
			while(1)
			{
				L++;
				if((1<<(L-1))-1>=l) break;
			}
			int R = k;
			//printf("%d %d??\n",L,R);
			long long int temp = sum(V[i-1]-'a',L,R);
			temp *= power(2,k);
			temp %= MOD;
			ans += temp;
			ans %= MOD;
		}
	}
	
	return ans;
}

char z[2000010];
int queryK;
char queryW[1000010];
long long int queryAns[100010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s%s",x+1,y+1);
	int c = strlen(x+1);
	
	for(int i=1;i<=a;i++) save[y[i]-'a'][i] = inv(power(2,i));
	for(int i=0;i<26;i++)
	{
		for(int j=1;j<=a;j++)
		{
			save[i][j] += save[i][j-1];
			save[i][j] %= MOD;
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		if((1<<(i-1))>LENMAX) break;
		for(int j=(1<<(i-1));j<=LENMAX;j+=(1<<i))
		{
			z[j] = y[i];
		}
	}
	
	long long int hashSum = 0;
	for(int i=1;i<=LENMAX;i++)
	{
		hashSum *= HASHMOD;
		hashSum += z[i];
		acceptedL.push_back(hashSum);
	}
	hashSum = 0;
	long long int hashMul = 1;
	for(int i=LENMAX;i>=1;i--)
	{
		hashSum += hashMul*z[i];
		acceptedR.push_back(hashSum);
		hashMul *= HASHMOD;
	}
	std::sort(acceptedL.begin(),acceptedL.end());
	acceptedL.erase(std::unique(acceptedL.begin(),acceptedL.end()),acceptedL.end());
	std::sort(acceptedR.begin(),acceptedR.end());
	acceptedR.erase(std::unique(acceptedR.begin(),acceptedR.end()),acceptedR.end());
	//std::sort(query+1,query+b+1,cmp);
	
	for(int i=1;i<=b;i++)
	{
		scanf("%d%s",&queryK,queryW+1);
		queryAns[i] = 0;
		int len = strlen(queryW+1);
		for(int j=0;j<=c;j++)
		{
			int start = j;
			V.clear();
			for(int k=1;k<=len;k++)
			{
				if(start==0) V.push_back(queryW[k]);
				else if(queryW[k]!=x[start]) goto u;
				start++;
				start%=(c+1);
			}
			queryAns[i] += doQuery(queryK);
			queryAns[i] %= MOD;
			u:;
		}
	}
	for(int i=1;i<=b;i++) printf("%lld\n",queryAns[i]);
}
