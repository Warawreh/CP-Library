#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void NO(){
	cout << "No\n";
	exit(0);
}

ll get(ll l,ll r){
	if(l > r)swap(l,r);
	// cerr << " ____ \n";
	// cerr << l << ' ' << r << ' ';
	l--;
	// cerr << r*(r+1)/2 - l * (l+1)/2 << '\n';
	return r*(r+1)/2 - l * (l+1)/2;
}

int main(){
	fast
	ll T,n,m;
	cin>>T>>n>>m;
	vector<pair<ll,ll>> e(m);
	ll mx = 0,mn = 0;
	for(int i=0;i<m;i++){
		cin>>e[i].first>>e[i].second;
		mx -= e[i].second;
		mn -= e[i].second;
	}

	for(int i=0;i<e.size();i++){
		ll to = e[i].second;
		ll time = e[i].first - (i ? e[i-1].first : 1);
		ll st = (i ? e[i-1].second : to + time);
		if(abs(to - st) > time){
			NO();
		}

		ll lo=st,hi = 1e10,maxx=st;
		while(lo <= hi){
			ll md = (lo + hi)/2;
			ll tm = abs(st - md) + abs(md - to);
			if(tm <= time){
				lo = md+1;
				maxx = md;
			}else hi = md-1;
		}

		ll same = time - abs(maxx - st) - abs(maxx - to);
		// cerr << maxx << ' ' << same << ' ' << st << ' ' << to << '\n';
		mx += get(st , maxx) + maxx * same + get(maxx,to) - maxx ;
	}
	mx += get(e.back().second,e.back().second + (n - e.back().first));


	for(int i=0;i<e.size();i++){
		ll be = e[i].second;
		ll time = e[i].first - (i ? e[i-1].first : 1);
		ll st = (i ? e[i-1].second : max(0LL,be - time));
		if(abs(be - st) > time){
			NO();
		}

		ll lo=0,hi = st,minn=st;
		while(lo <= hi){
			ll md = (lo + hi)/2;
			ll tm = abs(st - md) + abs(md - be);
			if(tm <= time){
				hi = md-1;
				minn = md;
			}else{
				lo = md+1;
			}
		}

		ll same = time - abs(minn - st) - abs(minn - be);
		// cerr << st << ' ' << be << ' ' << minn << ' ' << same << '\n';
		// cerr << mn << '\n';
		mn += get(st , minn) + minn * same + get(minn,be) - minn;

		// cerr << mn << '\n';	
	}
	// cout << get(10,35) * 4 - 35 - 35 - 10 << '\n';
	ll time = n - e.back().first;
	ll st = e.back().second;
	ll be = e.back().second - time;
	be = max(be , 0LL);
	ll minn = be;
	ll same = time - abs(minn - st) - abs(minn - be);
	mn += get(st , minn) + minn * same + get(minn,be) - minn;
	// cerr << time << ' ' << same << '\n';
	// cerr << minn << ' ' << same << ' ' << st << ' ' << be << '\n';
	// cerr << get(st , minn) << ' ' << minn * same << ' ' << get(minn,be) << ' ' << minn << '\n';
	// cerr << mn << ' ' << mx << '\n';
	if(T <= mx && T >= mn)cout << "Yes\n";
	else cout << "No\n";
}