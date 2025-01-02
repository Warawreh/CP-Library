#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0);
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fast
	int n,s;
	cin>>n>>s;
	int tmp = s;
	if(n*2 > s){
		cout << "No\n";
		return 0;
	}	
	cout << "Yes\n";
	for(int i=0;i<n-1;i++){
		cout << 1 << ' ';
	}
	cout << s - n + 1 << '\n';
	cout << s/2 << '\n';
}