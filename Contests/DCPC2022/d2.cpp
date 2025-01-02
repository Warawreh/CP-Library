#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll cur = 0;
void solve(){
	string s;
	ll k,n;
	cin>>s>>n>>k;
	// s = "a";
	// n = 2;
	// k = ++cur;

	vector<int> x;

	while(n > 60){
		k--;
		if(k == 0){
			cout << s;
			for(int i=0;i<x.size();i++){
				cout << "-C0000";
			}
			cout << '\n';
		}
		x.push_back(0);
		n--;
	}
	while(n > 0){
		int cur = 0;
		k--;
		if(!k){
			cout << s;
			for(int i=0;i<x.size();i++){
				string cur = to_string(x[i]);
				while(cur.size() < 4)cur = "0" + cur;
				cout << "-C" << cur;
			}
			cout << '\n';
			return;
		}

		// cerr << k << ' ' << n << '\n';

		while(n > 0 && k > (1LL << (n-1))){
			cur++;
			k -= (1LL << n-1);
			n--;
		}
		n--;
		x.push_back(cur);
		assert(k > 0);
	}
	k--;
	assert(k == 0);

	cout << s;
	for(int i=0;i<x.size();i++){
		string cur = to_string(x[i]);
		while(cur.size() < 4)cur = "0" + cur;
		cout << "-C" << cur;
	}
	cout << '\n';
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