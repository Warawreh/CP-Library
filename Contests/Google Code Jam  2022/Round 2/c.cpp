#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<pair<ll,ll>> s;
vector<pair<ll,ll>> c;
pair<ll,ll> bb;
const ll oo = 6e18;

ll S(ll a){
	return a*a;
}

ll dist(pair<ll,ll> a,pair<ll,ll> b){
	return S(a.first - b.first) + S(a.second - b.second);
}

bool cmp(pair<ll,ll> a,pair<ll,ll> b){
	return dist(a,bb) < dist(b,bb);
}	

const int nax = 11;
int dp[(1<<nax)][(1<<nax)];
int vis[(1<<nax)][(1<<nax)];
int n;	
int T;

int can(int i,int m,int m2){
	if(i == n){
		return 1;
	}
	int &ret = dp[m][m2];
	if(vis[m][m2] == T)return ret;
	vis[m][m2] = T;
	ret = 0;
	
	for(int j=0;j<n;j++){
		if((m >> j) & 1)continue;
		ll mn = oo;
		for(int j2=0;j2<n;j2++){
			if((m2 >> j2) & 1)continue;
			if(dist(s[j] , c[j2]) < mn){
				mn = dist(s[j] , c[j2]);
			}
		}
		// cerr << m << ' ' << m2 << '\n';
		// cerr << i << ' ' << j << ' '  << mn << ' ' << dist(s[j] , bb) << '\n';
		// cerr << s[j].first << ' ' << s[j].second << '\n';
		// cerr << '\n';
		if(mn > dist(s[j] , bb))continue;
		for(int j2=0;j2<n;j2++){
			if((m2 >> j2) & 1)continue;
			if(dist(s[j] , c[j2]) == mn){
				ret |= can(i + 1, m | (1<<j) , m2 | (1<<j2));
			}
		}
	}

	return ret;

}

void build(int i,int m,int m2){
	if(i == n){
		return;
	}

	for(int j=0;j<n;j++){
		if((m >> j) & 1)continue;
		ll mn = oo;
		for(int j2=0;j2<n;j2++){
			if((m2 >> j2) & 1)continue;
			if(dist(s[j] , c[j2]) < mn){
				mn = dist(s[j] , c[j2]);
			}
		}
		// cerr << m << ' ' << m2 << '\n';
		// cerr << i << ' ' << j << ' '  << mn << ' ' << dist(s[j] , bb) << '\n';
		// cerr << s[j].first << ' ' << s[j].second << '\n';
		// cerr << '\n';
		if(mn > dist(s[j] , bb))continue;
		for(int j2=0;j2<n;j2++){
			if((m2 >> j2) & 1)continue;
			if(dist(s[j] , c[j2]) == mn){
				if(can(i + 1, m | (1<<j) , m2 | (1<<j2))){
					cout << j + 1 << ' ' << j2 + 2 << '\n';
					build(i + 1, m | (1<<j) , m2 | (1<<j2));
					return;
				}
			}
		}
	}

}

void init(){
	c = s = vector<pair<ll,ll>>(n);
	// s = vector<pair<int,pair<ll,ll>>>(n);
}

void solve(){
	cin>>n;

	init();

	for(int i=0;i<n;i++){
		cin>>s[i].first>>s[i].second;
	}
	cin>>bb.first>>bb.second;
	for(int i=0;i<n;i++)cin>>c[i].first>>c[i].second;

	if(can(0,0,0) > 0){
		cout << "POSSIBLE\n";
		build(0,0,0);
	}else{
		cout << "IMPOSSIBLE\n";
	}
}

int main(){
	fast
	int t;
	cin>>t;
	for(T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}