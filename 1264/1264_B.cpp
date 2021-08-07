#include <stdio.h>
#include <vector>

int a,b,c,d;
int left,right;
std::vector<int> V1,V2,V3,V4;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a+b+c+d==1)
	{
		printf("YES\n");
		for(int i=0;i<a;i++) printf("0 ");
		for(int i=0;i<b;i++) printf("1 ");
		for(int i=0;i<c;i++) printf("2 ");
		for(int i=0;i<d;i++) printf("3 ");
		return 0;
	}
	
	if(a+b+c+d==2)
	{
		if(a==1&&b==1)
		{
			printf("YES\n");
			printf("0 1");
			return 0;
		}
		else if(b==1&&c==1)
		{
			printf("YES\n");
			printf("1 2");
			return 0;
		}
		else if(c==1&&d==1)
		{
			printf("YES\n");
			printf("2 3");
			return 0;
		}
		else printf("NO");
		return 0;
	}
	
	if(a+b+c+d==3)
	{
		if(a==2 && b==1)
		{
			printf("YES\n");
			printf("0 1 0");
			return 0;
		}
		if(c==1 && d==2)
		{
			printf("YES\n");
			printf("3 2 3");
			return 0;
		}
	}
	for(int L=0;L<=3;L++)
	{
		for(int R=0;R<=3;R++)
		{
			V1.clear();
			V2.clear();
			V3.clear();
			V4.clear();
			int a2 = a, b2 = b, c2 = c, d2 = d;
			if(L==0)
			{
				V1.push_back(0), V1.push_back(1);
				a2--, b2--, left = 1;
			}
			else if(L==1)
			{
				V1.push_back(1);
				b2--, left = 1;
			}
			else if(L==2)
			{
				V1.push_back(2);
				c2--, left = 2;
			}
			else if(L==3)
			{
				V1.push_back(3), V1.push_back(2);
				c2--, d2--, left = 2;
			}
			
			if(R==0)
			{
				V2.push_back(0), V2.push_back(1);
				a2--, b2--, right = 1;
			}
			else if(R==1)
			{
				V2.push_back(1);
				b2--, right = 1;
			}
			else if(R==2)
			{
				V2.push_back(2);
				c2--, right = 2;
			}
			else if(R==3)
			{
				V2.push_back(3), V2.push_back(2);
				c2--, d2--, right = 2;
			}
			if(a2<0 || b2<0 || c2<0 || d2<0) continue;
			
			if(left==1)
			{
				while(a2>0&&b2>0)
				{
					V3.push_back(0), V3.push_back(1);
					a2--,b2--;
				}
			}
			else
			{
				while(d2>0&&c2>0)
				{
					V3.push_back(3), V3.push_back(2);
					c2--,d2--;
				}
			}
			
			if(right==1)
			{
				while(a2>0&&b2>0)
				{
					V4.push_back(0), V4.push_back(1);
					a2--,b2--;
				}
			}
			else
			{
				while(d2>0&&c2>0)
				{
					V4.push_back(3), V4.push_back(2);
					c2--,d2--;
				}
			}
			
			if(a2>0)
			{
				if(left==1&&right==1&&c2==0&&d2==0&&a2==1)
				{
					printf("YES\n");
					for(int i=0;i<V1.size();i++) printf("%d ",V1[i]);
					for(int i=0;i<V3.size();i++) printf("%d ",V3[i]);
					printf("0 ");
					for(int i=V4.size()-1;i>=0;i--) printf("%d ",V4[i]);
					for(int i=V2.size()-1;i>=0;i--) printf("%d ",V2[i]);
					return 0;
				}
				else continue;
			}
			if(d2>0)
			{
				if(left==2&&right==2&&a2==0&&b2==0&&d2==1)
				{
					printf("YES\n");
					for(int i=0;i<V1.size();i++) printf("%d ",V1[i]);
					for(int i=0;i<V3.size();i++) printf("%d ",V3[i]);
					printf("3 ");
					for(int i=V4.size()-1;i>=0;i--) printf("%d ",V4[i]);
					for(int i=V2.size()-1;i>=0;i--) printf("%d ",V2[i]);
					return 0;
				}
				else continue;
			}
			
			if(left==1&&right==1)
			{
				if(c2==b2+1)
				{
					printf("YES\n");
					for(int i=0;i<V1.size();i++) printf("%d ",V1[i]);
					for(int i=0;i<V3.size();i++) printf("%d ",V3[i]);
					for(int i=1;i<=b2;i++) printf("2 1 ");
					printf("2 ");
					for(int i=V4.size()-1;i>=0;i--) printf("%d ",V4[i]);
					for(int i=V2.size()-1;i>=0;i--) printf("%d ",V2[i]);
					return 0;
				}
			}
			else if(left==2&&right==2)
			{
				if(b2==c2+1)
				{
					printf("YES\n");
					for(int i=0;i<V1.size();i++) printf("%d ",V1[i]);
					for(int i=0;i<V3.size();i++) printf("%d ",V3[i]);
					for(int i=1;i<=c2;i++) printf("1 2 ");
					printf("1 ");
					for(int i=V4.size()-1;i>=0;i--) printf("%d ",V4[i]);
					for(int i=V2.size()-1;i>=0;i--) printf("%d ",V2[i]);
					return 0;
				}
			}
			else if(left==1&&right==2)
			{
				if(b2==c2)
				{
					printf("YES\n");
					for(int i=0;i<V1.size();i++) printf("%d ",V1[i]);
					for(int i=0;i<V3.size();i++) printf("%d ",V3[i]);
					for(int i=1;i<=b2;i++) printf("2 1 ");
					for(int i=V4.size()-1;i>=0;i--) printf("%d ",V4[i]);
					for(int i=V2.size()-1;i>=0;i--) printf("%d ",V2[i]);
					return 0;
				}
			}
			else if(left==2&&right==1)
			{
				if(b2==c2)
				{
					printf("YES\n");
					for(int i=0;i<V1.size();i++) printf("%d ",V1[i]);
					for(int i=0;i<V3.size();i++) printf("%d ",V3[i]);
					for(int i=1;i<=b2;i++) printf("1 2 ");
					for(int i=V4.size()-1;i>=0;i--) printf("%d ",V4[i]);
					for(int i=V2.size()-1;i>=0;i--) printf("%d ",V2[i]);
					return 0;
				}
			}
		}
	}
	printf("NO");
}