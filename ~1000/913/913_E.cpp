#include <stdio.h>
#include <vector>
#include <queue>
#define X 15
#define Y 51
#define Z 85
//max 255
struct str{
	std::vector<char> x;
	int length;
	str()
	{
		x.resize(30);
	}
}ans[300];
int check[300];

bool operator<(str a, str b)
{
	if(a.length==b.length)
	{
		for(int i=1;i<=a.length;i++) if(a.x[i]!=b.x[i]) return a.x[i]>b.x[i];
		return true;
	}
	return a.length>b.length;
}
int func(std::vector<char> x, int& pivot, int end, int SAVE=255)
{
	int s1,s2;
	int NS1 = 0, NS2 = 0;
	if(x[pivot]=='!')
	{
		pivot++;
		NS1 = 1;
	}
	if(x[pivot]=='(')
	{
		pivot++;
		int count = 1;
		for(int i=pivot;i<=end;i++)
		{
			if(x[i]=='(') count++;
			else count--;
			if(count==0)
			{
				s1 = func(x,pivot,i-1);
				break;
			}
		}
		pivot++;
	}
	else if(x[pivot]=='x') s1 = X,pivot++;
	else if(x[pivot]=='y') s1 = Y,pivot++;
	else if(x[pivot]=='z') s1 = Z,pivot++;
	if(NS1==1) s1 = 255-s1;
	SAVE = SAVE&s1;
	
	if(pivot>end) return SAVE;
	else if(x[pivot]=='&')
	{
		pivot++;
		return func(x,pivot,end,SAVE);
	}
	else if(x[pivot]=='|')
	{
		pivot++;
		s2 = func(x,pivot,end);
		return s1|s2;
	}
}

std::priority_queue<str> Q;
str s1,s2,s3;
int main()
{
	s1.x[1]  = 'x', s1.length = 1;
	s2.x[1]  = 'y', s2.length = 1;
	s3.x[1]  = 'z', s3.length = 1;
	Q.push(s1), Q.push(s2), Q.push(s3);
	while(!Q.empty())
	{
		str A = Q.top();
		Q.pop();
		int pivot = 1;
		int value = func(A.x,pivot,A.length);
		printf("%d\n",value);
		if(check[value]==1) continue;
		check[value] = 1;
		ans[value] = A;
		
		str B = A;
		int length = A.length,value2;
		// |x
		B.x[length+1] = '|', B.x[length+2] = 'x',B.length = length+2;
		value2 = func(B.x,pivot=1,length+2);
		if(check[value2]==1&&ans[value2].length+2<B.length);
		else Q.push(B);
		//|y
		B.x[length+1] = '|', B.x[length+2] = 'y',B.length = length+2;
		value2 = func(B.x,pivot=1,length+2);
		if(check[value2]==1&&ans[value2].length+2<B.length);
		else Q.push(B);
		//|z
		B.x[length+1] = '|', B.x[length+2] = 'z',B.length = length+2;
		value2 = func(B.x,pivot=1,length+2);
		if(check[value2]==1&&ans[value2].length+2<B.length);
		else Q.push(B);
		
		// &x
		B.x[length+1] = '&', B.x[length+2] = 'x',B.length = length+2;
		value2 = func(B.x,pivot=1,length+2);
		if(check[value2]==1&&ans[value2].length+2<B.length);
		else Q.push(B);
		//&y
		B.x[length+1] = '&', B.x[length+2] = 'y',B.length = length+2;
		value2 = func(B.x,pivot=1,length+2);
		if(check[value2]==1&&ans[value2].length+2<B.length);
		else Q.push(B);
		//&z
		B.x[length+1] = '&', B.x[length+2] = 'z',B.length = length+2;
		value2 = func(B.x,pivot=1,length+2);
		if(check[value2]==1&&ans[value2].length+2<B.length);
		else Q.push(B);
		
		// |x
		B.x[length+1] = '|', B.x[length+2] = 'x',B.length = length+2;
		value2 = func(B.x,pivot=1,length+2);
		if(check[value2]==1&&ans[value2].length+2<B.length);
		else Q.push(B);
	}
}
