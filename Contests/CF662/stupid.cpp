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
	string s;
	vector<string> g;
	while(cin>>s){
		g.push_back(s);
	}	
	sort(all(g));
	for(string a : g)cout << a << '\n';
}