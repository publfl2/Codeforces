#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		V[b].push_back(std::make_pair(c,d));
		V[c].push_back(std::make_pair(b,d));
	}
	
	for(int i=1;i<=a;i++)
	{
		if(V[i].size()==2)
		{
			std::pair<int,int> P1 = V[i][0];
			std::pair<int,int> P2 = V[i][1];
			if(P1.second!=P2.second)
			{
				printf("NO");
				return 0;
			}
		}
	}
	
	for(int i=1;i<=a;i++) if(V[i].size()==1) leaf.push_back(i);
	int p = leaf.size();
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<V[i].size();j++)
		{
			count++;
			int t = V[i][j].first;
			for(int k=1;k<p;k++)
			{
				if(dist[leaf[0]][i]==dist[leaf[0]][t]+1&&dist[leaf[k]][t]==dist[leaf[k]][i]+1) x[count][k] = 1;
				if(dist[leaf[0]][t]==dist[leaf[0]][i]+1&&dist[leaf[k]][i]==dist[leaf[k]][t]+1) x[count][k] = 1;
			}
			for(int k=2;k<p;k++)
			{
				if(dist[leaf[1]][i]==dist[leaf[1]][t]+1&&dist[leaf[k]][t]==dist[leaf[k]][i]+1) x[count][p-2+k] = 1;
				if(dist[leaf[1]][t]==dist[leaf[1]][i]+1&&dist[leaf[k]][i]==dist[leaf[k]][t]+1) x[count][p-2+k] = 1;
			}
			y[count] = V[i][j].second;
		}
	}
	
	for(int j=1;j<=2*p-3;j++)
	{
		int pivot = 0;
		for(int i=j;i<=count;i++) if(x[i][j]!=0) pivot = i;
		swap(j,pivot);
		
	}
	
}
