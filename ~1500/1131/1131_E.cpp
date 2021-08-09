#include <iostream>
#include <string>

std::string x[100010];
int y[100010];
int func(int s, char K)
{
	int control = 0;
	for(int i=0;i<y[s];i++)
	{
		if(x[s][i]!=K)
		{
			control = 1;
			break;
		}
	}
	if(control==1)
	{
		int ans = 0, C = 0;
		for(int i=0;i<y[s];i++)
		{
			if(x[s][i]==K) C++;
			else C = 0;
			ans = ans>C?ans:C;
		}
		if(x[s][0]==x[s][y[s]-1]&&x[s][0]==K)
		{
			int count = 0;
			for(int i=y[s]-1;i>=0;i--)
			{
				if(x[s][i]!=K) break;
				else count++;
			}
			for(int i=0;i<y[s];i++)
			{
				if(x[s][i]!=K) break;
				else count++;
			}
			for(int i=1;i<s;i++) for(int j=0;j<y[i];j++) if(x[i][j]==K) ans = ans>count+1? ans : count+1;
		}
		for(int i=1;i<s;i++) for(int j=0;j<y[i];j++) if(x[i][j]==K) ans = ans>1? ans : 1;
		return ans;
	}
	else
	{
		int C = func(s-1,K);
		return C+(C+1)*y[s];
	}
}
int main()
{
	int a;
	std::cin>>a;
	for(int i=1;i<=a;i++) std::cin>>x[i];
	for(int i=1;i<=a;i++) y[i] = x[i].length();
	
	int control = 0;
	for(int i=0;i<y[a];i++)
	{
		if(x[a][i]!=x[a][0]) control = 1;
	}
	if(control==1)
	{
		int ans = 1, C = 1;
		for(int i=1;i<y[a];i++)
		{
			if(x[a][i]==x[a][i-1]) C++;
			else C = 1;
			ans = ans>C?ans:C;
		}
		if(x[a][0]==x[a][y[a]-1])
		{
			int count = 0;
			for(int i=y[a]-1;i>=0;i--)
			{
				if(x[a][i]!=x[a][0]) break;
				else count++;
			}
			for(int i=0;i<y[a];i++)
			{
				if(x[a][i]!=x[a][0]) break;
				else count++;
			}
			for(int i=1;i<a;i++) for(int j=0;j<y[i];j++) if(x[i][j]==x[a][0]) ans = ans>count+1? ans : count+1;
			
		}
		std::cout<<ans;
		return 0;
	}
	
	int c = func(a-1,x[a][0]);
	std::cout<<c+(c+1)*y[a];
}
