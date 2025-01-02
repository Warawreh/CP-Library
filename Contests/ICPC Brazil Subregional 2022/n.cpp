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
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    int k,l;
	cin>>k>>l;

	ll ans = 0,sum = 0;
	multiset<ll> flip,res;
	for(int i=n-k;i<n;i++){
		sum += a[i];
		sum += b[i];
		flip.insert(b[i]);
		if(flip.size() > l){
			auto cur = flip.begin();
			sum -= *cur;
			res.insert(*cur);
			flip.erase(cur);
		}
	}

	ans = sum;
	for(int i=0;i<k;i++){

		{//remove n-k+i
			sum -= a[n-k+i];
			if(flip.find(b[n-k+i]) != flip.end()){
				sum -= b[n-k+i];
				flip.erase(flip.find(b[n-k+i]));
			}else{
				assert(res.find(b[n-k+i]) != res.end());
				res.erase(res.find(b[n-k+i]));
			}

			while(res.size() && flip.size() < l){
				ll cur = *res.rbegin();
				flip.insert(cur);
				res.erase(res.find(cur));
				sum += cur;
			}
		}

		{//add i
			sum += a[i];
			sum += b[i];
			flip.insert(b[i]);
			if(flip.size() > l){
				auto cur = flip.begin();
				sum -= *cur;
				res.insert(*cur);
				flip.erase(cur);
			}
		}
		ans = max(ans , sum);
	}
	cout << ans << '\n';
}
