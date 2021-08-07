#include<stdio.h>
#define MAX 2000000
#define min(a,b) ((a)<(b) ? (a) : (b))

long long int N, B;

long long int count[MAX+1];
long long int countB[MAX+1];
long long int prime[MAX+1];
long long int cnt;

void test(){
	printf("%d\n", cnt);
	for(int i=0; i<cnt; i++) printf("prime : %lld\n", prime[i]);
	for(int i=0; i<cnt; i++) printf("%lld ", count[prime[i]]);
	printf("\n");
	for(int i=0; i<cnt; i++) printf("%lld ", countB[prime[i]]);
	printf("\n");
}

void found(long long int x){
	for(long long int i=2; i*i<=x; i++){
		if(x%i) continue;
		prime[cnt++] = i;
		while(x%i==0){
			countB[i]++;
			x/=i;
			if(x==0) return;
		}
	}
	if(x==1) return;
	prime[cnt++] = x;
	if(x>MAX) return;
	countB[x]++;
}

void update(long long int x){
	if(x==1) return;
	long long int temp = N;
	long long int cnt = 0;
	while(temp>1){
		cnt += temp/x;
		temp /= x;
	}
	count[x] = cnt;
}

long long int answer(long long int N, long long int B){
	long long int cnt = 0;
	while(N>1){
		cnt += N/B;
		N /= B;	
	}
	return cnt;
}

int main(void){
	scanf("%lld %lld", &N, &B);
	found(B);
	long long int ans = -1;
	if(prime[cnt-1] >= MAX){
		//printf("%d %d", cnt, prime[cnt-1]);
		ans = answer(N, prime[cnt-1]);
		cnt--;
	}
	for(int i=0; i<cnt; i++) update(prime[i]);
	for(int i=0; i<cnt; i++){
		int now = prime[i];
		if(ans == -1){
			ans = count[now] / countB[now];
			continue;
		}
		ans = min(ans, count[now] / countB[now]);
	}
//	test();
	printf("%lld", ans);
}
