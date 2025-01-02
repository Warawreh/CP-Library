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
	// freopen("file.in","r",stdin);	
	int n;
	cin>>n;
	ll best = 0;
	vector<vector<ll>> k(n);
	for(int i=0;i<n;i++){
		k[i].resize(3);
		cin>>k[i][0]>>k[i][1]>>k[i][2];
		if(k[i][1] * k[i][2] * k[best][0] > k[best][1] * k[best][2] * k[i][0])best = i;
	}
	cout << best + 1 << '\n';
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/