#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string int2bin(int x,int len){
	string res(len , '.');
	int at = len - 1;
	while(x){
		if(x % 2 == 1)res[at] = '-';
		x /= 2;
		at--;
	}
	return res;
}

void solve(){
	int n;
	string s;
	cin>>n>>s;
	
	cout << '\n';
	int add = 0;
	for(int i=0;i<n-1;i++){
		string cur = int2bin(i + add,10);
		int len = min(s.size() , cur.size());
		if(cur.substr(0,len) == s.substr(0,len)){
			add++;
			i--;
			continue;
		}
		cout << cur << '\n';
		cur.clear();
	}
}

int T;
int main(){
	fast
	int t;
	cin>>t;
	for(T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}