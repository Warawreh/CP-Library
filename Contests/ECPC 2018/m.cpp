#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef int T;
typedef tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;


#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,m;
	cin>>n>>m;

	map<int,vector<vector<int>>> e;
	for(int i=0;i<n;i++){
		int x,q,r;
		cin>>x>>q>>r;
		e[x].push_back({1,q - x});
		e[x + r + 1].push_back({2 , q - x});

	}

	for(int i=0;i<m;i++){
		int y,d;
		cin>>y>>d;

		e[y].push_back({3 , d - y , i});
	}

	indexed_set s;
	vector<int> ans(m);
	for(auto it : e){
		for(vector<int> cur : it.second){
			if(cur[0] == 1){//insert
				s.insert(cur[1]);
			}else if(cur[0] == 2){
				s.erase(s.find_by_order(s.order_of_key(cur[1])));
			}else{
				int i = cur[2];
				ans[i] = s.size() - s.order_of_key(cur[1]);
			}
		}
	}

	for(int i=0;i<m;i++)
		cout << ans[i] << ' ';
	cout << '\n';
}

int main(){
	fast
	freopen("business.in","r",stdin);
	int t;
	cin>>t;
	while(t--)solve();	
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/