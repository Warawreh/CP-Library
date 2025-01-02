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
		int x;
		cin>>s>>x;
		int n = s.size();
		string res(n,'1');
		for(int i=0;i<n;i++){
			if(s[i] == '0'){
				if(i + x < n)res[i+x] = '0';
				if(i - x >= 0)res[i-x] = '0';
			}
		}
		string tmp(n,'0');
		for(int i=0;i<n;i++){
			bool a=0;
			if(i + x < n && res[i + x] == '1')a = 1;
			if(i - x >= 0 && res[i-x] == '1')a = 1;
			if(a)tmp[i] = '1';
		}
		if(tmp == s)cout << res << '\n';
		else cout << "-1\n";
	}
}