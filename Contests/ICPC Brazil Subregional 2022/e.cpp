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
    map<int,int> hv;
    int ans = 0;
    for(int i=0;i<n;i++){
    	int a;
    	cin>>a;
    	if(hv[a+1]){
    		hv[a+1]--;
    	}else ans++;

    	hv[a]++;
    }
    cout << ans << '\n';
}
