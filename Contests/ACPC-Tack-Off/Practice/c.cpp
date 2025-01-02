#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	// fast
	freopen("hello.in","r",stdin);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		if(i)cout << '\n';
		int a,b;
		cin>>a>>b;
		cout << "sum = " << a+b;
	}
}