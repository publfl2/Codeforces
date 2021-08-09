#include <stdio.h>
#include <map>
#define MAX 7000
int x[3][10010],y[3];
int a;
//std::map<int,int> M[2];
short M[2][MAX*MAX+1];
short func(int s, int t)
{
	// 1 : lose 2 : win 3 : loop
	if((s-1)%a==0) return M[t][s] = 1;
	if(s>2*a*a) return M[t][s] = 3;
	//if(M[t].find(s)!=M[t].end()) return M[t][s];
	if(M[t][s]!=0) return M[t][s];
	bool loop_check = false;
	for(int i=1;i<=y[t];i++)
	{
		short k =func(s+x[t][i],1-t);
		if(k==3) loop_check = true;
		if(k==1) return M[t][s] = 2;
	}
	if(loop_check) return M[t][s] = 3;
	else return M[t][s] = 1;
}
void F(short k)
{
	if(k==1) printf("Lose " );
	if(k==2) printf("Win ");
	if(k==3) printf("Loop ");
}
int main()
{
	scanf("%d",&a);
	
	scanf("%d",&y[0]);
	for(int i=1;i<=y[0];i++) scanf("%d",&x[0][i]);
	scanf("%d",&y[1]);
	for(int i=1;i<=y[1];i++) scanf("%d",&x[1][i]);
	
	for(int i=2;i<=a;i++) F(func(i,0));
	printf("\n");
	for(int i=2;i<=a;i++) F(func(i,1));
}
