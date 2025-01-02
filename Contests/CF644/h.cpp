#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<string,bool> bad;

string inc(string a){
	for(int i=a.size()-1;i>=0;i--){
		if(a[i] == '1'){
			a[i] = '0';
		}else{
			a[i] = '1';
			break;
		}
	}
	return a;
}

string dec(string a){
	for(int i=a.size()-1;i>=0;i--){
		if(a[i] == '1'){
			a[i] = '0';
			break;
		}else{
			a[i] = '1';
		}
	}
	return a;
}

void solve(){
	int n,m;
	cin>>n>>m;
	string a(m,'1');
	a[0] = '0';
	int less=0,more=0;
	int have = 0;
	vector<string> s(n);
	bad.clear();
	for(int i=0;i<n;i++){
		cin>>s[i];
		if(s[i] > a)more++;
		else less++;
		bad[s[i]] = 1;
	}
	int dif = abs(more-less);
	while(bad[a])a = dec(a);
	// cerr << a << ' ' << dif << '\n';
	if(more > less){
		for(int i=0;i<dif;i++){
			if(have)a = dec(a);
			while(bad[a])a = dec(a);
			have = !have;
		}
	}else{
		for(int i=0;i<dif;i++){
			if(have == 0)a = inc(a);
			while(bad[a])a = inc(a);
			have = !have;
		}
	}
	cout << a << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}