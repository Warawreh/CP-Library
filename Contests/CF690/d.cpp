#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	int sum = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum += a[i];
	}
	for(int i=n;i>=1;i--){
		bool can = true;
		if(sum % i != 0)continue;
		int to = sum / i;
		int hv = 0;
		for(int j=0;j<n;j++){
			if(hv > to){
				can = false;
				break;
			}
			hv += a[j];
			if(hv == to){
				hv = 0;
			}
		}
		if(hv > to)can = false;
		if(can){
			cout << n - i << '\n';
			break;
		}
	}
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();

}