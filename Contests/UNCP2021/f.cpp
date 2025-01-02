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
    int n,q;
    cin>>n>>q;
    vector<int> r(n),c(n);
    int ans = 0;
    vector<string> s(n);

    for(int i=0;i<n;i++){
    	cin>>s[i];
    	for(int j=0;j<n;j++){
    		if(s[i][j] == '1'){
    			r[i]++;
    			c[j]++;

    			if(r[i] == n)ans++;
    			if(c[j] == n)ans++;
    		}
    	}
    }

    int add=0,at = 0;
    while(q--){
    	int t;
    	cin>>t;
    	if(t == 1){//update
    		int i,j,b;
    		cin>>i>>j>>b;
    		i--;j--;


    		j = (j - add + n)%n;


    		if(s[i][j] == '1'){
				if(r[i] == n)ans--;
				if(c[j] == n)ans--;
				r[i]--;
				c[j]--;
			}

			if(b == 1){
				r[i]++;
				c[j]++;
				if(r[i] == n)ans++;
				if(c[j] == n)ans++;
				s[i][j] = '1';
			}else s[i][j] = '0';

    	}else{//shift
    		int b;
    		cin>>b;

    		add++;
    		add %= n;
    		at--;
    		at+=n;
    		at %= n;

    		int j = at;
    		for(int i=0;i<n;i++){

    			if(s[i][j] == '1'){
    				if(r[i] == n)ans--;
    				if(c[j] == n)ans--;
    				r[i]--;
    				c[j]--;
    			}
    			int to = s[i][j] - '0';

    			if(b == 1){
    				r[i]++;
    				c[j]++;
    				if(r[i] == n)ans++;
    				if(c[j] == n)ans++;
	    			s[i][j] = '1';
				}else s[i][j] = '0';

    			b = to;
    		}
    	}

    	// for(int i=0;i<n;i++){
    	// 	cerr << s[i] << '\n';
    	// }
    	// cerr << '\n';

    	cout << ans << '\n';
    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/