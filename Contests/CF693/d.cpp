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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)cin>>a[i];
		sort(all(a));
		int t = 0;
		vector<ll> s(2);
		for(int i=n-1;i>=0;i--){
			if(a[i] % 2 == t){
				s[t]+=a[i];
			}
			t = !t;
		}
		if(s[0] == s[1])cout << "Tie\n";
		else if(s[0] > s[1])cout << "Alice\n";
		else cout << "Bob\n";
	}
}