#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#define MOD 99999971
 
int a,b;
char x[110][110];
 
int count1[1100010],count2[1100010];
int check3[1100010];
long long int save[60];
 
std::vector<long long int> temp;
void func(int bit, int s)
{
	if(check3[bit]==0)
	{
		count2[bit] += a;
		temp.clear();
		for(int i=1;i<=a;i++) temp.push_back(save[i]);
		std::sort(temp.begin(),temp.end());
		for(int i=0;i<temp.size();i++)
		{
			if(i-1>=0 && temp[i]==temp[i-1]) continue;
			if(i+1<temp.size()&&temp[i]==temp[i+1]) continue;
			count1[bit]++;
		}
		check3[bit] = 1;
	}
	if(s>b) return;
	
	func(bit,s+1);
	long long int save2[60];
	for(int i=1;i<=a;i++) save2[i] = save[i];
	for(int i=1;i<=a;i++)
	{
		save[i] *= MOD;
		save[i] += x[i][s];
	}
	func(bit+(1<<(s-1)),s+1);
	for(int i=1;i<=a;i++) save[i] = save2[i];
}
 
double check[1100010];
int check2[1100010];
double func2(int bit)
{
	if(check2[bit]) return check[bit];
	
	if(count1[bit]==count2[bit]) return 0;
	
	double s1 = (double)count1[bit]/count2[bit];
	double s2 = (double)(count2[bit]-count1[bit])/count2[bit];
	double s3 = 0;
	int count = 0;
	for(int i=1;i<=b;i++) if((bit&(1<<(i-1)))==0) count++;
	for(int i=1;i<=b;i++) if((bit&(1<<(i-1)))==0)
	{
		int newBit = bit+(1<<(i-1));
		s3 += (func2(newBit)*(count2[newBit]-count1[newBit]))/(count*count2[newBit]);
	}
	//printf("%d : %lf %lf %lf!!\n",bit,s1,s2,s3);
	check2[bit] = 1;
	return check[bit] = s3+1;
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
	func(0,1);
	
	printf("%.12lf",func2(0));
}
