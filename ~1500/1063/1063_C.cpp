#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

char g[10];
int getQuery(long long int s, long long int t)
{
	printf("%lld %lld\n",s,t);
	fflush(stdout);
	scanf("%s",g);
	if(g[0]=='b') return 1; // black
	else return 2; // white
}

std::vector< std::pair<int,int> > black,white;

long long int MAX = 1;
int direX[5]={1,0,-1,0};
int direY[5]={0,1,0,-1};

std::pair<long long int,long long int> func(int type)
{
	while(1)
	{
		long long int a = rand()%30000-15000;
		long long int b = rand()%30000-15000;
		
		long long int minBlack = MAX, maxBlack = -MAX;
		for(int i=0;i<black.size();i++)
		{
			long long int value = a*black[i].first + b*black[i].second;
			minBlack = minBlack<value?minBlack:value;
			maxBlack = maxBlack>value?maxBlack:value;
		}
		
		long long int minWhite = MAX, maxWhite = -MAX;
		for(int i=0;i<white.size();i++)
		{
			long long int value = a*white[i].first + b*white[i].second;
			minWhite = minWhite<value?minWhite:value;
			maxWhite = maxWhite>value?maxWhite:value;
		}
		
		if(maxBlack<minWhite)
		{
			for(int i=0;i<black.size();i++)
			{
				long long int value = a*black[i].first + b*black[i].second;
				if(value==maxBlack)
				{
					if(type==1) return std::make_pair(black[i].first+b,black[i].second-a);
					else
					{
						for(int j=0;j<4;j++)
						{
							value = a*(black[i].first+direX[j]) + b*(black[i].second+direY[j]);
							if(maxBlack<value&&value<minWhite)
							{
								printf("%lld %lld %lld %lld\n",black[i].first+direX[j],black[i].second+direY[j],black[i].first+direX[j]+b,black[i].second+direY[j]-a);
								fflush(stdout);
								return std::make_pair(0,0);
							}
						}
					}
				}
			}
			for(int i=0;i<white.size();i++)
			{
				long long int value = a*white[i].first + b*white[i].second;
				if(value==minWhite)
				{
					if(type==1) return std::make_pair(white[i].first+b,white[i].second-a);
					else
					{
						for(int j=0;j<4;j++)
						{
							value = a*(white[i].first+direX[j]) + b*(white[i].second+direY[j]);
							if(maxBlack<value&&value<minWhite)
							{
								printf("%lld %lld %lld %lld\n",white[i].first+direX[j],white[i].second+direY[j],white[i].first+direX[j]+b,white[i].second+direY[j]-a);
								fflush(stdout);
								return std::make_pair(0,0);
							}
						}
					}
				}
			}
		}
		
		if(maxWhite<minBlack)
		{
			for(int i=0;i<white.size();i++)
			{
				long long int value = a*white[i].first + b*white[i].second;
				if(value==maxWhite)
				{
					if(type==1) return std::make_pair(white[i].first+b,white[i].second-a);
					else
					{
						for(int j=0;j<4;j++)
						{
							value = a*(white[i].first+direX[j]) + b*(white[i].second+direY[j]);
							if(maxWhite<value&&value<minBlack)
							{
								printf("%lld %lld %lld %lld\n",white[i].first+direX[j],white[i].second+direY[j],white[i].first+direX[j]+b,white[i].second+direY[j]-a);
								fflush(stdout);
								return std::make_pair(0,0);
							}
						}
					}
				}
			}
			for(int i=0;i<black.size();i++)
			{
				long long int value = a*black[i].first + b*black[i].second;
				if(value==minBlack)
				{
					if(type==1) return std::make_pair(black[i].first+b,black[i].second-a);
					else
					{
						for(int j=0;j<4;j++)
						{
							value = a*(black[i].first+direX[j]) + b*(black[i].second+direY[j]);
							if(maxWhite<value&&value<minBlack)
							{
								printf("%lld %lld %lld %lld\n",black[i].first+direX[j],black[i].second+direY[j],black[i].first+direX[j]+b,black[i].second+direY[j]-a);
								fflush(stdout);
								return std::make_pair(0,0);
							}
						}
					}
				}
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	for(int i=1;i<=18;i++) MAX*=10;
	int a;
	scanf("%d",&a);
	
	int color = getQuery(500000000,500000000);
	if(color==1) black.push_back(std::make_pair(500000000,500000000));
	if(color==2) white.push_back(std::make_pair(500000000,500000000));
	
	for(int i=2;i<=a;i++)
	{
		std::pair<int,int> P = func(1);
		int c = getQuery(P.first,P.second);
		if(c==1) black.push_back(P);
		else white.push_back(P);
	}
	func(2);
}
