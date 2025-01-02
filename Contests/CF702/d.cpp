#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> a,dp;

void go(int l,int r,int d){
	if(l > r){
		return;
	}
	int at = -1;
	for(int i=l;i<=r;i++){
		if(at == -1 || a[i] > a[at])at = i;
	}
	dp[at] = d;
	go(l , at-1, d + 1);
	go(at+1 , r, d + 1);
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		a = dp = vector<int>(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
			a[i]--;
		}
		go(0,n-1,0);
		for(int i : dp){
			cout << i << ' ';
		}
		cout << '\n';
	}
}