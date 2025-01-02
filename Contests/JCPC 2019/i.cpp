#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct interval{
	char c;
	int l,r;

	interval(){

	}

	void read(){
		cin>>c>>l>>r;
		l--;r--;
		return;
	}

	bool operator<(const interval &rhs){
		return l < rhs.l;
	}
};

int main(){
	fast
	int n,q;
	cin>>n>>q;
	vector<vector<interval>> g(n);
	for(int i=0;i<n;i++){
		int m;
		cin>>m;
		g[i].resize(m);
		for(int j=0;j<m;j++){
			g[i][j].read();
		}
		sort(all(g[i]));
	}

	while(q--){
		string s;
		cin>>s;
		vector<bool> good(26);
		for(int i=0;i<s.size();i++)good[s[i] - 'a'] = 1;

		ll ans = 0;
		ll oldSum = 0;
		ll newSum = 0;
		vector<pair<int,int>> lst,nxt;

		for(int i=0;i<n;i++){

			ll intersect = 0;
			int at = 0;
			for(int j=0;j<g[i].size();j++){
				interval &cur = g[i][j];
				if(!good[cur.c - 'a'])continue;
				newSum += cur.r - cur.l + 1;
				int l = cur.l;
				int r = cur.r;
				nxt.push_back({l,r});

				while(at < lst.size() && lst[at].second <= r){
					if(lst[at].second >= l){
						intersect += lst[at].second - max(l , lst[at].first) + 1;
					}
					at++;
				}

				if(at < lst.size() && lst[at].first <= r){
					intersect += r - max(l , lst[at].first) + 1;
				}
			}

			ans += oldSum - intersect;
			oldSum = newSum;
			newSum = 0;
			swap(lst, nxt);
			nxt.clear();


		}
		ans += oldSum;

		cout << ans << '\n';
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/