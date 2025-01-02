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
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	vector<pair<int,int>> a(2*n);
	for(int i=0;i<2*n;i++){
		cin>>a[i].first;
		a[i].second = i + 1;
	}
	sort(all(a));
	vector<pair<int,int>> ans;
	for(int i=0;i<2*n;i+=2){
		if(a[i].first != a[i+1].first){
			cout << -1 << '\n';
			return 0;
		}
		ans.push_back({a[i].second , a[i+1].second});
	}
	for(auto a : ans){
		cout << a.first << ' ' << a.second << '\n';
	}
}