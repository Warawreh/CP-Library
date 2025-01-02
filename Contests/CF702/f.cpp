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
		map<int,int> f;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			f[a]++;
		}
		vector<int> t;
		int sum = 0,cnt = 0;
		for(auto it : f){
			t.push_back(it.second);
			sum += it.second;
			cnt++;
		}
		sort(all(t));
		int ans = n;
		int comp = 0;
		for(int i=0;i<t.size();i++){
			ans = min(ans , comp + sum - t[i] * cnt);
			cnt--;
			sum -= t[i];
			comp += t[i];
		}
		cout << ans << '\n';
	}
}