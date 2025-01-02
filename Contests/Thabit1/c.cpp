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
	int n,k,m;
	cin>>n>>k>>m;
	vector<bool> h(2);
	int cur = 0;
	bool s = 0,e=  0;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		a%=2;
		b%=2;
		cur += a;
		cur %= 2;
		if(a != b){
			s = 1;
		}else{
			e = 1;
		}
	}
	k %= 2;
	if(s == 0){
		cout << 2 - (m == cur) << '\n';
	}else{
		if(k == 0){
			if(e == 0){
				cout << 2 - (m == cur) << '\n';
			}else{
				cout << 2 << '\n';
			}	
		}else if(k == 1){
			if(e == 0){
				cout << 2 - !(m == cur) << '\n';
			}else{
				cout << 1	 << '\n';
			}
		}
	}
}