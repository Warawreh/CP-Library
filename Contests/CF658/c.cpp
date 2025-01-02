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
		int n,x,y;
		cin>>n>>x>>y;
		vector<int> h(n+2);
		set<pair<int,int>> st;
		auto add = [&](int x){
			if(h[x]){
				auto it = st.find({h[x] , x});
				st.erase(it);
			}
			h[x]++;
			st.insert({h[x] , x});
		};

		auto rem = [&](int x){
			auto it = st.find({h[x] , x});
			st.erase(it);
			h[x]--;
			if(h[x])st.insert({h[x] , x});	
		};

		vector<int> ans(n);
		vector<vector<int>> at(n+2);
		set<int> have;
		for(int i=1;i<=n+1;i++)have.insert(i);
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			have.erase(x);
			at[x].push_back(i);
			add(x);
		}

		for(int i=0;i<x;i++){
			auto it = st.rbegin();
			int X = it->second;
			ans[at[X].back()] = X;
			at[X].pop_back();
			rem(X);
		}
		y-=x;
		vector<int> tmp;
		for(auto it : st){
			for(int i=0;i<it.first;i++)tmp.push_back(it.second);
		}
		reverse(all(tmp));
		bool good = 1;
		for(int i=0;i<tmp.size();i++){
			if(!y || st.empty())break;
			auto it = st.begin();
			int b = it->second;
			int x = tmp[i];
			if(x == b){
				it++;
				if(it != st.end())b = it->second;
			}
			if(x == b)continue;
			y--;
			ans[at[x].back()] = b;
			at[x].pop_back();
			rem(b);
		}
		if(y){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for(int i : ans){
			if(i == 0)i = *have.begin();
			cout << i << ' ';
		}
		cout << '\n';
	}	
}