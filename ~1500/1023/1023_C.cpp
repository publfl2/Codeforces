#include <stdio.h>
#include <vector>


char x[200010];
std::vector<char> S;
std::vector<char> ans;
void func(int start, int end, int k)
{
	if(k==0) return;
	
	int count = 0;
	for(int i=start;i<end;i++)
	{
		if(S[i]=='(') count++;
		else count--;
		
		if(count==0)
		{
			if((i-start+1)<=k)
			{
				for(int j=start;j<=i;j++) ans.push_back(S[j]);
				func(i+1,end,k-(i-start+1));
				break;
			}
			else
			{
				ans.push_back('(');
				func(start+1,end-1,k-2);
				ans.push_back(')');
				break;
			}
		}
	}
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	
	for(int i=1;i<=a;i++) S.push_back(x[i]);
	func(0,a,b);
	for(int i=0;i<ans.size();i++) printf("%c",ans[i]);
}
