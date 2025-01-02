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
	cin>>n;

	const int nax = 1001;
	vector<bitset<nax>> b(n);
	for(int i=1;i<=1000;i++){
		if(b[n-1][i-1] == 1)continue;

		b[0][i-1] = 1;
		for(int j=1;j<n;j++){
			b[j] |= (b[j-1] << i);
		}
	}

	bool win = 0;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(b[n-1][a-1] == 1){
			win = 1;
		}
	}
	cout << (win ? "Alice\n" : "Bob\n");
}

int main(){
    fast
    int t;
    cin>>t;
    while(t--){
    	solve();
    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/