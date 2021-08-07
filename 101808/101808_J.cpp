#include <stdio.h>

struct str{
	int left;
	int right;
	int dire;
	int loca;
	
}A,B;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d%d%d%d",&A.left,&A.right,&A.loca,&A.dire);
		scanf("%d%d%d%d",&B.left,&B.right,&B.loca,&B.dire);
		scanf("%d",&a);
		
		int count = 0;
		if(A.loca==A.left) A.dire = 1;
		if(A.loca==A.right) A.dire = 0;
		if(B.loca==B.left) B.dire = 1;
		if(B.loca==B.right) B.dire = 0;
		for(int i=1;i<=a;i++)
		{
			if(A.dire==0)
			{
				A.loca--;
				if(A.loca==A.left) A.dire = 1;
			}
			else
			{
				A.loca++;
				if(A.loca==A.right) A.dire = 0;
			}
			
			if(B.dire==0)
			{
				B.loca--;
				if(B.loca==B.left) B.dire = 1;
			}
			else
			{
				B.loca++;
				if(B.loca==B.right) B.dire = 0;
			}
			if(A.loca==B.loca) count++;
		}
		printf("%d\n",count);
	}
}
