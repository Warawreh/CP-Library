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
    int n,m,t;
    cin>>n>>m>>t;

    vector<vector<int>> g(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cin>>g[i][j];
	}
	int ans = 0;

	if(n == 1){
		vector<int> &a = g[0];
		multiset<int> vals;
		int l = 0;
		for(int r=0;r<m;r++){
			vals.insert(a[r]);
			while(vals.size() && *vals.rbegin() - *vals.begin() > t){
				vals.erase(vals.find(a[l]));
				l++;
			}
			ans = max(ans , r - l + 1);
		}

	}else {
    	
    	for(int i=0;i<n;i++){

    		for(int j=i;j<n;j++){

    			vector<int> mx(m , 0),mn(m , 2e9);
    			for(int l=0;l<m;l++){
    				for(int x=i;x<=j;x++){
				    	// cerr << i << ' ' << j << ' ' << l << ' ' << x << '\n';
    					mn[l] = min(mn[l] , g[x][l]);
    					mx[l] = max(mx[l] , g[x][l]);
    				}
    			}

    			for(int l=0;l<m;l++){
	    			int border = mx[l],mxval=mx[l],mnval = 2e9;
	    			if((m - l) * (j - i + 1) <= ans)break;
    				for(int r=l;r<m;r++){
	    				border = max({border , g[i][r] , g[j][r]});
	    				mxval = max(mxval , mx[r]);
	    				mnval = min(mnval , mn[r]);
    					if(mxval - mnval > t)break;



	    				if(max(border , mx[r]) >= mxval){
	    					ans = max(ans , (r - l + 1) * (j - i + 1));
	    				}
    				}

    			}

    		}

    	}

    }
	cout << ans << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/