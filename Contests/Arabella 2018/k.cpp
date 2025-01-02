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
		string a,b;
		cin>>a>>b;
		string val = "";
		for(int i=0;i<n;i++){
			if(a[i] != b[i]){
				val += b[i];
			}
		}
		if(val.size() == 0){
			cout << "YES\n";
		}else{
			int at = val.size() - 1;
			bool good = true;
			for(int i=0;i<n;i++){
				if(a[i] != b[i]){
					if(a[i] != val[at]){
						good = false;
						break;
					}
					at = (at + 1)%val.size();
				}
			}
			cout << (good ? "YES\n" : "NO\n");

		}
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/