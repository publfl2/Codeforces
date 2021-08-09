#include <stdio.h>
#include <atcoder/mincostflow>
#define MAX 100

char x[110];
int y[110];
int count[110];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	for(int i=1;i<=a;i++) count[x[i]-'a'+1]++;
	
	atcoder::mcf_graph<int, long long int> G(1+ 26 + 26*(a/2) + a + 1 + 3);
	int c = a/2;
	int start = 26*(c+1);
	int end = start + a + 1;
	for(int i=1;i<=26;i++)
	{
		G.add_edge(0,(i-1)*(c+1)+1,count[i],0);
		for(int j=2;j<=c+1;j++)
		{
			G.add_edge((i-1)*(c+1)+1,(i-1)*(c+1)+j,1,0);
			int s = (j-1);
			int t = a-(j-1)+1;
			if(x[s]=='a'+i-1) G.add_edge((i-1)*(c+1)+j,start+s,1,MAX-y[s]);
			else G.add_edge((i-1)*(c+1)+j,start+s,1,MAX);
			
			if(x[t]=='a'+i-1) G.add_edge((i-1)*(c+1)+j,start+t,1,MAX-y[t]);
			else G.add_edge((i-1)*(c+1)+j,start+t,1,MAX);
		}
	}
	for(int i=1;i<=a;i++) G.add_edge(start+i,end,1,0);
	
	std::pair<int, long long int> P;
	P = G.flow(0,end);
	printf("%lld",MAX*a - P.second);
}