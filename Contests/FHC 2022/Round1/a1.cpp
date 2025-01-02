#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];

	if(a == b){
		if(k == 1)
			cout << "NO\n";
		else
			cout << "YES\n";
		return;
	}else{
		if(k == 0){
			cout << "NO\n";
			return;
		}
		int st = 0;
		for(int i=0;i<n;i++){
			if(b[i] == a[0]){
				st = i;
				break;
			}
		}

		for(int i=0;i<n;i++){
			if(a[i] != b[(i + st)%n]){
				cout << "NO\n";
				return;
			}
		}

		if(n > 2)
			cout << "YES\n";
		else{
			if(k % 2 == 1){
				cout << "YES\n";
			}else{
				cout << "NO\n";
			}
		}
	}
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		
		solve();
	}
}