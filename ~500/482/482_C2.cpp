#include <stdio.h>
#include <vector>
#include <string.h>
 
int a,b;
char x[110][110];
 
int count1[1100010],count2[1100010];
void func(int bit, int s, std::vector<int> &V)
{
	//printf("%d %d %d!!\n",bit,s,V.size());
	if(V.size()==1) count1[bit]++;
	count2[bit] += V.size();
	if(s>b) return;
	
	func(bit,s+1,V);
	
	std::vector<int> V2[52];
	for(int i=0;i<V.size();i++) V2[x[V[i]][s]-'a'].push_back(V[i]);
	for(int i=0;i<52;i++) if(V2[i].size()>0) func(bit+(1<<(s-1)),s+1,V2[i]);
}
 
double check[1100010];
int check2[1100010];
double func2(int bit)
{
	printf("%d : %d %d!!\n",bit,count1[bit],count2[bit]);
	if(check2[bit]) return check[bit];
	
	if(count1[bit]==count2[bit]) return 0;
	
	double s1 = (double)count1[bit]/count2[bit];
	double s2 = (double)(count2[bit]-count1[bit])/count2[bit];
	double s3 = 0;
	int count = 0;
	for(int i=1;i<=b;i++) if((bit&(1<<(i-1)))==0) count++;
	for(int i=1;i<=b;i++) if((bit&(1<<(i-1)))==0) s3 += func2(bit+(1<<(i-1)))/count;
	//printf("%d : %lf %lf %lf!!\n",bit,s1,s2,s3);
	check2[bit] = 1;
	return check[bit] =  s2*(s3+1);
}
 
std::vector<int> V;
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	b = strlen(x[1]+1);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]<='Z') x[i][j] += ('a'-'A'+26);
		}
	}
	for(int i=1;i<=a;i++) V.push_back(i);
	func(0,1,V);
	
	printf("%.12lf",func2(0));
}
