#include<iostream>
#include<vector>
 
using namespace std;
 
void cyclecheck(vector<vector<int>>& E, vector<int>& cycle,
	vector<int>& check, int cur) {
	check[cur] = 2;
	for (auto next : E[cur]) {
		if (check[next] == 2) {
			cycle[next] = 1;
		}
		if (check[next] == 0) {
			cyclecheck(E, cycle, check, next);
		}
	}
	check[cur] = 1;
}
 
void r(vector<vector<int>>& E, vector<int>& cycle,
	vector<int>& check, int cur) {
 
	for (auto next : E[cur]) {
		int check_next = check[next];
		if (check[cur] == -1) {
			check[next] = -1;
		}
		else if (check[next] == 1 && check[cur] > 0) {
			check[next] = 2;
		}
		else if (check[next] == 0) {
			if (cycle[next]) check[next] = -1;
			else check[next] = check[cur];
		}
		if (check_next != check[next]) r(E, cycle, check, next);
	}
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> E(n);
 
		vector<int> cycle(n, 0);
		for (int i = 0; i < m; i++) {
			int t1, t2;
			cin >> t1 >> t2; t1--; t2--;
			if (t1 == t2) {
				cycle[t1] = 1;
				continue;
			}
			E[t1].push_back(t2);
		}
 
		vector<int> check(n, 0);
		cyclecheck(E, cycle, check, 0);
 
		check = vector<int>(n, 0);
		check[0] = (cycle[0] == 1) ? -1 : 1;
		r(E, cycle, check, 0);
		for (auto& Ci : check) cout << Ci << ' ';
		cout << '\n';
	}
}