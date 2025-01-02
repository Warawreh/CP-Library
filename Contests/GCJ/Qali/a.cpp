#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	int ans = 0;
	for(int i=0;i<n - 1;i++){
		int mn = i;
		for(int j=i;j<n;j++){
			if(a[j] < a[mn]){
				mn = j;
			}
		}
		ans += mn - i + 1;
		reverse(a.begin() + i ,a.begin() + mn + 1);
	}
	return ans;
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": " << solve() << '\n';
	}
}