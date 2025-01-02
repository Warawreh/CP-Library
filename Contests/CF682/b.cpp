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
	int _;
	cin>>_;
	while(_--){
		int n;
		cin>>n;
		map<int,int> mp;
		bool good = false;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(mp[x])good = true;
			mp[x] = 1;
		}
		cout << (good ? "Yes\n" : "No\n");
	}	
}