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
	map<string,ll> mp;
	for(int i=0;i<n;i++){
		ll a;
		string s;
		cin>>a>>s;
		sort(all(s));
		if(mp[s] == 0)mp[s] = a;
		mp[s] = min(mp[s] , a);
	}
	if(mp["AB"] == 0)mp["AB"] = 1e9;
	if(mp["AC"] == 0)mp["AC"] = 1e9;
	if(mp["BC"] == 0)mp["BC"] = 1e9;
	if(mp["A"] == 0)mp["A"] = 1e9;
	if(mp["B"] == 0)mp["B"] = 1e9;
	if(mp["C"] == 0)mp["C"] = 1e9;
	if(mp["ABC"] == 0)mp["ABC"] = 1e9;
	mp["AB"] = min(mp["AB"] , mp["A"] + mp["B"]);
	mp["AC"] = min(mp["AC"] , mp["A"] + mp["C"]);
	mp["BC"] = min(mp["BC"] , mp["C"] + mp["B"]);
	mp["ABC"] = min(mp["ABC"] , mp["AB"] + mp["C"]);
	mp["ABC"] = min(mp["ABC"] , mp["AC"] + mp["B"]);
	mp["ABC"] = min(mp["ABC"] , mp["BC"] + mp["A"]);
	mp["ABC"] = min(mp["ABC"] , mp["C"] + mp["B"] + mp["A"]);
	if(mp["ABC"] == 1e9)mp["ABC"] = -1;
	cout << mp["ABC"];
}