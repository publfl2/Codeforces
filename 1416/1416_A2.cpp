#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int main() {
	int T;
	cin >> T;
 
	const int inf = 1e9;
 
	while (T--) {
		int n;
		cin >> n;
 
		vector<vector<int>> founds(n + 1);
 
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			founds[t].push_back(i);
		}
 
		vector<int> ans(n+2, inf);
 
		for (int i = n - 1; i > 0; i--) {
			founds[i].push_back(-1);
			founds[i].push_back(n);
			sort(founds[i].begin(), founds[i].end());
 
			int max_interval = 0;
			for (int j = 0; j < founds[i].size() - 1; j++) {
				if (founds[i][j + 1] - founds[i][j] > max_interval) {
					max_interval = founds[i][j + 1] - founds[i][j];
				}
				
			}
			ans[max_interval] = i;
		}
		int best_found = inf;
		for (int i = 1; i <= n; i++) {
			if (ans[i] < best_found) best_found = ans[i];
 
			cout << (best_found == inf ? -1 : best_found) << ' ';
		}
		cout << '\n';
 
 
	}
 
}
