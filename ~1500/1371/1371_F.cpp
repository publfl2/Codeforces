#include <stdio.h>


int MAX(int a,int b, int c)
{
	return a>b?a>c?a:c:c>b?c:b;
}

struct str{
	int max;
	int left;
	int leftmost;
	int right;
	int rightmost;
};


struct segTree{
	int left[2000010][2];
	int leftmost[2000010][2];
	int right[2000010][2];
	int rightmost[2000010][2];
	int max[2000010][2];
	int isSame[2000010][2];
	
	void update(int v)
	{
		for(int i=0;i<=1;i++)
		{
			left[v][i] = left[2*v][i];
			leftmost[v][i] = leftmost[2*v][i];
			right[v][i] = right[2*v+1][i];
			rightmost[v][i] = rightmost[2*v+1][i];
			max[v][i] = max[2*v][i]>max[2*v+1][i]?max[2*v][i]:max[2*v+1][i];
			
			if(right[2*v][i]>0&&left[2*v+1][i]>0)
			{
				int C = right[2*v][i] + left[2*v+1][i];
				max[v][i] = max[v][i]>C?max[v][i]:C;
				if(leftmost[2*v][i]==-1) leftmost[v][i] = C;
				if(rightmost[2*v+1][i]==-1) rightmost[v][i] = C;
			}
			else if(right[2*v][i]==0&&left[2*v+1][i]>0)
			{
				if(rightmost[2*v][i]==-1) left[v][i] += left[2*v+1][i];
				else
				{
					int C = rightmost[2*v][i]+left[2*v+1][i];
					max[v][i] = max[v][i]>C?max[v][i]:C;
					if(rightmost[2*v+1][i]==-1) rightmost[v][i] = C;
				}
			}
			else if(right[2*v][i]>0&&left[2*v+1][i]==0)
			{
				if(leftmost[2*v+1][i]==-1) right[v][i] += right[2*v][i];
				else
				{
					int C = leftmost[2*v+1][i]+right[2*v][i];
					max[v][i] = max[v][i]>C?max[v][i]:C;
					if(leftmost[2*v][i]==-1) leftmost[v][i] = C;
				}
			}
		}
	}
	void set(int ind, char val, int l=1, int r=500000, int v=1)
	{
		if(l==r)
		{
			if(val=='<')
			{
				left[v][0] = 1, left[v][1] = 0;
				leftmost[v][0] = leftmost[v][1] = -1;
				right[v][0] = 0, right[v][1] = 1;
				rightmost[v][0] = rightmost[v][1] = -1;
				max[v][0] = max[v][1] = 0;
			}
			else
			{
				left[v][0] = 0, left[v][1] = 1;
				leftmost[v][0] = leftmost[v][1] = -1;
				right[v][0] = 1, right[v][1] = 0;
				rightmost[v][0] = rightmost[v][1] = -1;
				max[v][0] = max[v][1] = 0;
			}
			return;
		}
		else
		{
			int h = (l+r)/2;
			if(ind<=h) set(ind,val,l,h,2*v);
			else set(ind,val,h+1,r,2*v+1);
			update(v);
		}
	}
	
	str getQuery(int L, int R, int l=1, int r=500000, int v=1)
	{
		if(L<=l&&r<=R)
		{
			int k;
			k = left[v][0], left[v][0] = left[v][1], left[v][1] = k;
			k = leftmost[v][0], leftmost[v][0] = leftmost[v][1], leftmost[v][1] = k;
			k = right[v][0], right[v][0] = right[v][1], right[v][1] = k;
			k = rightmost[v][0], rightmost[v][0] = rightmost[v][1], rightmost[v][1] = k;
			k = max[v][0], max[v][0] = max[v][1], max[v][1] = k;
			//printf("%d %d : %d %d %d!!\n",l,r,max[v][0],left[v][0],right[v][0]);
			return {max[v][0],left[v][0],leftmost[v][0],right[v][0],rightmost[v][0]};
		}
		else if(R<l) return {0,0,-1,0,-1};
		else if(r<L) return {0,0,-1,0,-1};
		else
		{
			int h = (l+r)/2;
			str s1 = getQuery(L,R,l,h,2*v);
			str s2 = getQuery(L,R,h+1,r,2*v+1);
			update(v);
			str ans;
			
			ans.left = s1.left;
			ans.leftmost = s1.leftmost;
			ans.right = s2.right;
			ans.rightmost = s2.rightmost;
			ans.max = s1.max>s2.max?s1.max:s2.max;
			
			if(s1.right>0&&s2.left>0)
			{
				int C = s1.right + s2.left;
				ans.max = ans.max>C?ans.max:C;
				if(s1.leftmost==-1) ans.leftmost = C;
				if(s2.rightmost==-1) ans.rightmost = C;
			}
			else if(s1.right==0&&s2.left>0)
			{
				if(s2.rightmost==-1) ans.left += s2.left;
				else
				{
					int C = s2.rightmost+s2.left;
					ans.max = ans.max>C?ans.max:C;
					if(s2.rightmost==-1) ans.rightmost = C;
				}
			}
			else if(s1.right>0&&s2.left==0)
			{
				if(s2.leftmost==-1) ans.right += s1.right;
				else
				{
					int C = s2.leftmost+s1.right;
					ans.max = ans.max>C?ans.max:C;
					if(s1.leftmost==-1) ans.leftmost = C;
				}
			}
			
			printf("%d %d : %d %d %d!!\n",l,r,ans.max,ans.left,ans.right);
			
			return ans;
		}
	}
}T;

char x[500010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++) T.set(i,x[i]);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		str s = T.getQuery(c,d);
		printf("%d\n",MAX(s.max,s.left,s.right));
	}
}
