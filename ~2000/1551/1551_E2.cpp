#include<iostream>
#include<vector>
#include <stdio.h>
 
using namespace std;
 
int main() {
	int T;
	cin >> T;
 
	while (T--) {
		int n, k;
		cin >> n >> k;
 
		vector<int> A(n);
		for (auto& a : A) {
			cin >> a; a--;
		}
 
		const int inf = 999999;
		vector<int> L(n, -inf);
		int ans = inf;
		for (int i = 0; i < n; i++) {
			printf("%d : %d!!\n",i,A[i]);
			if (A[i] <= i) L[i] = 1;
			else continue;
			for (int j = 0; j < i; j++) {
				if (A[i] > A[j] && A[i] - A[j] <= (i - j)) {
					L[i] = max(L[i], L[j] + 1);
				}
			}
			if (L[i] >= k) {
				ans = min(ans,i - A[i]);
				break;
			}
		}
		for(int i=0;i<n;i++) cout<<L[i];
		if (ans == inf) ans = -1;
		cout << ans << '\n';
 
	}
}