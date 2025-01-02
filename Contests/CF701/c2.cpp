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
	int x,y;
	cin>>x>>y;
	int cnt = 0;
	for(int a=1;a<=x;a++){
		for(int b=1;b<=y;b++){
			if(a/b == a%b){
				cout << a << ' ' << b << '\n';
				cnt++;
			}
		}
		cerr << cnt << ',';
	}
}
// x^(n^2+2*n)/(1-x^n)