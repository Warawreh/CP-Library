#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;

int main(){
    fast
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    while(q--){
    	int t;
    	cin>>t;
    	if(t == 0){
    		int l,r,c;
    		cin>>l>>r>>c;
    		// l--;r--;
    		for(int i=l;i<=r;i++)a[i] = c;
    	}else if(t == 1){
    		int l,r,c;
    		cin>>l>>r>>c;
    		// l--;r--;
    		for(int i=l;i<=r;i++)a[i] = max(a[i] , c);
    	}else{
    		int l,r,c;
    		cin>>l>>r>>c;
    		// cerr << l << ' '  << r << '\n';
    		vector<int> dp(c+1);

    		dp[0] = 1;
    		for(int i=l;i<=r;i++){

    			for(int x=c-1;x>=0;x--){
    				dp[x + 1] = (dp[x + 1] + (dp[x] * 1LL * a[i])%mod)%mod;
    			}

    		}
    		// cerr << '\n';
    		cout << dp[c] << '\n';
    	}
    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/