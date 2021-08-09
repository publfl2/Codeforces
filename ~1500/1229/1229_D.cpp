#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> T;
int check[100010],temp[10];
void func(std::vector<int> axis)
{
	int sum = 0;
	for(int i=1;i<=5;i++) sum*= 10, sum += axis[i];
	if(check[sum]) return;
	check[sum] = 1;
	
	for(int i=0;i<T.size();i++)
	{
		std::vector<int> axis2;
		for(int k=0;k<=5;k++) axis2.push_back(0);
		
		int t = T[i];
		for(int k=5;k>=1;k--) temp[k] = t%10, t/=10;
		for(int k=1;k<=5;k++) axis2[k] = axis[temp[k]];
		func(axis2);
	}
}

int p[10],x[10];

std::vector< std::pair< std::vector<int> , std::pair<int,int> > > current;
std::vector<int> initial;
std::vector<int> number;

int main()
{
	for(int i=1;i<=5;i++) p[i] = i;
	do{
		int S = 0;
		for(int i=1;i<=5;i++) S*=10, S+=p[i];
		number.push_back(S);
	}while(std::next_permutation(p+1,p+6));
	
	initial.push_back(12345);
	long long int ans = 0;
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++) scanf("%d",&x[j]);
		for(int j=b+1;j<=5;j++) x[j] = j;
		int S = 0;
		for(int j=1;j<=5;j++) S*=10, S+=x[j];
		
		current.push_back(std::make_pair(initial,std::make_pair(1,1)));
		std::vector< std::pair< std::vector<int> , std::pair<int,int> > > current2;
		for(int j=0;j<current.size();j++)
		{
			T = current[j].first;
			T.push_back(S);
			for(int k=0;k<number.size();k++) check[number[k]] = 0;
			
			//for(int k=0;k<T.size();k++) check[T[k]] = 1;
			
			for(int k=0;k<T.size();k++)
			{
				std::vector<int> axis;
				for(int l=0;l<=5;l++) axis.push_back(l);
				
				int t = T[k];
				for(int l=5;l>=1;l--) temp[l] = t%10, t/=10;
				for(int l=1;l<=5;l++) axis[l] = temp[x[l]];
				func(axis);
			}
			
			int count = 0;
			for(int k=0;k<number.size();k++) count += check[number[k]];
			ans += (long long int)count*current[j].second.second;
			std::vector<int> temp = current[j].first;
			if(count>current[j].second.first) temp.push_back(S);
			
			if(current2.empty()) current2.push_back(std::make_pair(temp,std::make_pair(count,current[j].second.second)));
			else
			{
				if(count==current2.back().second.first)
				{
					current2.back().second.second += current[j].second.second;
				}
				else current2.push_back(std::make_pair(temp,std::make_pair(count,current[j].second.second)));
			}
		}
		current = current2;
		//printf("%d %lld!!\n",i,ans);
	}
	
	printf("%lld",ans);
}