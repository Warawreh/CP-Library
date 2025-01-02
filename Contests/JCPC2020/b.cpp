#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1e5 + 10;
vector<pair<int,ll>> seg[4*nax];
vector<int> a;
int n,k;

void build(int n=1,int s=1,int e = ::n){
	if(s == e){
		seg[n].clear();
		seg[n].push_back({a[s-1],a[s-1]});
		return;
	}
	build(n+n,s,(s+e)/2);
	build(n+n+1,(s+e)/2+1,e);

	seg[n].clear();
	int a=0,b=0;
	while(a < seg[n+n].size() && b < seg[n+n+1].size()){
		if(a == seg[n+n].size()){
			seg[n].push_back({seg[n+n+1][b].first , seg[n+n+1][b].first + (seg[n].size() ? seg[n].back().second : 0LL)});
			b++;
		}else if(b == seg[n+n+1].size()){
			seg[n].push_back({seg[n+n][a].first , seg[n+n][a].first + (seg[n].size() ? seg[n].back().second : 0LL)});
			a++;
		}else if(seg[n+n][a].first < seg[n+n+1][b].first){
			seg[n].push_back({seg[n+n][a].first , seg[n+n][a].first + (seg[n].size() ? seg[n].back().second : 0LL)});
			a++;
		}else{
			seg[n].push_back({seg[n+n+1][b].first , seg[n+n+1][b].first + (seg[n].size() ? seg[n].back().second : 0LL)});
			b++;
		}
	}
}

int main(){
	fast
	#ifndef LOCAL
		freopen("task.in","r",stdin);
	#endif
	
}