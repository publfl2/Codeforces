#include <stdio.h>
#include <string.h>
#include <vector>
char x[100010];

int ans[100010];

std::vector<int> V;
int main()
{
	int a;
	scanf("%d%s",&a,x+1);
	
	for(int i=1;i<=a-1;i++) if(x[i+1]!='0') V.push_back(i);
	int s = V[0];
	for(int i=0;i<V.size();i++) if((V[i]>a-V[i]?V[i]:a-V[i])<(s>a-s?s:a-s)) s=V[i];
	printf("%d!!\n",s);
	
	
	for(int i=1;i<=s;i++) ans1[s-i+1] += x[i]-'0';
	for(int i=s+1;i<=a;i++) ans1[a-i+1] += x[i]-'0';
	for(int i=1;i<=100000;i++) ans1[i+1]+=ans1[i]/10,ans1[i]%=10;
	
	int t;
	for(int i=100001;i>=1;i--)
	{
		if(ans[i]!=0)
		{
			t = i;
			break;
		}
	}
	
	if()
	
	for(int i=t;i>=1;i--) printf("%d",ans[i]);
}
