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
	ll n,v;
	cin>>n>>v;
	vector<vector<ll>> k(n+1,vector<ll>(3));
	k[0] = {0,0,0};
	for(int i=1;i<=n;i++)cin>>k[i][1];
	for(int i=1;i<=n;i++)cin>>k[i][0];
	for(int i=1;i<=n;i++)k[i][2] = i;
	
	sort(all(k),[v](vector<ll> a,vector<ll> b){	
		if(a[0] + a[1] * v == b[0] + b[1] * v)return a[2] < b[2];
		return a[0] + a[1] * v < b[0] + b[1] * v;
	});	
	
	
	multiset < ll > s;
    multiset < ll > :: iterator it;

    for(int i=0;i<=n;i++){
    	ll val = k[i][0] - k[i][1] * v;
    	val = -val;

        if(s.upper_bound(val) == s.begin() && abs(k[i][0]) - k[i][1] * v > 0){
        	continue;
        }

        s.insert(val);


        it = s.upper_bound(val);

        // it++;

        if(it != s.end())
            s.erase(it);
        // cerr << abs(k[i][0]) - k[i][1] * v << ' ' << s.size() << '\n';
    }

    cout << s.size()-1 << endl;

	
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/