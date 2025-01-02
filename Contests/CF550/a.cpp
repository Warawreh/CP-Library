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
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n = s.size();
		sort(all(s));
		bool can = true;
		for(int i=1;i<n;i++){
			if(s[i] - s[i-1] != 1){
				can = false;
			}
		}
		cout << (can ? "Yes\n" : "No\n");
	}
}