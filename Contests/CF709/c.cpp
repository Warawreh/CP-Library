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
	for(int i=1;i<=100000;i++){
		int a = __builtin_popcount(i);
		int b = __builtin_popcount(i+1);
		if(a%2 == b%2)cout << i << ',';
	}
}
