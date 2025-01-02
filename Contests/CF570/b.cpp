#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int mx(vector<int> a,int x){
	int dif = 0;
	for(int i : a){
		dif = max(dif , abs(x - i));
	}
	return dif;
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int ans = -1;
		for(int i=0;i<n;i++){
			if(mx(a , a[i] + k) <= k)ans = max(ans , a[i] + k);
		}
		cout << ans << '\n';
	}
}