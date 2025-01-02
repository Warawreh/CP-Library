#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void NO(){
	cout << "-1\n";
	exit(0);
}

int main(){
	fast
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	vector<vector<int>> ans;
	int at = n-1;
	set<pair<int,int>> on;
	for(int i=n;i>=0;i--){
		if(a[i] == 1){
			pair<int,int> p = {i,at};
			at--;
			on.insert(p);
			ans.push_back({p.first,p.second});
		}
	}

	vector<pair<int,int>> W(n);
	for(int i=n;i>=0;i--){
		if(a[i] == 2){
			auto it = on.lower_bound({i,-1});
			if(it == on.end()){
				NO();
			}
			pair<int,int> p = *it;
			on.erase(it);
			W[i] = {i,p.second};
			ans.push_back({i,p.second});
		}
	}

	for(int i=0;i<n;i++){
		if(a[i] == 2){
			on.insert({W[i].first,W[i].second});
		}
	}

	for(int i=n-1;i>=0;i--){
		if(a[i] == 3){
			auto it = on.lower_bound({i,-1});
			if(it == on.end()){
				NO();
			}
			pair<int,int> p = *it;
			on.erase(it);
			ans.push_back({i,at});
			on.insert({i,at});
			if(at < 0)NO();
			ans.push_back({p.first,at});
			at--;
		}
	}
	assert(ans.size() <= 2*n);
	cout << ans.size() << '\n';
	for(vector<int> x : ans){
		cout << x[1] + 1 << ' ' << x[0] + 1 << '\n';
	}
}