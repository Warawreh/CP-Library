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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int cnt = 0;
		
		while(n%2 == 0){
			cnt++;
			n/=2;
		}
		if(cnt != 0){
			if(cnt % 2 == 0 || n != 1){
				cout << "Alice\n";
			}else{
				cout << "Bob\n";	
			}

		}else{
			cout << "Bob\n";
		}
	}
}


/*
1 2 3 4 5 6 7 8 9 10 12 13 14 15 16 17 18 19 20 21
L L L W L W L L L  W  W  L  W  L  W  L  
*/