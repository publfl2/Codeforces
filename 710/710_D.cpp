#include <stdio.h>
#include <vector>
#include <atcoder/math>

std::vector<long long int> V1,V2;
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	V1.push_back(b), V1.push_back(d);
	V2.push_back(a), V2.push_back(c);
	std::pair<long long int, long long int> P = atcoder::crt(V1,V2);
	if(P.second==0) printf("0");
	else
	{
		e = e>b?e:b;
		e = e>d?e:d;
		if(e>f) printf("0");
		else
		{
			long long int L = (e-P.first)/P.second-1;
			while(1)
			{
				if(L*P.second+P.first<e) L++;
				else break;
			}
			long long int R = (f-P.first)/P.second+1;
			while(1)
			{
				if(R*P.second+P.first>f) R--;
				else break;
			}
			printf("%lld",R-L+1);
		}
	}
}