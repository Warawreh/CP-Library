#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll SQRT(ll a){
	ll b = sqrt(a);
	while((b + 1) * (b + 1) < a)b++;
	while(b * b >= a)b--;
	return b + 1;
}

int main(){
    fast
    int t;
    cin>>t;
	ll n = 0;
    while(t--){
    	cin>>n;
    	// n++;

    	if(n == 2){
    		cout << "0 0 1 1 0 0 0 0 0\n";
    		continue;
    	}

    	ll want = SQRT(n);
    	bool fnd = 0;
    	for(int IT=0;IT<10;IT++){
    		ll need = want * want - n;
    		if(need % 3 == 0){
    			need /= 3;
    			// cerr << want * want << '\n';
    			cout << n - need << ' ' << need;
    			assert(want * want == (n-need) + need * 4);
    			for(int j=3;j<=9;j++)
    				cout << ' ' << 0;
    			cout << '\n';

    			fnd = 1;
    			break;

    		}

    		if(need >= 8 && (need - 8)% 3 == 0){
    			need -= 8;
    			need /= 3;
    			assert(n - need - 1 >= 0);
    			cout << n - need - 1 << ' ' << need << ' ' << 1;
    			// cerr << want*want << ' ' << (n-need-1) + need * 4 + 9 << '\n';
    			assert(want * want == (n-need-1) + need * 4 + 9);
    			for(int j=4;j<=9;j++)
    				cout << ' ' << 0;
    			cout << '\n';
    			fnd = 1;
    			break;
    		}


    		want++;
    	}

    	if(!fnd){
    		cout << -1 << '\n';
    	}
    }

}