#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 2e5;

vector<int> g[nax];

int main(){
	fast
	freopen("icpc/a3.in","r",stdin);
	freopen("icpc/a3.out","w",stdout);
	int mx = 0;

	{//Read input
		int u,v;
		while(cin >> u >> v){
			mx = max(mx , max(u,v));
		}
	}
	cerr << mx << '\n';

	//Solution
	int groubs = uniform_int_distribution<int>(1, 10)(rng);
	vector<vector<int>> com(groubs);
	for(int i=0;i<=mx;i++){
		int at = uniform_int_distribution<int>(1, groubs)(rng) - 1;
		com[at].push_back(i);
	}

	//Print


	for(vector<int> a : com){
		if(a.empty())continue;
		for(int i =0;i<a.size();i++){
			if(i)cout << ' ';
			cout << a[i];
		}
		cout << '\n';
	}
}