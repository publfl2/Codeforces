#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>

struct str{
	int x0;
	int y0;
	int z0;
};
bool operator<(str a, str b)
{
	if(a.x0==b.x0)
	{
		if(a.y0==b.y0) return a.z0<b.z0;
		return a.y0<b.y0;
	}
	return a.x0<b.x0;
}
int control;

int x[110][110];
std::vector<str> St;
std::map<str,int> M;
std::map<int,int> S1,S2,S3;

void func(int k)
{
	if(control) return;
	if(k>8)
	{
		printf("YES\n");
		for(int i=0;i<8;i++) printf("%d %d %d\n",St[i].x0,St[i].y0,St[i].z0);
		control = 1;
		return;
	}
	
	std::sort(x[k]+1,x[k]+4);
	do{
		if(M[{x[k][1],x[k][2],x[k][3]}]==0)
		{
			M[{x[k][1],x[k][2],x[k][3]}]++;
			S1[x[k][1]]++;
			S2[x[k][2]]++;
			S3[x[k][3]]++;
			
			if(S1.size()<=2&&S2.size()<=2&&S3.size()<=2)
			{
				if(S1[x[k][1]]<=4&&S2[x[k][2]]<=4&&S3[x[k][3]]<=4)
				{
					St.push_back({x[k][1],x[k][2],x[k][3]});
					func(k+1);
					St.pop_back();
				}
			}
			
			M.erase({x[k][1],x[k][2],x[k][3]});
			S1[x[k][1]]--;
			if(S1[x[k][1]]==0) S1.erase(x[k][1]);
			S2[x[k][2]]--;
			if(S2[x[k][2]]==0) S2.erase(x[k][2]);
			S3[x[k][3]]--;
			if(S3[x[k][3]]==0) S3.erase(x[k][3]);
		}
	}while(std::next_permutation(x[k]+1,x[k]+4));
	
}
int main()
{
	for(int i=1;i<=8;i++) scanf("%d%d%d",&x[i][1],&x[i][2],&x[i][3]);
	func(1);
	if(control==0) printf("NO");
}
