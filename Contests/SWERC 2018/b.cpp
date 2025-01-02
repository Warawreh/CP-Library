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
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    vector<int> fr(n),to(n);
    for(int i=0;i<n;i++){
    	cin>>a[i].first>>a[i].second;

    	// fr[i] = i-1;
    	// while(fr[i] >= 0 && a[i].first >= a[fr[i]].first && a[i].second <= a[fr[i]].second){
    	// 	fr[i] = fr[fr[i]];
    	// }
    }

    int lo=1,hi=n,ans = 1;
    while(lo <= hi){
    	int md = (lo + hi)/2;

    	int mx = 0;
    	multiset<int> l,r;
    	int at = 0;
    	for(int i=0;i<n;i++){
    		l.insert(a[i].first);
    		r.insert(a[i].second);


    		while(at <= i && *r.begin() - *l.rbegin() + 1 < md){
    			l.erase(l.find(a[at].first));
    			r.erase(r.find(a[at].second));
    			at++;
    		}
    		mx = max(mx , i - at + 1);
    	}
    	// cerr << md << ' ' << mx << '\n';

    	if(mx >= md){
    		lo = md+1;
    		ans = md;
    	}else hi = md-1;
    }

    // for(int i=n-1;i>=0;i--){
    // 	to[i] = i+1;
    // 	while(to[i] < n && a[i].first >= a[to[i]].first && a[i].second <= a[to[i]].second){
    // 		to[i] = to[to[i]];
    // 	}
    // }
    // int ans = 0;
    // for(int i=0;i<n;i++){
    // 	int len = to[i] - fr[i] - 1;
    // 	len  = min(len , (a[i].second - a[i].first + 1));
    // 	ans = max(ans , len);
    // }
    cout << ans << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/