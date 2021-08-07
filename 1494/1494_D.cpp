#include <stdio.h>
#include <vector>
#include <algorithm>

int next[1110][5010];
std::vector< std::pair<int,int> > ans;
int value[1110];
int a,C;
std::vector<int> save[5010],save2[1110][5010];
void func(int k)
{
	int count = 0;
	for(int i=1;i<=5000;i++)
	{
		if(next[k][i]>0)
		{
			func(next[k][i]);
			count += save[next[k][i]].size();
		}
	}
	for(int i=1;i<=5000;i++)
	{
		for(int j=0;j<save2[k][i].size();j++)
		{
			count++;
			if(next[k][i]==0) next[k][i] = save2[k][i][j];
			save[next[k][i]].push_back(save2[k][i][j]);
		}
	}
	
	save[k].push_back(k);
	if(count==0) return;
	
	if(k!=a+1)
	{
		int t = count/2;
		for(int i=C;i<=C+t-2;i++) save[k].push_back(i);
		C = C+t-1;
	}
	
	int p = 0;
	for(int i=1;i<=5000;i++)
	{
		if(next[k][i]>0)
		{
			for(int j=0;j<save[next[k][i]].size();j++)
			{
				//printf("%d %d %d %d %d!!\n",k,i,next[k][i],save[next[k][i]][j],save[k][p%save[k].size()]);
				value[save[next[k][i]][j]] = i;
				ans.push_back({save[k][p%save[k].size()],save[next[k][i]][j]});
				p++;
			}
		}
	}
}

int x[510][510];
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) scanf("%d",&x[i][j]);
	
	C = a+1;
	for(int i=1;i<=a;i++)
	{
		std::vector<int> temp;
		for(int j=1;j<=a;j++) temp.push_back(x[i][j]);
		std::sort(temp.begin(),temp.end());
		temp.erase(std::unique(temp.begin(),temp.end()),temp.end());
		
		int start = 0;
		for(int j=temp.size()-1;j>=1;j--)
		{
			int t = temp[j];
			if(next[start][t]==0) next[start][t] = C++;
			start = next[start][t];
		}
		save2[start][temp[0]].push_back(i);
	}
	func(a+1);
	for(int i=1;i<=5000;i++) if(next[0][i]>0) value[a+1] = i;
	
	printf("%d\n",C-1);
	for(int i=1;i<C;i++) printf("%d ",value[i]);
	printf("\n%d\n",a+1);
	for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].second,ans[i].first);
}