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
	int r,c;
	int x,y;
	cin>>r>>c>>x>>y;
	int D = abs(x - r) + abs(y - c);
	if(D == 0)cout << 0 << '\n';
	else if(D <= 3 || x + y == r + c || r - c == x - y){
		cout << 1 << '\n';
	}else{
		int a = abs(x - r);
		int b = abs(y - c);
		int d = min(a , b);
		// cerr << a << ' ' << b << '\n';
		int w = 1;
		if((a+b)%2 == 0 || abs(a-b) <= 3)w = 0;
		cout << 2 + w << '\n';
		// a-=d;
		// b-=d;
		// cout << 1 + (a + b + 2)/3 << '\n';
	}

}