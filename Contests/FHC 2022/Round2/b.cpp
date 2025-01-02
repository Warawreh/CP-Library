#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const int nax = 1e6 + 5;

struct customr{
	ll a,b,x,y;

	void read(){
		cin>>a>>b>>x>>y;
	}
};

void solve(){
	int n,k;
	cin>>n>>k;

	vector<multiset<ll>> cont(nax),pass(n);
	vector<int> uniqu;
	vector<customr> c(n);
	for(int i=0;i<n;i++){
		c[i].read();
		uniqu.push_back(c[i].a);
		uniqu.push_back(c[i].b);
	}

	sort(all(uniqu));
	uniqu.resize(unique(all(uniqu)) - uniqu.begin());
	vector<pair<pair<ll,ll>,ll>> e;

	for(int i=0;i<n;i++){
		c[i].a = lower_bound(all(uniqu) , c[i].a) - uniqu.begin();
		c[i].b = lower_bound(all(uniqu) , c[i].b) - uniqu.begin();

		e.push_back({{c[i].x , -1} , i });
		e.push_back({{c[i].y , 1} , i });
	}	

	multiset<ll> ans;

	sort(all(e));
	for(auto cur : e){
		int i = cur.second;
		int at = cur.first.first;


		if(cur.first.second == -1){//get vales

			int fr = c[i].a;
			for(ll it : cont[fr]){
				ans.insert(-(-it + c[i].x));
				if(ans.size() > k)ans.erase(--(ans.end()));

				if(c[i].y >= c[i].x){
					pass[i].insert(-(-it + c[i].x - c[i].y));
					if(pass[i].size() > k)pass[i].erase(--(pass[i].end()));
				}else{
					cont[c[i].b].insert(-(-it + c[i].x - c[i].y));
					if(cont[c[i].b].size() > k)cont[c[i].b].erase(--(cont[c[i].b].end()));
				}
			}

		}else{

			for(ll it : pass[i]){
				cont[c[i].b].insert(it);
				if(cont[c[i].b].size() > k)cont[c[i].b].erase(--(cont[c[i].b].end()));
				
			}
			cont[c[i].b].insert(c[i].y);
			if(cont[c[i].b].size() > k)cont[c[i].b].erase(--(cont[c[i].b].end()));


		}

	}

	ll res = 0;
	for(ll it : ans){
		res += -it;
	}
	assert(ans.size() <= k);
	cout << res % mod << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}

/*
Case #1: 140
Case #2: 135
Case #3: 0
Case #4: 10
Case #5: 996694768

*/