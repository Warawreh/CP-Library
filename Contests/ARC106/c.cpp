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
	int n,m;
	cin>>n>>m;
	if(m < 0){
		cout << -1 << '\n';
	}else if(m == 0){
		for(int i=1;i<=n;i++){
			cout << i * 2 << ' ' << i*2+1 << '\n';
		}
	}else if(n - m <= 1){
		cout << -1 << '\n';
	}else{
		cout << 1 << ' ' << (int)1e9 << '\n';
		for(int i=1;i<=m;i++){
			cout << i * 2 << ' ' << i*2+1 << '\n';
		}
		int rest = n - m - 1;
		cout << (int)1e6 << ' ' << (int)2e6 << '\n';
		for(int i=1;i<rest;i++){
			cout << (int)1e6 + i << ' ' << (int)2e6+i << '\n';
		}
	}
}