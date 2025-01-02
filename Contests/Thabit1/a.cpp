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
	bool a=0,b=0;
	int ans = 0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x == 0)a = 1;
		else b = 1;
		if(a && b){
			ans++;
			a = b = 0;
		}
	}
	cout << ans << '\n';
}