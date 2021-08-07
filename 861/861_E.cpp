#include <stdio.h>
#include <string.h>
#include <set>
char x[100010][10];
int y[100010];

std::set<int> S1,S2,T1,T2,E1,E2,M1,M2;
std::pair<int,int> P[500010];
int p = 1;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%s %d",x[i]+1,&y[i]);
	}
	
	int b = 0,c;
	for(int i=1;i<=a;i++) b+=y[i];
	for(int i=1;i<=b;i++) E1.insert(i),M1.insert(i);
	for(int i=b+1;i<=a;i++) E2.insert(i),M2.insert(i);
	for(int i=1;i<=a;i++)
	{
		c = strlen(x[i]+1);
		for(int j=1;j<=c;j++)
		{
			if(x[i][j]<'0'||x[i][j]>'9') goto u;
		}
		if(x[i][1]=='0') goto u;
		
		int s;
		s = 0;
		for(int j=1;j<=c;j++)
		{
			s*=10;
			s+=(x[i][j]-'0');
		}
		
		if(y[i]==1)
		{
			if(s<=b) E1.erase(s),M1.erase(s);
			else if(b<s&&s<=a) E2.erase(s),S2.insert(i);
			else goto u;
		}
		else
		{
			if(s<=b) E1.erase(s),T2.insert(i);
			else if(b<s&&s<=a) E2.erase(s),M2.erase(s);
			else goto u;
		}
		continue;
		
		u:;
		if(y[i]==1) S1.insert(i);
		else T1.insert(i);
	}
	
	while(1)
	{
		printf("!!\n");
		if(M1.empty()&&M2.empty()) break;
		else if(M1.empty())
		{
			std::set<int> ::iterator it;
			if(!T1.empty()) P[p++] = std::make_pair(*T1.begin(),*M2.begin()), T1.erase(T1.begin()) , E2.erase(M2.begin()), M2.erase(M2.begin());
			else if(!T2.empty()) P[p++] = std::make_pair(*T2.begin(),*M2.begin()), T2.erase(T2.begin()), E2.erase(M2.begin()), M2.erase(M2.begin());
		}
		else if(M2.empty())
		{
			if(!S1.empty()) P[p++] = std::make_pair(*S1.begin(),*M1.begin()), S1.erase(S1.begin()) , E1.erase(M2.begin()), M1.erase(M2.begin());
			else if(!S2.empty()) P[p++] = std::make_pair(*S2.begin(),*M1.begin()), S2.erase(S2.begin()), E1.erase(M2.begin()), M1.erase(M2.begin());
		}
		else
		{
			if(!E1.empty())
			{
				if(!S2.empty()) P[p++] = std::make_pair(*S2.begin(),*E1.begin()), M1.erase(*E1.begin()), E1.erase(E1.begin()), E2.insert(*S2.begin()), S2.erase(S2.begin());
				else P[p++] = std::make_pair(*S1.begin(),*E1.begin()), S1.erase(S1.begin()), M1.erase(*E1.begin()), E1.erase(E1.begin());
			}
			else if(!E2.empty())
			{
				if(!T2.empty()) P[p++] = std::make_pair(*T2.begin(),*E2.begin()), M2.erase(*E2.begin()), E2.erase(E2.begin()), E1.insert(*T2.begin()), T2.erase(T2.begin());
				else P[p++] = std::make_pair(*T1.begin(),*E2.begin()), T1.erase(T1.begin()), M2.erase(*E2.begin()), E2.erase(E2.begin());
			}
			else
			{
				P[p++] = std::make_pair(*M1.begin(),a+1);
				P[p++] = std::make_pair(*M2.begin(),*M1.begin());
				P[p++] = std::make_pair(a+1,*M2.begin());
				M1.erase(M1.begin()), M2.erase(M2.begin());
			}
		}
	}
	for(int i=1;i<p;i++)
	{
		if(P[i].first==a+1) printf("move extra %s\n",x[P[i].second]+1);
		else if(P[i].second==a+1) printf("move %s extra\n",x[P[i].first]+1);
		else printf("move %s %s\n",x[P[i].first]+1,x[P[i].second]+1);
	}
}
