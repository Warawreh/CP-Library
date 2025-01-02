#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fast
	int n;
	cin>>n;
	vector<int> a(n),at(n);
	vector<bool> u(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]--;
		at[a[i]] = i;	
	}
	vector<int> e;
	for(int i=n-1;i>=0;i--){
		while(at[i] != i){
			// swap at[i] , at[i+1]
			if(u[at[i]]){
				cout << -1 << '\n';
				return 0;
			}
			e.push_back(at[i]);
			u[at[i]] = 1;
			int v = a[at[i] + 1];
			swap(at[i] , at[v]);
			swap(a[at[i]] , a[at[v]]);
		}
	}
	if(e.size() != n-1){
		cout << -1 << '\n';
		return 0;
	}
	for(int i : e){
		cout << i + 1 << '\n';
	}
}