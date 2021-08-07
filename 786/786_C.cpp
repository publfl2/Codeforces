#include <stdio.h>
#define MAX 500
class Pivot{
	private:
	int pivotSize;
	int color[100010];
	int lastIndex;
	public:
	Pivot()
	{
		pivotSize = 0;
	}
	void addColor(int k)
	{
		if(color[k]==0) pivotSize++;
		color[k]++;
	}
	void deleteColor(int k)
	{
		if(color[k]==1) pivotSize--;
		color[k]--;
	}
	bool isColor(int k)
	{
		if(color[k]<=0) return false;
		else return true;
	}
	int getIndex()
	{
		return lastIndex;
	}
	void setIndex(int k)
	{
		lastIndex = k;
	}
	int getSize()
	{
		return pivotSize;
	}
}pivot[MAX];
int x[100010];
int ans = 0,a;
int func(int k, int t)
{
	int check[100010]={};
	int count = 0;
	for(int i=k;i<=a;i++)
	{
		if(check[x[i]]==0)
		{
			if(count==t)
			{
				ans++;
				return i;
			}
			check[x[i]] = 1, count++;
		}
	}
	ans++;
	return a+1;
}
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=MAX&&i<=a;i++)
	{
		int b = 1;
		ans = 0;
		while(b<=a) b = func(b,i);
		printf("%d ",ans);
	}
	if(a<=MAX) return 0;
	//case : MAX+1
	int number = 1;
	for(int i=1;i<=a;i++)
	{
		if(!pivot[number].isColor(x[i]))
		{
			if(pivot[number].getSize()==MAX+1)
			{
				pivot[number].setIndex(i-1);
				number++;
			}
		}
		pivot[number].addColor(x[i]);
	}
	pivot[number].setIndex(a);
	printf("%d ",number);
	
	for(int i=MAX+2;i<=a;i++)
	{
		for(int j=1;j<=number;j++)
		{
			while(1)
			{
				if(pivot[j].getIndex()==a) goto u;
				if(!pivot[j].isColor(x[pivot[j].getIndex()+1])) if(pivot[j].getSize()==i) break;
				
				pivot[j].addColor(x[pivot[j].getIndex()+1]);
				pivot[j+1].deleteColor(x[pivot[j].getIndex()+1]);
				pivot[j].setIndex(pivot[j].getIndex()+1);
			}
		}
		u:;
		for(int j=1;j<=number;j++)
		{
			if(pivot[j].getIndex()==a)
			{
				printf("%d ",j);
				break;
			}
		}
	}
}
