#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]--;
	}
	vector<pair<int,int>> p(k);
	for(int i=0;i<k;i++){
		cin>>p[i].first>>p[i].second;
		p[i].first--;
	}

	vector<int> l(k,0),f(n,0);
	int s=0,e=0;
	for(int i=0;i<k;i++){
		l[i] = s;

		while(e < n && f[p[i].first] < p[i].second){
			f[a[e]]++;
			e++;
		}
		if(f[p[i].first] != p[i].second){
			cout << "no\n";
			return;
		}

		while(s < e){
			f[a[s]]--;
			s++;
		}


	}

	{
		int s=n-1,e=n-1;
		for(int i=k-1;i>=0;i--){
			while(s >= l[i] && f[p[i].first] <= p[i].second ){
				if(a[s] == p[i].first && f[p[i].first] == p[i].second)break;
				f[a[s]]++;
				s--;
			}

			if(s == l[i] - 1){
				cout << "yes\n";
				return;
			}

			while(e > s){
				f[a[e]]--;
				e--;
			}
		}

	}
	cout << "no\n";

}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();	
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/