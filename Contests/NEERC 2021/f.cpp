#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ld S(ld a){return a*a;}

int main(){
    fast
    int n;
    ld P;
    cin>>n>>P;
    vector<ld> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<ld> pre(n) , pre2(n);
    for(int i=1;i<n;i++){
    	pre[i] = pre[i-1] + (a[i] - a[i-1]);
    	pre2[i] = pre2[i-1] + S(a[i] - a[i-1]);
    }	

    ll pos=0,neg=0;

    for(int i=0;i<n;i++){
    	for(int j=i+2;j<n;j++){
    		ld sz = (j - i + 1);
    		ld A = (a[j] - a[i]) / (ld)(sz - 1);
    		if((a[j] - a[i]) == 0)continue;
    		// cerr << i << ' ' << j << ' ' << A << ' ' << (a[j] - a[i]) << ' ' << sz << '\n';

    		ld D = S(A) * (sz - 1) + (pre2[j] - pre2[i]) - 2 * A * (pre[j] - pre[i]);
    		// D /= sz;
    		// D = sqrt(D);

    		// ld D2 = 0;
    		// for(int l=i+1;l<=j;l++){
    		// 	D2 += S(a[l] - a[l-1] - A);
    		// }
    		// assert(fabs(D2 - D) <= 1e-9);
    		// cerr << D << '\n';


    		if(D == 0){
    			if((a[j] - a[i]) < 0)neg++;
    			else if((a[j] - a[i]) > 0)pos++;
    			else assert(0);
    		}else{
	    		// cerr << A << ' ' << -A/D << ' ' << P << '\n';
	    		if((a[j] - a[i]) < 0){
	    			D /= (ld)(sz - 1);
		    		D = sqrt(D);
		    		// cerr << -A / D << ' ' << P << '\n';
	    			if(-A / D >= P)neg++;
	    		}else{
	    			// cerr << D << '\n';
	    			D /= (ld)(sz - 1);
		    		D = sqrt(D);
	    			// cerr << A / D << ' ' << P << '\n';
	    			if(A / D >= P)pos++;
	    			// if(S(a[j] - a[i]) / n / S(P) >= D)pos++;
	    		}
    		}
    	}
    }
    cout << pos << ' ' << neg << '\n';
}
