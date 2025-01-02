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
		cin>>n;
		if(n <= 30)cout << "NO\n";
		else{
			cout << "YES\n";
			if(n == 36){
				cout << "5 6 10 15\n";
			}else if(n == 40){
				cout << "6 14 15 5\n";
			}else if(n == 44){
				cout << "6 10 15 13\n";
			}else{
				cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << n - 30 << '\n';
			}
		}
	}	
}