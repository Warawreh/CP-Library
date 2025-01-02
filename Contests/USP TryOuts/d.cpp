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
    	
    vector<ll> mod;
    for(int i=0;i<500;i++){
    	mod.push_back(uniform_int_distribution<ll>(1e9, 2e9)(rng));
    }

    int n,m;
    cin>>n>>m;
    vector<ll> a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    map<ll,bool> hv;
    for(int i=0;i<m;i++){
    	cin>>b[i];
    	hv[b[i]] = 1;
    }

    int cnt = 0;
    for(int T=0;T<mod.size();T++){
    	ll x=1,y=0;
    	ll d = 1;
    	for(int i=0;i<m;i++){
    		d = (d * (b[i]%mod[T])) % mod[T];
    	}
    	ll p=1;
    	for(int i=0;i<n;i++){
    		
	    	if(hv[a[i]]){
	    		p = (p * (a[i]%mod[T]))%mod[T];
	    	}else{
	    		if(y == 0){
	    			x = 1;
	    			y = (a[i]%mod[T]);
	    		}else{
		    		x = (x * (a[i]%mod[T]))%mod[T];
		    		x = (x + y)%mod[T];
		    		y = (y * (a[i]%mod[T]))%mod[T];
	    		}
	    	}
    	}

    	// cerr << p << ' ' << x << ' ' << d << ' ' << mod[T] << '\n';
    	p = (p * x)%mod[T];

    	if(p == d){
    		cnt++;
    	}

    }

    if(cnt == mod.size()){
    	cout << "S\n";
    }else cout << "N\n";
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/