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
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	int o = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		o+=a[i];
	}
	for(int i=0;i<q;i++){
		int t,g;
		cin>>t>>g;
		if(t == 1){
			g--;
			if(a[g] == 0)o++;
			else o--;
			a[g] = !a[g];
		}else{
			if(g <= o)cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
}