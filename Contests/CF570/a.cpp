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
	int b;
	cin>>b;
	while(1){
		string a = to_string(b);
		int s=0;
		for(char c : a){
			s += c-'0';
		}
		s %= 4;
		if(s == 0)break;
		b++;
	}
	cout << b << '\n';
}