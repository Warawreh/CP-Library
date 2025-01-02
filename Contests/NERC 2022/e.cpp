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
	int l,n;
	cin>>l>>n;
	vector<int> a(n+2);
	for(int i=1;i<=n;i++)cin>>a[i];
	a[0] = 0;
	a.back() = l;
	int mn,mx;
	{//find maximum smallest range
		int lo=1,hi=l;
		mn=a[1];
		while(lo <= hi){
			int md = (lo + hi)/2;
	
			bool can = true;
			int to = 0;
	
			for(int i=1;i<=n;i++){
				if(to > a[i]){
					can = false;
					break;
				}
				int nxt = to + md;
				to = max(nxt , a[i]);
			}
	
			if(can){
				lo = md+1;
				mn = md;
			}else hi = md-1;
		}
	}
	
	{//find minimum biggest range the fit the current mn
		int lo = mn,hi = l;
		mx = l;

		while(lo <= hi){
			int md = (lo + hi)/2;

			bool can = true;
			int extra = 0;
			int to = 0;

			for(int i=1;i<=n;i++){
				int nxt = max(a[i] , to + mn);
				int need = nxt - mn - to;
				extra += md - mn;


				if(need > extra){
					can = false;
					break;
				}
				extra -= need;
				extra = min(extra , a[i+1] - nxt);
				// cerr << i << ' ' << nxt << ' ' << to << ' ' << extra << '\n';
				to = nxt;

			}

			// cerr << md << ' ' << can << ' ' << to << ' ' << extra << '\n';
			if(to + extra < l)can = false;
			// return 0;
			if(can){
				hi = md-1;
				mx = md;
			}else lo = md+1;
		}

	}
	// cerr << mn << ' ' << mx << '\n';

	vector<int> fr(n+2),to(n+2);
	fr[0] = to[0] = 0;
	for(int i=1;i<=n;i++){
		fr[i] = max(a[i] , fr[i-1] + mn);
		to[i] = min(a[i+1] , to[i-1] + mx);
	}
	int at = l;
	vector<int> ans(n+2);
	ans[n] = l;
	for(int i=n-1;i>0;i--){
		ans[i] = min(ans[i+1] - mn , to[i]);
	}
	for(int i=1;i<=n;i++)
		cout << ans[i-1] << ' ' << ans[i] << '\n';

}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/