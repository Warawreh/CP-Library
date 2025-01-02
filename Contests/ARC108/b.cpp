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
	string s,b;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		b += s[i];
		while(b.size() >= 3 && b.substr(b.size() - 3) == "fox"){
			b.pop_back();b.pop_back();b.pop_back();
		}
	}
	cout << b.size() << '\n';
}