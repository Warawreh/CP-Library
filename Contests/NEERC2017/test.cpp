#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
#define mk make_pair 
#define ff first 
#define ss second 
typedef long long ll;
ll ans=1e18;
void solve(ll n , ll k , ll days , ll s){
	if(s+k==n){
		ans=min(ans,days);
		return;
		}
	for(ll i=0;i<k;i++){
		solve(n,k-i,days+1,s+i+min(s+i,(n-s-i)/2));
		}
	return;
}

int main(){
	ll n ;
	ll k;
	cin>>n>>k;
	for(ll i=1;i<k;i++){
		solve(n,k-i,1,i);
		}
	cout<<ans;
	return 0;
}
