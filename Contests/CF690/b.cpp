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
		int n;
		string s;
		cin>>n>>s;
		bool good = false;
		for(int i=0;i<=4;i++){
			int j = 4-i;
			if(s.substr(0,i) + s.substr(n - j) == "2020"){
				good = true;
				break;
			}
		}
		cout << (good ? "Yes\n" : "No\n");
	}
}