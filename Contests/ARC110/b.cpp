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
	string t;
	cin>>n>>t;
	if(n == 1){
		if(t == "0"){
			cout << (ll)1e10 << '\n';
		}else{
			cout << (ll)2e10 << '\n';
		}
		return 0;
	}
	string s = "110";
	while(s.size() <= t.size()){
		s += s;	
	}
	s += s;
	s+=s;
	ll len = 3e10;
	int at = -1;
	for(int i=0;i<3;i++){
		if(s.substr(i,t.size()) == t){
			at = i + 1;
		}
	}
	if(at == -1){
		cout << 0 << '\n';
		return 0;
	}else{
		for(int i=at;i<at + 3;i++){
			// cerr << i << ' ' << t.size() << ' ' << s.substr(i,t.size()) << '\n';
			if(s.substr(i,t.size()) == t){
				len -= at;
				len -= t.size();
				len+=1;
				// cerr << len << ' ' << i << ' ' << at << '\n';
				cout << len / (i-at+1) + 1 << '\n';
				return 0;
			}
		}
		cout << 0 << '\n';
	}
}