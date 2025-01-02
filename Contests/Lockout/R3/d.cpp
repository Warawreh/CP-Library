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
	int n,m;
	cin>>n>>m;
	vector<int> p(n);
	iota(all(p),1);
	reverse(all(p));
	if(n % 2 == 0){
		vector<int> g(n);
		int at = 0;
		for(int i=n/2-1;i>=0;i--){
			g[i] = p[at + 1];
			g[n - i - 1] = p[at];
			at += 2;
		}
		m--;
		for(int i=0;i<n;i++){
			if((m >> i) & 1){
				swap(g[i] , g[n-i-1]);
			}
		}
		for(int i=0;i<n;i++)
			cout << g[i] << ' ';

	}else{
		vector<int> g(n);
		int at = 0;
		g[n/2] = p[at];
		at++;
		for(int i=n/2-1;i>=0;i--){
			g[i] = p[at];
			g[n - i - 1] = p[at + 1];
			at += 2;
		}
		m--;
		for(int i=0;i<n;i++){
			if((m >> i) & 1){
				swap(g[i] , g[n-i-1]);
			}
		}
		for(int i=0;i<n;i++)
			cout << g[i] << ' ';
	}
}