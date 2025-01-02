#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ask(int a,int b){
	cout << "M " << a + 1 << ' ' << b + 1 << endl;
	fflush(stdout);
	int r;
	cin>>r;
	return r-1;
}

int main(){
	fast
	int t,n;
	cin>>t>>n;
	for(int T=0;T<t;T++){
		for(int i=0;i<n - 1;i++){
			int at = ask(i,n-1);
			if(at != i){
				cout << "S " << i + 1 << ' ' << at + 1 << endl;
				fflush(stdout);
				int r;
				cin>>r;
				if(r != 1){
					while(1);
				}
			}
		}
		cout << "D " << endl;
		fflush(stdout);
		int r;
		cin>>r;
		if(r != 1){
			while(1);
		}
	}
}