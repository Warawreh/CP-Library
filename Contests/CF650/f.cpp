#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void comp(vector<int> &a){
	map<int,int> mp;
	vector<int> b = a;
	sort(all(b));
	int cnt = 0;
	for(int i : b){
		if(!mp[i])
			mp[i] = ++cnt;
	}
	for(int &i : a){
		int t = i;
		i = mp[i];
	}
}

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	comp(a);
	vector<int> at(n+1);
	for(int i=0;i<n;i++){
		cerr << a[i] << ' ';
		at[a[i]] = i;
	}
	cerr << '\n';

	int ans = n;
	for(int i=1;i<=n;i++){	
		int lst = -1;
		int to = n+1;
		for(int j=i;j<=n;j++){
			if(at[j] < lst){
				to = j;
				break;
			}
			lst = at[j];
			ans = min(ans , i - 1 + n - j);
		}
		i = to -1 ;
	}

	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();	
}