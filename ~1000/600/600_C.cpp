#include <stdio.h>
#include <string.h>
#include <vector>

char x[200010];
int count[30];
std::vector<int> V;
std::vector<char> ans1,ans2;

int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++) count[x[i]-'a']++;
	for(int i=0;i<26;i++) if(count[i]%2==1) V.push_back(i);
	
	if(V.size()%2==1)
	{
		int p;
		for(int i=(int)V.size()-1;i>=0;i--)
		{
			p = i;
			if(2*i+1==V.size()) break;
			if(count[V[i]]>1) break;
		}
		
		int s = 0, t = (int)V.size()-1;
		while(1)
		{
			if(t==p) t--;
			if(t<=s) break;
			count[V[s]]++, count[V[t]]--;
			s++,t--;
		}
	}
	else
	{
		for(int i=0;i<V.size();i++)
		{
			if(V.size()<=2*i+1) break;
			count[V[i]]++;
			count[V[V.size()-1-i]]--;
		}
	}
	
	for(int i=0;i<26;i++)
	{
		if(count[i]%2==1) continue;
		for(int j=1;j<=count[i]/2;j++) ans1.push_back('a'+i);
	}
	for(int i=0;i<26;i++)
	{
		if(count[i]%2==1)
		{
			for(int j=1;j<=count[i];j++) ans1.push_back('a'+i);
		}
	}
	for(int i=25;i>=0;i--)
	{
		if(count[i]%2==1) continue;
		for(int j=1;j<=count[i]/2;j++) ans1.push_back('a'+i);
	}
	
	for(int i=0;i<26;i++) count[i] = 0;
	V.clear();
	for(int i=1;i<=a;i++) count[x[i]-'a']++;
	for(int i=0;i<26;i++) if(count[i]%2==1) V.push_back(i);
	
	for(int i=0;i<V.size();i++)
	{
		if(V.size()<=2*i+1) break;
		count[V[i]]++;
		count[V[V.size()-1-i]]--;
	}
	
	for(int i=0;i<26;i++)
	{
		if(count[i]%2==1) continue;
		for(int j=1;j<=count[i]/2;j++) ans2.push_back('a'+i);
	}
	for(int i=0;i<26;i++)
	{
		if(count[i]%2==1)
		{
			for(int j=1;j<=count[i];j++) ans2.push_back('a'+i);
		}
	}
	for(int i=25;i>=0;i--)
	{
		if(count[i]%2==1) continue;
		for(int j=1;j<=count[i]/2;j++) ans2.push_back('a'+i);
	}
	
	for(int i=0;i<ans1.size();i++)
	{
		if(ans1[i]<ans2[i])
		{
			for(int j=0;j<ans1.size();j++) printf("%c",ans1[j]);
			return 0;
		}
		if(ans1[i]>ans2[i])
		{
			for(int j=0;j<ans2.size();j++) printf("%c",ans2[j]);
			return 0;
		}
	}
	for(int j=0;j<ans1.size();j++) printf("%c",ans1[j]);
}