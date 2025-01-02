#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n;
	ld p;
	cin>>n>>p;

	vector<ld> ans(n,0);
	vector<vector<ld>> trtr(n+1,vector<ld>(n,0));
	for(int i=0;i<n;i++)trtr[0][i] = 1;
	for(int r = 0;r < n - 1;r++){
		vector<ld> pre(n);
		for(int i=0;i<n;i++){
			pre[i] = trtr[r][i] + (i ? pre[i-1] : 0.0);
		}
		ld x = n-r;
		ld tot = x * (x-1) / 2;
		ld np = tot - x + 1;
		for(int i=0;i<n;i++){
			ld P=(i ? pre[i-1] : 0.0),suf=pre.back() - pre[i];

			ld pass = np + suf * (1-p) + P * p;
			// cerr << pass * trtr[r][i] << ' ' << tot << ' ' << np << '\n';
			trtr[r+1][i] = pass * trtr[r][i] / tot;
			// if(r == n-2)
			// 	cerr << i << ' ' << trtr[r][i] << ' ' << tot << ' ' << pre << ' ' << suf << '\n';
		}
		for(int i=0;i<n;i++){
			if(r)trtr[r][i] += trtr[r-1][i];
			cerr << trtr[r][i] << ' ';
		}
		// cerr << '\n';
		cerr << pre.back() << '\n';
	}
	for(int i=0;i<n;i++){
		ans[i] = trtr[n-2][i];
	}
	for(int i=0;i<n;i++){
		cout << ans[i] << '\n';
	}
}

int main(){
	fast
	cout << setprecision(8) << fixed;
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ":\n";
		solve();
	}
}

/*
	trtr = to_reach_this_round
	For each round find P_trtr : 
		let assume x is the # remaning player
		you don't play : 
			1 - (x-1)/tot
		play and win :
			let's assume I am playing some one weaker
				sum of P[j]_trtr * (1 - p) * 1 / tot
			else 
				sum of P[j]_trtr * p * 1 / tot
*/