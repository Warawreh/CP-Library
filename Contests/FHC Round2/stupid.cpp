#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
ld p;
vector<ld> ans;

void calc(vector<int> a,ld pro){
	if(p < 1e-10)return;
	if(a.size() == 2)return;
	for(int i : a){
		ans[i] += pro;
	}
	ll x = a.size();
	ld tot = x * (x - 1)/2;
	for(int i=0;i<a.size();i++){
		for(int j=i+1;j<a.size();j++){
			vector<int> tmp = a;
			tmp.erase(tmp.begin() + i);
			calc(tmp , pro * p / tot);
			// tmp = a;
			// tmp.erase(tmp.begin() + j);
			// calc(i + 1,tmp , pro * (1 - p) / tot);
		}
	}
}

int main(){
	cout << setprecision(8) << fixed;
	fast
	int t;
	cin>>t;
	while(t--){
		cin>>n>>p;
		vector<int> a(n);
		ans.resize(n,0);
		iota(all(a),0);
		calc(a,1);
		for(int i=0;i<n;i++)cout << ans[i] << '\n';
	}
}