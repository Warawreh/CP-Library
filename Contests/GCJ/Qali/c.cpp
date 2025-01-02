#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int solve(vector<int> a){
	int n = a.size();
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

vector<int> solve(){
	int n,k;
	cin>>n>>k;
	int mx = n*(n+1)/2 - 1;
	if(k > mx || k < n-1)return {};
	vector<int> a(n);
	k -= (n-1);
	iota(all(a) , 1);
	for(int i=n-2;i>=0;i--){
		int to = min(n-1 , i + k);
		k -= to - i;

		reverse(a.begin() + i , a.begin() + to + 1);
	}
	return a;
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		vector<int> res = solve();
		if(res.size() == 0)cout << "IMPOSSIBLE";
		else for(int i : res)cout << i << ' ';
		cout << '\n';
	}
}