#include <iostream>
#include <string>
#include <algorithm>
#include <map>

std::string S[110],T[110];
bool cmp(std::string A, std::string B)
{
	if(A.size()==B.size()) return A[A.size()-1] < B[B.size()-1];
	return A.size()<B.size();
}

std::map<char,int> M1,M2;
int abs(int k)
{
	return k>0?k:-k;
}
int main()
{
	int a;
	std::cin>>a;
	for(int i=1;i<=a;i++) std::cin>>S[i];
	for(int i=1;i<=a;i++) std::cin>>T[i];
	std::sort(S+1,S+a+1,cmp);
	std::sort(T+1,T+a+1,cmp);
	
	int p = 0;
	int count = 0;
	for(int i=a;i>=1;i--)
	{
		if(S[i].size()==1)
		{
			p = i;
			break;
		}
		if(S[i][S[i].size()-1]!=T[i][T[i].size()-1]) count++;
	}
	for(int i=p;i>=1;i--)
	{
		M1[S[i][0]]++;
		M2[T[i][0]]++;
	}
	std::cout<<count+(abs(M1['S']-M2['S'])+abs(M1['M']-M2['M'])+abs(M1['L']-M2['L']))/2;
}
