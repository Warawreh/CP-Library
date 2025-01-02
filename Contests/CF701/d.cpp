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
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int a;
			cin>>a;
			if((i+j)%2){
				cout << 720720 << ' ';
			}else{
				cout << 720720 + pow(a,4) << ' ';
			}
		}
		cout << '\n';
	}
}