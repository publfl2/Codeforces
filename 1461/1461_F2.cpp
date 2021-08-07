#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> a(n);
	bool two=true;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]<=1)two=false;
	}
	string s; cin >> s;
	bool mul=false;
	for(char c:s){
		if(c=='*')mul=true;
	}
	if(s.size()==1){
		for(int i=0;i<n;i++){
			if(i) cout << s;
			cout << a[i];
		}
		cout << endl;
		return 0;
	}
	if(two and mul){
		for(int i=0;i<n;i++){
			if(i) cout << "*";
			cout << a[i];
		}
		cout << endl;
		return 0;
	}
	if(!mul){
		for(int i=0;i<n;i++){
			if(i) cout << "+";
			cout << a[i];
		}
		cout << endl;
		return 0;
	}
	if(s.size()==3){
		s="+*";
	}
	mul=false; // add
	for(char c:s){
		if(c=='+')mul=true;
	}
	vector<char> res(n+1,'.');
	if(mul){
		for(int i=0;i<n;i++){
			if(a[i]==0){
				res[i]='+';
				res[i+1]='+';
			}
		}
		ll p=1; bool f=false;
		ll ad=0;
		a.push_back(0);
		int last=0;
		for(int i=0;i<=n;i++){
			if(a[i]==0){
				if(ad==0){
					p=1; f=false;
					last=i+1;
					continue;
				}
				if(f or ad<=p){
					for(int j=last;j<i;j++){
						if(j==last){
							res[j]='+';
						}
						else{
							res[j]='*';
						}
						if(j+1==i){
							res[j+1]='+';
						}
						else{
							res[j+1]='*';
						}
					}
				}
				else{
					for(int j=last;j<i;j++){
						res[j]='+';
						res[j+1]='+';
					}
				}
				last=i+1;
				p=1; ad=0;
				f=false;
			}
			else{
				if(f)continue;
				ad+=a[i];
				p*=a[i];
				if(p>1e9)f=true;
			}
		}
		for(int i=0;i<n;i++){
			if(i)cout << res[i];
			cout << a[i];
		}
		cout << endl;
	}
	else{
		bool zero=false;
		for(int i=0;i<n;i++){
			if(a[i]==0)zero=true;
		}
		if(!zero){
			for(int i=0;i<n;i++){
				if(i)cout << "*";
				cout << a[i];
			}
			cout << endl;
			return 0;
		}
		else{
			zero=false;
			for(int i=0;i<n;i++){
				if(a[i]!=0){
					res[i]='*';
					res[i+1]='*';
				}
				else{
					if(!zero){
						res[i]='-';
						res[i+1]='*';
						zero=true;
					}
					else{
						res[i]='*';
						res[i+1]='*';
					}
				}
			}
			for(int i=0;i<n;i++){
				if(i)cout << res[i];
				cout << a[i];
			}
			cout << endl;
		}
	}
}
