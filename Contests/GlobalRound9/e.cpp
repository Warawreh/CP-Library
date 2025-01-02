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
	vector<int> a(n);
	vector<pair<int,int>> ans;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<i;j++){
			if(a[i] < a[j])ans.push_back({j,i});
		}
	}
	sort(all(ans) , [&] (pair<int,int> x,pair<int,int> b){
		if(x.first == b.first){
			if(a[x.second] == a[b.second])return x.second > b.second;
			return a[x.second] > a[b.second];
		}
		return x.first < b.first;
	});
	for(int i=0;i<ans.size();i++){
		swap(a[ans[i].first] , a[ans[i].second]);
	}
	for(int i=1;i<n;i++){
		if(a[i] < a[i-1]){
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << ans.size() << '\n';
	for(auto a : ans)cout << a.first + 1 << ' ' << a.second + 1 << '\n';
}